//
//  KinectController.h
//  KinectSockets
//
//  Created by Colin Duffy on 6/10/24.
//

#ifndef KinectController_h
#define KinectController_h

#include "ofMain.h"
#include "Apollo.h"

#ifdef APOLLO_KINECT
#include "ofxAzureKinect.h"
#endif

#pragma mark - Models

class KinectEvents {
public:
    static const string USER_JOINED;
    static const string USER_LEFT;
    static const string POSE_DETECTED;
};

#pragma mark - Controlller

class KinectController : public EventDispatcher {
public:
    
    ~KinectController();
    void setup();
    void update(float deltaTime);
    void draw();
    
    // Getters
    
    bool connected() const {
        return _connected;
    }
    
    int totalUsers() const {
        return _totalUsers;
    }
    
protected:
    
    ofJson data;
    bool _connected;
    int maxUsers;
    int _totalUsers;
    
#ifdef APOLLO_KINECT
    ofxAzureKinect::Device kinectDevice;
#endif
    
    void updatePoseDetection();
};

#endif /* KinectController_h */
