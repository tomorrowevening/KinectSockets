//
//  KinectTypes.h
//  KinectSockets
//
//  Created by Colin Duffy on 6/10/24.
//

#ifndef KinectTypes_h
#define KinectTypes_h

#include "Apollo.h"

#pragma mark - Data

#if defined(APOLLO_MSW) || defined(APOLLO_LINUX)
#include "ofxAzureKinect.h"
#else
typedef enum
{
    K4ABT_JOINT_PELVIS = 0,
    K4ABT_JOINT_SPINE_NAVEL,
    K4ABT_JOINT_SPINE_CHEST,
    K4ABT_JOINT_NECK,
    K4ABT_JOINT_CLAVICLE_LEFT,
    K4ABT_JOINT_SHOULDER_LEFT,
    K4ABT_JOINT_ELBOW_LEFT,
    K4ABT_JOINT_WRIST_LEFT,
    K4ABT_JOINT_HAND_LEFT,
    K4ABT_JOINT_HANDTIP_LEFT,
    K4ABT_JOINT_THUMB_LEFT,
    K4ABT_JOINT_CLAVICLE_RIGHT,
    K4ABT_JOINT_SHOULDER_RIGHT,
    K4ABT_JOINT_ELBOW_RIGHT,
    K4ABT_JOINT_WRIST_RIGHT,
    K4ABT_JOINT_HAND_RIGHT,
    K4ABT_JOINT_HANDTIP_RIGHT,
    K4ABT_JOINT_THUMB_RIGHT,
    K4ABT_JOINT_HIP_LEFT,
    K4ABT_JOINT_KNEE_LEFT,
    K4ABT_JOINT_ANKLE_LEFT,
    K4ABT_JOINT_FOOT_LEFT,
    K4ABT_JOINT_HIP_RIGHT,
    K4ABT_JOINT_KNEE_RIGHT,
    K4ABT_JOINT_ANKLE_RIGHT,
    K4ABT_JOINT_FOOT_RIGHT,
    K4ABT_JOINT_HEAD,
    K4ABT_JOINT_NOSE,
    K4ABT_JOINT_EYE_LEFT,
    K4ABT_JOINT_EAR_LEFT,
    K4ABT_JOINT_EYE_RIGHT,
    K4ABT_JOINT_EAR_RIGHT,
    K4ABT_JOINT_COUNT
} k4abt_joint_id_t;

typedef enum
{
    K4ABT_JOINT_CONFIDENCE_NONE = 0,
    K4ABT_JOINT_CONFIDENCE_LOW = 1,
    K4ABT_JOINT_CONFIDENCE_MEDIUM = 2,
    K4ABT_JOINT_CONFIDENCE_HIGH = 3,
    K4ABT_JOINT_CONFIDENCE_LEVELS_COUNT = 4,
} k4abt_joint_confidence_level_t;

typedef k4abt_joint_confidence_level_t ConfidenceLevel;

struct BodyJoint
{
    glm::vec3 position;
    glm::quat orientation;
    ConfidenceLevel confidenceLevel;
    glm::vec2 projPos;
    k4abt_joint_id_t jointID;
};

struct BodySkeleton
{
    uint32_t id;
    BodyJoint joints[K4ABT_JOINT_COUNT];
};

#endif

#pragma mark - Poses

class KinectPose {
public:
    bool detected;
    string name;
    vector<BodyJoint> joints;
};

#pragma mark - Events

class KinectEvent : public Event {
public:
    static const string USER_JOINED;
    static const string USER_LEFT;
    static const string POSE_DETECTED;
    static const string POSE_LOST;
    
    KinectPose *pose = NULL;
};

#endif /* KinectTypes_h */
