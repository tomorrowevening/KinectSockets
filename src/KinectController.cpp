//
//  KinectController.cpp
//  KinectSockets
//
//  Created by Colin Duffy on 6/10/24.
//

#include "KinectController.h"

#pragma mark - Public

KinectController::~KinectController() {
    poses.clear();
#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
    kinectDevice.close();
#endif
}

void KinectController::setup() {
    printf("KinectController::setup\n");
    string filePath = "json/kinect.json";
    ofFile file(filePath);
    if (file.exists()) {
        file >> data;
        printf("> JSON Loaded\n");
        setupConfig();
        setupPoses();
        setupDevice();
    } else {
        printf("> Couldn't find kinect JSON: %s\n", filePath.c_str());
    }
}

void KinectController::setupConfig() {
    _maxUsers = data["settings"]["maxUsers"];
    _trackBodies = data["settings"]["trackBodies"];
    printf("> Max Users: %i, Tracking: %s\n", _maxUsers, _trackBodies ? "true" : "false");
}

void KinectController::setupPoses() {
    int totalPoses = data["poses"].size();
    printf("> Total Poses: %i\n", totalPoses);
    for (int i = 0; i < totalPoses; i++) {
        KinectPose pose;
        pose.name = data["poses"][i]["name"];
        poses.push_back(pose);
        printf(">>> Pose: %s\n", pose.name.c_str());
    }
}

void KinectController::setupDevice() {
#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
    if (kinectDevice.open()) {
        auto deviceSettings = ofxAzureKinect::DeviceSettings();
        deviceSettings.syncImages = false;
        deviceSettings.depthMode = K4A_DEPTH_MODE_NFOV_UNBINNED;
        deviceSettings.updateIr = false;
        deviceSettings.updateColor = true;
        deviceSettings.colorResolution = K4A_COLOR_RESOLUTION_720P;
        deviceSettings.updateWorld = true;
        deviceSettings.updateVbo = false;
        kinectDevice.startCameras(deviceSettings);
        
        if (_trackBodies) {
            auto bodyTrackerSettings = ofxAzureKinect::BodyTrackerSettings();
            bodyTrackerSettings.sensorOrientation = K4ABT_SENSOR_ORIENTATION_DEFAULT;
            //bodyTrackerSettings.processingMode = K4ABT_TRACKER_PROCESSING_MODE_CPU;
            bodyTrackerSettings.imageType = K4A_CALIBRATION_TYPE_COLOR;
            bodyTrackerSettings.updateBodiesImage = true;
            kinectDevice.startBodyTracker(bodyTrackerSettings);
        }
    }
#endif
}

void KinectController::update(float deltaTime) {
#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
    _connected = kinectDevice.isStreaming();
    if (_connected) {
        const auto& skeletons = kinectDevice.getBodySkeletons();
        
        // Check for change in users
        int totalSkeletons = skeletons.size();
        if (totalSkeletons != _totalUsers) {
            Event evt;
            evt.type = totalSkeletons > _totalUsers ? KinectEvents::USER_JOINED : KinectEvents::USER_LEFT;
            dispatchEvent(evt);
        }
        _totalUsers = totalSkeletons;
        
        // Check for Pose Detection
        if (_trackBodies) {
            for (int i = 0; i < totalSkeletons; i++) {
                updatePoseDetection(skeletons[i]);
            }
        }
    }
#endif
}

void KinectController::draw() {
    string outputMsg = "Kinect Controller\n";
    
#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
    if (_connected) {
        // Draw the body index texture.
        // The pixels are not black, their color equals the body ID which is just a low number.
        kinectDevice.getBodyIndexTex().draw(0, 0);

        // Draw the projected joints onto the image.
        const auto& skeletons = kinectDevice.getBodySkeletons();
        for (int i = 0; i < skeletons.size(); ++i) {
            for (int j = 0; j < K4ABT_JOINT_COUNT; ++j) {
                switch (skeletons[i].joints[j].confidenceLevel) {
                case K4ABT_JOINT_CONFIDENCE_MEDIUM:
                    ofSetColor(ofColor::green);
                    break;
                case K4ABT_JOINT_CONFIDENCE_LOW:
                    ofSetColor(ofColor::yellow);
                    break;
                case K4ABT_JOINT_CONFIDENCE_NONE:
                default:
                    ofSetColor(ofColor::red);
                    break;
                }
                ofDrawCircle(skeletons[i].joints[j].projPos, 5.0f);
            }
        }
    }
#else
    outputMsg += "- Windows/Linux Required\n";
#endif
    
    if (_connected) {
        outputMsg += "- Connected\n";
    } else {
        outputMsg += "- Not Connected\n";
    }
    outputMsg += "- Total Users: " + ofToString(_totalUsers) + " / " + ofToString(_maxUsers) + "\n";
    int totalPoses = data["poses"].size();
    outputMsg += "- Total Poses: " + ofToString(totalPoses)  + "\n";
    ofSetColor(255);
    ofDrawBitmapString(outputMsg, 25, 25);
    
}

bool KinectController::checkSkeletonForPose(BodySkeleton skeleton, KinectPose pose) {
    float totalDistance = 0.0f;
    for (int i = 0; i < K4ABT_JOINT_COUNT; i++) {
        BodyJoint skeletonJoint = skeleton.joints[i];
        BodyJoint poseJoint = pose.skeleton.joints[i];
        float orientationDistance = distance(
             skeletonJoint.orientation.x,
             skeletonJoint.orientation.y,
             skeletonJoint.orientation.z,
             skeletonJoint.orientation.w,
             poseJoint.orientation.x,
             poseJoint.orientation.y,
             poseJoint.orientation.z,
             poseJoint.orientation.w
         );
        totalDistance += orientationDistance;
    }
    return totalDistance < maxPoseDistance * 32.0f;
}

#pragma mark - Protected

void KinectController::updatePoseDetection(BodySkeleton skeleton) {
    int totalPoses = (int)poses.size();
    for (int i = 0; i < totalPoses; i++) {
        KinectPose pose = poses[i];
        bool detected = checkSkeletonForPose(skeleton, pose);
        if (detected) {
            if (!pose.detected) {
                KinectEvent evt;
                evt.type = KinectEvent::POSE_DETECTED;
                evt.pose = &pose;
                dispatchEvent(evt);
            }
        } else if (pose.detected) {
            KinectEvent evt;
            evt.type = KinectEvent::POSE_LOST;
            evt.pose = &pose;
            dispatchEvent(evt);
        }
        pose.detected = detected;
    }
}
