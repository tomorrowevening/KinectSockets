#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColorHex(0x333333);
    ofSetFrameRate(60);
    
#if defined(APOLLO_MSW)
    printf("App::Windows\n");
#elif defined(APOLLO_LINUX)
    printf("App::Linux\n");
#elif defined(APOLLO_MAC)
    printf("App::Mac\n");
#endif
    
    kinectController.setup();
    kinectController.addListener(KinectEvent::USER_JOINED, this);
    kinectController.addListener(KinectEvent::USER_LEFT, this);
    kinectController.addListener(KinectEvent::POSE_DETECTED, this);
    kinectController.addListener(KinectEvent::POSE_LOST, this);
    
    gui.setup();
    gui.setPosition(ofGetWidth() - 220, 20);
    gui.add(maxPoseDistance.setup("Max Pose Distance", kinectController.maxPoseDistance, 0.0f, 45.0f));
}

//--------------------------------------------------------------
void ofApp::update() {
    Motion.update();
    kinectController.maxPoseDistance = maxPoseDistance;
    kinectController.update(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void ofApp::draw() {
    kinectController.draw();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {
    kinectController.removeListener(KinectEvent::USER_JOINED, this);
    kinectController.removeListener(KinectEvent::USER_LEFT, this);
    kinectController.removeListener(KinectEvent::POSE_DETECTED, this);
    kinectController.removeListener(KinectEvent::POSE_LOST, this);
    Motion.removeAllTweens();
}

//--------------------------------------------------------------
void ofApp::evtHandler(Event *event) {
    const string eType = event->type;
    printf("Event: %s\n", eType.c_str());
    if (eType == KinectEvent::USER_LEFT) {
        printf(">> User Left!\n");
    } else if (eType == KinectEvent::USER_JOINED) {
        printf(">> User Joined!\n");
    } else if (eType == KinectEvent::POSE_DETECTED) {
        KinectPose *pose = (KinectPose*)event;
        printf(">> Pose detected!: %s\n", pose->name.c_str());
    } else if (eType == KinectEvent::POSE_LOST) {
        KinectPose *pose = (KinectPose*)event;
        printf(">> Pose lost!: %s\n", pose->name.c_str());
    }
}
