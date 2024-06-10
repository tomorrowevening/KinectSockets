//
//  Tween.h
//  Apollo
//  Created by Colin Duffy on 5/3/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloAnimation.h"
#include "ApolloTime.h"
#include "ApolloVec2.h"
#include "ApolloVec3.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	using namespace std;
	using namespace Apollo;

	class Tween : public EventDispatcher {
	protected:
		
		CubicEase points;
		
	public:
		
		float* var;
		float from, to;
		double duration, timestamp;
		double end();
		
		void update(float percent);
		
		void onComplete() {
			AnimationEvent aEvt = AnimationEvent(AnimationEvent::ON_COMPLETE, name);
			dispatchEvent(aEvt);
		}
		
		Tween(string name = "");
		
		// Getters
		double range();
		static CubicEase getEase(PennerEases ease);
		bool isComplete();
		float progress();
		
		// Setters
		void setLinear();
		void setEase(float x0, float y0, float x1, float y1);
		void setEase(Vec2 c0, Vec2 c1);
		void setPenner(PennerEases ease);
		void setStepped();
		
	};
}