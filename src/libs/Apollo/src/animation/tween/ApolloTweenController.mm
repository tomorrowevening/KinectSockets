//
//  TweenController.cpp
//  Apollo
//  Created by Colin Duffy on 5/6/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloTweenController.h"

#ifdef OF_VERSION_MAJOR
#include "ofMain.h"
#endif

namespace Apollo {

	TweenController Motion;

	void TweenController::update() {
		_activeTweens = 0;
		float aniPercent;
		for(int i = tweens.size() -1; i >= 0; --i){
			aniPercent = tweens[i].progress();
			if(tweens[i].isComplete()){
				tweens[i].var[0] = tweens[i].to;
				tweens[i].onComplete();
				removeTween(i);
			} else if(aniPercent > 0){
				tweens[i].update(aniPercent);
				++_activeTweens;
			}
		}
	}
	
	void TweenController::drawDebug() {
#ifdef OF_VERSION_MAJOR
		ofSetColor(255);
		ofDrawBitmapString("Total tweens: " + ofToString(totalTweens()), 25, 25);
#endif
	}

	//////////////////////////////////////////////////
	#pragma mark - Management
	//////////////////////////////////////////////////
	
	Tween* TweenController::addTween(float &var, float to, float time, CubicEase ease, float delay) {
		return addTween(var, to, time, ease.c0.x, ease.c0.y, ease.c1.x, ease.c1.y, delay);
	}
	
	Tween* TweenController::addTween(float &var, float to, float time, PennerEases ease, float delay) {
		CubicEase tEase = Tween::getEase(ease);
		return addTween(var, to, time, tEase.c0.x, tEase.c0.y, tEase.c1.x, tEase.c1.y, delay);
	}

	Tween* TweenController::addTween(float &var, float to, float time, Vec2 c0, Vec2 c1, float delay) {
		return addTween(var, to, time, c0.x, c0.y, c1.x, c1.y, delay);
	}

	Tween* TweenController::addTween(float &var, float to, float time, float x0, float y0, float x1, float y1, float delay) {
		float from = var;
		float _delay = 0;
		float latest = 0;
		double now = getSystemMS();
		
		const int total = totalTweens();
		const bool override = overrideTween();
		for(int i = 0; i < total; ++i){
			if(tweens[i].var == &var) {
				if(override){
					tweens[i].from = from;
					tweens[i].to = to;
					tweens[i].setEase(x0, y0, x1, y1);
					tweens[i].timestamp = now + (delay * 1000.);
					tweens[i].duration = time * 1000.;
					return &tweens[i];
				} else {
					//sequence mode
					if((tweens[i].timestamp + tweens[i].duration) > latest){
						latest = (tweens[i].timestamp + tweens[i].duration);
						_delay = (tweens[i].duration - Apollo::getElapsedMS(tweens[i].timestamp));
						from = tweens[i].to;
					}
				}
			}
		}
		
		Tween t;
		t.var = &var;
		t.from = from;
		t.to = to;
		t.setEase(x0, y0, x1, y1);
		t.timestamp = now + (delay * 1000.) + _delay;
		t.duration = time * 1000.;
		tweens.push_back(t);
		
		return &tweens[total];
	}

	void TweenController::removeTween(int index) {
		tweens.erase(tweens.begin() + index);
	}

	void TweenController::removeTween(float &var) {
		for(int i = totalTweens()-1; i > -i; --i) if(tweens[i].var == &var) removeTween(i);
	}

	void TweenController::removeAllTweens() { tweens.clear(); }

	//////////////////////////////////////////////////
	#pragma mark - Getters
	//////////////////////////////////////////////////
	
	int TweenController::activeTweens() { return _activeTweens; }

	int TweenController::totalTweens() { return (int)tweens.size(); }

	//////////////////////////////////////////////////
	#pragma mark - Setters
	//////////////////////////////////////////////////

	void TweenController::setPlaymode(Playmode playMode) { this->playMode = playMode; }

}