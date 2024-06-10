//
//  ApolloScene.h
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloDisplayObject.h"
#include "ApolloTime.h"
#include "ApolloTweenController.h"

namespace Apollo {
	
	enum SceneState {
		Scene_In = 0,
		Scene_Idle,
		Scene_Out,
		Scene_Hidden
	};
	
	class Scene : public DisplayObject {
	public:
		
		static const string		SCENE_IN;
		static const string		SCENE_OUT;
		
		SceneState				state;
		TweenController			timeline;
		int						frameNum;
		float					elapsedTime;
		
		Scene();
		virtual ~Scene();
		
		virtual void show();
		virtual void hide();
		virtual void update();
		virtual void updateTime();
		
		// Getters
		
		const bool showing() {
			return bShowing;
		}
		
		// Setters
		
		virtual void showing(bool value) {
			value ? show() : hide();
		}
		
	protected:
		
		bool					bShowing;
		float					showStart;
		
		virtual void animateIn();
		virtual void animateInComplete();
		virtual void animateOut();
		virtual void animateOutComplete();
		
	};
	
}
