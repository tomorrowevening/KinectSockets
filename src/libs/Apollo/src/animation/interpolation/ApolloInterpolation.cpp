//
//  ApolloInterpolation.cpp
//  Apollo
//
//  Created by Colin Duffy on 9/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloInterpolation.h"

namespace Apollo {
	
	Interpolation::Interpolation(float value, float target, float speed, float spring) {
		this->value			= value;
		this->target		= target;
		this->speed			= speed;
		this->spring		= spring;
		this->velocity		= 0;
		this->startValue	= value;
		hasVar				= false;
	}
	
	Interpolation::Interpolation(float &value, float target, float speed, float spring) {
		this->var			= &value;
		this->value			= value;
		this->target		= target;
		this->speed			= speed;
		this->spring		= spring;
		this->velocity		= 0;
		this->startValue	= value;
		hasVar				= true;
	}
	
	void Interpolation::reset() {
		if(hasVar) {
			value = target = var[0] = startValue;
		} else {
			target = value = startValue;
		}
		velocity = 0;
	}
	
	void Interpolation::update() {
		velocity = (( target - value ) * speed ) + ( velocity * spring );
		value = roundTo(value + velocity, 1000);
		//
		if(hasVar) var[0] = value;
	}
	
	const bool Interpolation::complete() {
		return value == target;
	}

}
