//
//  ApolloStage.h
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloDisplayObject.h"
#include "ApolloScene.h"

namespace Apollo {
	
	class Stage : public DisplayObject {
	public:
		
		Scene				*activeScene;
		int					sceneIndex;
		
		Stage();
		virtual ~Stage();
		
		virtual bool addChild(DisplayObject* obj);
		virtual void showChild(string name);
		virtual void hideChild(string name);
		virtual void showScene(string name);
		virtual void showSceneAt(int index);
		virtual void hideScene();
		
		// Handlers
		
		virtual void evtHandler(Event *evt);
		
	protected:
		
		Scene				*nextScene;
		
		virtual void updateChildren();
		virtual void showNextScene();
		virtual void hideCurrentScene();
		
	};
	
}
