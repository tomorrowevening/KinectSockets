//
//  ApolloSpring.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloSpring.h"
#include "ApolloGL.h"

namespace Apollo {
	
#pragma mark - Spring
	
	Spring::Spring(string sID) {
		acc		= 0;
		vel		= 0;
		target	= 0;
		value	= 0;
		
		friction	= 0.7f;
		mass		= 8.0f;
		bounce		= 0.8f;
		
		identifer = sID;
		pointer = NULL;
	}
	
	Spring::~Spring() {
		pointer = NULL;
		history.clear();
	}
	
	void Spring::update() {
#if SPRING_HISTORY_LENGTH > 0
		history.insert( history.begin(), pointer[0] );
		if(history.size() > SPRING_HISTORY_LENGTH) history.pop_back();
#endif
		float force = (value - target) * -bounce;
		acc = force / mass;
		vel = (vel + acc) * friction;
		value += vel;
		if(pointer != NULL) pointer[0] = value;
		
		if( totalHandlers() > 0 ) {
			AnimationEvent aEvt = AnimationEvent(AnimationEvent::ON_UPDATE, identifer);
			dispatchEvent( aEvt );
			if(complete()) {
				aEvt = AnimationEvent(AnimationEvent::ON_COMPLETE, identifer);
				dispatchEvent( aEvt );
			}
		}
	}
	
#pragma mark - Spring Vector
	
	SpringVec::SpringVec(string sID) {
		acc			= 0;
		vel			= 0;
		target		= 0;
		value		= 0;
		
		friction	= 0.7f;
		mass		= 8.0f;
		bounce		= 0.8f;
		
		identifer = sID;
		pointer = NULL;
	}
	
	SpringVec::~SpringVec() {
		pointer = NULL;
		history.clear();
	}
	
	void SpringVec::update() {
#if SPRING_HISTORY_LENGTH > 0
		history.insert( history.begin(), pointer[0] );
		if(history.size() > SPRING_HISTORY_LENGTH) history.pop_back();
#endif
		//
		Vec3 force = (value - target) * -bounce;
		acc = force / mass;
		vel = (vel + acc) * friction;
		value += vel;
		if(pointer != NULL) pointer[0] = value;
		
		if( totalHandlers() > 0 ) {
			AnimationEvent aEvt = AnimationEvent(AnimationEvent::ON_UPDATE, identifer);
			dispatchEvent( aEvt );
			if(complete()) {
				aEvt = AnimationEvent(AnimationEvent::ON_COMPLETE, identifer);
				dispatchEvent( aEvt );
			}
		}
	}
	
	void SpringVec::draw() {
		Apollo::setColor(255);
#if SPRING_HISTORY_LENGTH > 0
		int i, total = history.size()-1;
		if(total > 0) {
			Apollo::drawLine(value.x, value.y, value.z,
							 history[0].x, history[0].y, history[0].z);
			for(i = 0; i < total; ++i) {
				Apollo::drawLine(history[i].x,   history[i].y,   history[i].z,
								 history[i+1].x, history[i+1].y, history[i+1].z);
			}
		}
#endif
		Apollo::pushMatrix();
		Apollo::translate(value.x, value.y, value.z);
		Apollo::drawCircle(-5, -5, 10);
		Apollo::popMatrix();
	}

}
