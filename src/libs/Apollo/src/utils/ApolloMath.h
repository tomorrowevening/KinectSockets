//
//  ApolloMath.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include <math.h>
#include <iostream>
#include <algorithm>
#include "ApolloCore.h"

#ifndef RADIANS
#define RADIANS									0.017453292519943295f
#endif

#ifndef DEGREES
#define DEGREES									57.29577951308232f
#endif

#ifndef PI
#define PI										3.14159265359f
#endif

#ifndef PI_2
#define PI_2									PI * 2.f
#endif

#ifndef PI_HALF
#define PI_HALF									( PI * (float)0.5 )
#endif

namespace Apollo {
    
    float	clamp(float value, float minV, float maxV);
	float	lerp(float per, float min, float max);
	float	getRange(float value, float min, float max);
	float	roundTo(float value, int ordinal = 1);
    
    // Random
    
    float   random(float max);
	float   randomRange(float min, float max);
    
    // Bools
    
    bool    inRange(float value, float min, float max);
    
    // Trig
    
    float   toDeg(float radians);
	float   toRad(float degrees);
	float   getAngleRad(float x1, float y1, float x2, float y2);
	float   getAngleDeg(float x1, float y1, float x2, float y2);
    
    float   distance(float a, float b);
	float   distance(float x1, float y1, float x2, float y2);
	float   distance(float x1, float y1, float z1, float x2, float y2, float z2);
    float   distance(float x1, float y1, float z1, float w1, float x2, float y2, float z2, float w2);
	
	float cosRange(float degrees, float range, float min);
	float sinRange(float degrees, float range, float min);
    
}
