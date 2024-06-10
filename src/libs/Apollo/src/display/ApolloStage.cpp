//
//  ApolloStage.cpp
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloStage.h"

namespace Apollo {
	
	Stage::Stage() {
		activeScene	= NULL;
		nextScene	= NULL;
		sceneIndex	= -1;
	}
	
	Stage::~Stage() {
		activeScene	= NULL;
		nextScene	= NULL;
	}
	
	bool Stage::addChild(DisplayObject* obj) {
		if( !DisplayObject::addChild(obj) ) return false;
		obj->visible = false;
		return true;
	}
	
	void Stage::showChild(string name) {
		int index = getChildIndex(name);
		if(index < 0) return;
		children[index]->visible = true;
	}
	
	void Stage::hideChild(string name) {
		int index = getChildIndex(name);
		if(index < 0) return;
		children[index]->visible = false;
	}
	
	#pragma mark Scene
	
	void Stage::showScene(string name) {
		int index = getChildIndex(name);
		if(index < 0) return;
		nextScene  = (Scene*)children[index];
		sceneIndex = index;
		
		if(activeScene != NULL) hideCurrentScene();
		else showNextScene();
	}
	
	void Stage::showSceneAt(int index) {
		if(index < 0 || index >= numChildren()) return;
		nextScene  = (Scene*)children[index];
		sceneIndex = index;
		
		if(activeScene != NULL) hideCurrentScene();
		else showNextScene();
	}
	
	void Stage::hideScene() {
		if(activeScene != NULL) hideCurrentScene();
	}
	
	#pragma mark Handlers
	
	void Stage::evtHandler(Event *evt) {
		const string eType = evt->type;
		if(eType == Scene::SCENE_OUT) {
			activeScene->removeListener(Scene::SCENE_OUT, this);
			activeScene = NULL;
			//
			if(nextScene != NULL) showNextScene();
		}
	}
	
	#pragma mark Protected
	
	void Stage::updateChildren() {
		DisplayObject *obj;
		int i, total = numChildren();
		for(i = 0; i < total; ++i) {
			obj = children[i];
			if(obj->visible) {
				if(obj->right()  > size.x) width( obj->right() );
				if(obj->bottom() > size.y) height(obj->bottom());
				obj->update();
			}
		}
		obj = NULL;
		
		if(activeScene != NULL) activeScene->updateTime();
	}
	
	void Stage::showNextScene() {
		activeScene = nextScene;
		nextScene = NULL;
		//
		activeScene->show();
	}
	
	void Stage::hideCurrentScene() {
		activeScene->addListener(Scene::SCENE_OUT, this);
		activeScene->hide();
	}
	
}
