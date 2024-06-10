//
//  ApolloMath.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloMath.h"

namespace Apollo {
    
    float clamp(float value, float minV, float maxV) {
		return std::max(minV, std::min(value, maxV));
	}
	
	float lerp(float per, float min, float max) {
		return (max - min) * per + min;
	}
	
	float getRange(float value, float min, float max) {
		return (value - min) / (max - min);
	}
	
	// Rounds by hundreds
	float roundTo(float value, int ordinal) {
		return round(value * ordinal) * (1.f / (float)ordinal);
	}
    
    bool inRange(float value, float min, float max) {
		return value >= min && value <= max;
	}
    
    float random(float max) {
		return ((float)rand()/(float)RAND_MAX) * max;
	}
	
	float randomRange(float min, float max) {
		return random(max-min) + min;
	}
    
    float toDeg(float radians) {
		return radians * DEGREES;
	}
	
	float toRad(float degrees) {
		return degrees * RADIANS;
	}
	
	float getAngleRad(float x1, float y1, float x2, float y2) {
		return atan2( y2-y1, x2-x1 );
	}
	
	float getAngleDeg(float x1, float y1, float x2, float y2) {
		return toDeg(getAngleRad(x1, y1, x2, y2));
	}
    
    float distance(float a, float b) {
		float v = a-b;
		return sqrtf(v * v);
	}
	
	float distance(float x1, float y1, float x2, float y2) {
		float x = x1 - x2;
		float y = y1 - y2;
		return sqrtf( (x*x) + (y*y));
	}
	
	float distance(float x1, float y1, float z1, float x2, float y2, float z2) {
		float x = x1 - x2;
		float y = y1 - y2;
		float z = z1 - z2;
		return sqrtf( (x*x) + (y*y) + (z*z));
	}
	
	float cosRange(float degrees, float range, float min) {
		return (((1.0f + cos(toRad(degrees))) * 0.5f) * range) + min;
	}
	
	float sinRange(float degrees, float range, float min) {
		return (((1.0f + sin(toRad(degrees))) * 0.5f) * range) + min;
	}
    
}
