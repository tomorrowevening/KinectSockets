//
//  ApolloSpring.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloVec3.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"

namespace Apollo {
	
#ifndef SPRING_HISTORY_LENGTH
	#define SPRING_HISTORY_LENGTH			20
	#define SPRING_INTERPOLATION_PRECISION	0.01
#endif
    
    class Spring : public EventDispatcher {
    public:
        
        float			target, value;
        float			acc, vel;
        float			friction, mass, bounce;
		vector<float>	history;
		string			identifer;
        
        // Targets
        float			*pointer;
        
        Spring(string sID = "");
        virtual ~Spring();
        virtual void update();
		
		// Getters
		
		const bool complete() {
			return sqrt(vel*vel) < SPRING_INTERPOLATION_PRECISION;
		}
        
    };
    
    class SpringVec : public EventDispatcher {
    public:
        
        Vec3			target, value;
        Vec3			acc, vel;
        float			friction, mass, bounce;
		vector<Vec3>	history;
		string			identifer;
        
        // Targets
        Vec3			*pointer;
        
        SpringVec(string sID = "");
        virtual ~SpringVec();
        virtual void update();
		virtual void draw();
		
		// Getters
		
		const bool complete() {
			return vel.length() < SPRING_INTERPOLATION_PRECISION;
		}
        
    };
    
}
