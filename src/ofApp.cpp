#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundColorHex(0x333333);
    ofSetFrameRate(60);
    
#ifdef APOLLO_MSW
    printf("App::Windows\n");
#endif
    
#ifdef APOLLO_LINUX
    printf("App::Linux\n");
#endif
    
#ifdef APOLLO_MAC
    printf("App::Mac\n");
#endif
    
    kinectController.setup();
    kinectController.addListener(KinectEvents::USER_JOINED, this);
    kinectController.addListener(KinectEvents::USER_LEFT, this);
    kinectController.addListener(KinectEvents::POSE_DETECTED, this);
}

//--------------------------------------------------------------
void ofApp::update() {
    Motion.update();
    kinectController.update(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void ofApp::draw() {
    kinectController.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {
    kinectController.removeListener(KinectEvents::USER_JOINED, this);
    kinectController.removeListener(KinectEvents::USER_LEFT, this);
    kinectController.removeListener(KinectEvents::POSE_DETECTED, this);
    Motion.removeAllTweens();
}

//--------------------------------------------------------------
void ofApp::evtHandler(Event *event) {
    const string eType = event->type;
    printf("Event: %s\n", eType.c_str());
    if (eType == KinectEvents::USER_LEFT) {
        printf(">> User Left!\n");
    } else if (eType == KinectEvents::USER_JOINED) {
        printf(">> User Joined!\n");
    } else if (eType == KinectEvents::POSE_DETECTED) {
        printf(">> Pose Detected!\n");
    }
}
