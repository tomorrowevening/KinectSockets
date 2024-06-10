#pragma once

#include "ofMain.h"
#include "Apollo.h"
#include "KinectController.h"

class ofApp : public ofBaseApp, public EventHandler {
public:
    
    OFDispatcher dispatcher;
    KinectController kinectController;
    
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;
    
    void evtHandler(Event *event) override;
};
