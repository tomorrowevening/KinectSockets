//
//  KinectController.cpp
//  KinectSockets
//
//  Created by Colin Duffy on 6/10/24.
//

#include "KinectController.h"

#pragma mark - Model

const string KinectEvents::USER_JOINED = "KinectEvents::USER_JOINED";
const string KinectEvents::USER_LEFT = "KinectEvents::USER_LEFT";
const string KinectEvents::POSE_DETECTED = "KinectEvents::POSE_DETECTED";

#pragma mark - Public

KinectController::~KinectController() {
#ifdef APOLLO_KINECT
    kinectDevice.close();
#endif
}

void KinectController::setup() {
    printf("KinectController::setup\n");
#ifndef APOLLO_KINECT
    printf("> Kinect not found.\n");
#endif
    string filePath = "json/kinect.json";
    ofFile file(filePath);
    if (file.exists()) {
        file >> data;
        printf("> JSON Loaded\n");
        maxUsers = data["settings"]["maxUsers"];
        bool trackBodies = data["settings"]["trackBodies"];
        printf("> Max Users: %i, Tracking: %s\n", maxUsers, trackBodies ? "true" : "false");
        
#ifdef APOLLO_KINECT
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
            
            if (trackBodies) {
                auto bodyTrackerSettings = ofxAzureKinect::BodyTrackerSettings();
                bodyTrackerSettings.sensorOrientation = K4ABT_SENSOR_ORIENTATION_DEFAULT;
                //bodyTrackerSettings.processingMode = K4ABT_TRACKER_PROCESSING_MODE_CPU;
                bodyTrackerSettings.imageType = K4A_CALIBRATION_TYPE_COLOR;
                bodyTrackerSettings.updateBodiesImage = true;
                kinectDevice.startBodyTracker(bodyTrackerSettings);
            }
        }
#endif
    } else {
        printf("> Couldn't find kinect JSON: %s\n", filePath.c_str());
    }
}

void KinectController::update(float deltaTime) {
#ifdef APOLLO_KINECT
    _connected = kinectDevice.isStreaming();
    if (_connected) {
        const auto& skeletons = kinectDevice.getBodySkeletons();
        int totalSkeletons = skeletons.size();
        if (totalSkeletons != _totalUsers) {
            Event evt;
            if (totalSkeletons > _totalUsers) {
                evt.type = KinectEvents::USER_JOINED;
            } else {
                evt.type = KinectEvents::USER_LEFT;
            }
            dispatchEvent(evt);
        }
        _totalUsers = totalSkeletons;
    }
#endif
}

void KinectController::draw() {
#ifdef APOLLO_KINECT
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
#endif
    
    string outputMsg = "Kinect Controller\n";
    if (_connected) {
        outputMsg += "- Connected\n";
    } else {
        outputMsg += "- Not Connected\n";
    }
    outputMsg += "- Total Users: " + ofToString(_totalUsers) + " / " + ofToString(maxUsers) + "\n";
    ofSetColor(255);
    ofDrawBitmapString(outputMsg, 25, 25);
    
}

#pragma mark - Protected

void KinectController::updatePoseDetection() {
#ifdef APOLLO_KINECT
#endif
}
