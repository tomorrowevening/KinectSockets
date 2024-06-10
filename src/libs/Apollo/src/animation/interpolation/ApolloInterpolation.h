//
//  ApolloInterpolation.h
//  Apollo
//
//  Created by Colin Duffy on 9/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloCore.h"
#include "ApolloMath.h"
#include "ApolloVec2.h"

namespace Apollo {
	
	class Interpolation {
	public:
		
		float value, target, velocity;
		float speed, spring;
		
		Interpolation(float  value = 0.0f, float target = 0.0f, float speed = 0.1f, float spring = 0);
		Interpolation(float &value, float target, float speed = 0.1f, float spring = 0);
		
		void reset();
		void update();
		
		// Getters
		
		const bool complete();
		
	protected:
		
		float* var, startValue;
		bool hasVar;
		
	};
	
}
