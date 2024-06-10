//
//  ApolloDisplayObject.cpp
//  Apollo
//  Created by Colin Duffy on 7/22/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "ApolloDisplayObject.h"

namespace Apollo {
	
	int DisplayObject::displayObjectCount = 0;
	
	DisplayObject::DisplayObject() {
		this->name = "Apollo::DisplayObject::" + toString(DisplayObject::displayObjectCount);
		this->snapshot = false;
		this->visible  = true;
		this->alpha = 1.f;
		this->anchor.set(0, 0, 0);
		this->position.set(0, 0, 0);
		this->rotation.set(0, 0, 0);
		this->scale.set(1, 1, 1);
		this->size.set(0, 0, 0);
		this->parent = NULL;
		this->sortChildren = false;
		
		++DisplayObject::displayObjectCount;
	}
	
	void DisplayObject::setup(float _x, float _y, float _width, float _height) {
		position.set(_x, _y, 0);
		size.set(_width, _height, 0);
	}
	
	void DisplayObject::dispose() {
		parent = NULL;
//		screenshot.dispose();
		
		int i, total = numChildren()-1;
		for(i = total; i > -1; --i) {
			children[i]->dispose();
			delete children[i];
		}
		children.clear();
	}
	
	void DisplayObject::update() {
		updateChildren();
	}
	
	void DisplayObject::drawBounds() {
		noFill();
		setColorGL(1.f, 0, 0);
		drawRect(0, 0, size.x, size.y);
		setColorGL(1.f);
		fill();
	}
	
	void DisplayObject::updateChildren() {
		DisplayObject *obj;
		int i, total = numChildren();
		for(i = 0; i < total; ++i) {
			obj = children[i];
			if(obj->right()  > size.x) width( obj->right() );
			if(obj->bottom() > size.y) height(obj->bottom());
			obj->update();
		}
		obj = NULL;
	}
	
	void DisplayObject::drawChildren() {
		if(sortChildren) {
			sort(children.begin(), children.end(), DisplayObjectSort());
		}
		int i, total = numChildren();
		for(i = 0; i < total; ++i) children[i]->draw();
	}
	
	void DisplayObject::draw() {
		if(!visible || alpha <= 0) return;
		
		Apollo::pushMatrix();
		
		Apollo::translate(position);
		Apollo::rotate(rotation);
		Apollo::scale(scale);
		Apollo::translate(-anchor);
		setColorGL(1.f, opacity());
		
//		if(snapshot) {
//			screenshot.draw();
//		} else {
			render();
//		}
		
#ifdef APOLLO_DEBUG
		drawBounds();
#endif
		
		// Layers
		drawChildren();
		Apollo::popMatrix();
		drawAfter();
	}
	
	bool DisplayObject::addChild(DisplayObject* obj) {
		if( obj->parent == this ) return false;
		if( obj->parent != NULL ) obj->parent->removeChild(obj);
		
		if(!sortChildren) {
			int total = numChildren();
			if(total > 0) {
				float z = children[0]->position.z;
				for(int i = 0; i < total; ++i) {
					if(children[i]->position.z != z) {
						sortChildren = true;
						break;
					}
				}
			}
		}
		
		obj->parent = this;
		children.push_back( obj );
		return true;
	}
	
	bool DisplayObject::hasChild(DisplayObject* obj) {
		return getChildIndex(obj) > -1;
	}
	
	DisplayObject* DisplayObject::getChildAt(int index) {
		if(index < numChildren()) return children[index];
		return NULL;
	}
	
	DisplayObject* DisplayObject::getChildByName(string name) {
		int i, total = numChildren();
		for(i = 0; i < total; ++i) {
			if(children[i]->name == name) return children[i];
		}
		return NULL;
	}
	
	int DisplayObject::getChildIndex(DisplayObject* obj) {
		int i, total = numChildren();
		for(i = 0; i < total; ++i) if(children[i] == obj) return i;
		return -1;
	}
	
	int DisplayObject::getChildIndex(string name) {
		int i, total = numChildren();
		for(i = 0; i < total; ++i) if(children[i]->name == name) return i;
		return -1;
	}
	
	void DisplayObject::removeChild(DisplayObject* obj) {
		int i, index = -1, total = numChildren();
		for(i = 0; i < total; ++i) {
			if(children[i] == obj) {
				index = i;
				removeChildAt(index);
				return;
			}
		}
	}
	
	void DisplayObject::removeChildAt(int index) {
		children[index]->parent = NULL;
		children.erase( children.begin() + index );
	}
	
	void DisplayObject::removeAllChildren() {
		for(int i = numChildren()-1; i > -1; --i) removeChildAt(i);
		children.clear();
	}
	
	const Vec3 DisplayObject::absolutePos() {
		if(parent != NULL) return parent->absolutePos() + position;
		return position;
	}
	
	const float DisplayObject::absoluteLeft() {
		if(parent != NULL) return parent->absoluteLeft() + position.x;
		return position.x;
	}
	
	const float DisplayObject::absoluteTop() {
		if(parent != NULL) return parent->absoluteTop() + position.y;
		return position.y;
	}
	
	const float DisplayObject::absoluteFront() {
		if(parent != NULL) return parent->absoluteFront() + position.z;
		return position.z;
	}
	
	
}
