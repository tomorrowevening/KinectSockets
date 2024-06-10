//
//  ApolloSpringController.h
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloGL.h"
#include "ApolloMath.h"
#include "ApolloSpring.h"
#include "ApolloStrings.h"

namespace Apollo {
	
	class SpringController {
	public:
		
		vector<Spring>			springs;
		vector<SpringVec>		vSprings;
		
		SpringController();
		virtual ~SpringController();
		virtual void update();
		virtual void draw();
		
		virtual void to(float *item, float target, float friction = 0.7f, float mass = 8.f, float spring = 0.8f);
		virtual void to( Vec3 *item,  Vec3 target, float friction = 0.7f, float mass = 8.f, float spring = 0.8f);
		
		virtual void removeAllSprings();
		
	};
	
	extern SpringController Springy;
	
}
