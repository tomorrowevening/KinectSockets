//
//  KinectController.h
//  KinectSockets
//
//  Created by Colin Duffy on 6/10/24.
//

#ifndef KinectController_h
#define KinectController_h

#include "ofMain.h"
#include "KinectTypes.h"

class KinectController : public EventDispatcher {
public:
    
    vector<KinectPose> poses;
    float maxPoseDistance = 10.0f;
    
    ~KinectController();
    void setup();
    void update(float deltaTime);
    void draw();
    
    // Utils
    
    bool checkSkeletonForPose(BodySkeleton skeleton, KinectPose pose);
    
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
    bool _trackBodies;
    int _maxUsers;
    int _totalUsers;
    
#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
    ofxAzureKinect::Device kinectDevice;
#endif
    
    void setupConfig();
    void setupPoses();
    void setupDevice();
    void updatePoseDetection(BodySkeleton skeleton);
};

#endif /* KinectController_h */
