//
//  Tween.cpp
//  Apollo
//  Created by Colin Duffy on 5/3/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloTween.h"

namespace Apollo {
	
	Tween::Tween(string name) {
		this->name = name;
	}

	void Tween::update(float percent) {
		var[0] = points.getCurvePercent(percent) * range() + from;
		AnimationEvent aEvt = AnimationEvent(AnimationEvent::ON_UPDATE, name);
		dispatchEvent(aEvt);
	}

	//////////////////////////////////////////////////
	#pragma mark - Setters
	//////////////////////////////////////////////////

	void Tween::setLinear() {
		points.setLinear();

	}
	void Tween::setEase(float x0, float y0, float x1, float y1) {
		points.set(x0, y0, x1, y1);
	}

	void Tween::setEase(Vec2 c0, Vec2 c1) {
		points.set(c0, c1);
	}
	
	void Tween::setPenner(PennerEases ease) {
		points.copy( getEase(ease) );
	}

	void Tween::setStepped(){
		points.setStepped();
	}

	//////////////////////////////////////////////////
	#pragma mark - Getters
	//////////////////////////////////////////////////
	
	float Tween::progress() {
		float since = getElapsedMS(timestamp);
		return since / duration;
	}
	
	bool Tween::isComplete() {
		return progress() >= 1.f;
	}
	
	double Tween::end() {
		return timestamp + duration;
	}

	double Tween::range() {
		return to - from;
	}
	
	CubicEase Tween::getEase(PennerEases ease) {
		return CubicEase::getPenner(ease);
	}

}