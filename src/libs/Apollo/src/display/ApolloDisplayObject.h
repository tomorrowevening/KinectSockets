//
//  ApolloDisplayObject.h
//  Apollo
//  Created by Colin Duffy on 7/22/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloEventDispatcher.h"
#include "ApolloGL.h"
//#include "ApolloFBO.h"
#include "ApolloStrings.h"
#include "ApolloVec2.h"
#include "ApolloVec3.h"

using namespace std;
using namespace Apollo;

namespace Apollo {
	
	class DisplayObject : public EventHandler, public EventDispatcher {
	public:
		
		string						name;
		bool						snapshot, visible;
		Vec3						anchor, position, rotation, scale, size;
		float						alpha;
		int							zIndex;
		DisplayObject*				parent;
		vector<DisplayObject*>		children;
		
		DisplayObject();
		virtual ~DisplayObject() {	dispose(); }
		
		virtual void				setup(float _x, float _y, float _width, float _height);
		virtual void				dispose();
		virtual void				update();
		virtual void				draw();
		virtual void				drawAfter() {} // called before draw is complete, outside matrices
		virtual void				drawBounds();
		
		virtual bool				addChild(DisplayObject* obj);
		virtual bool				hasChild(DisplayObject* obj);
		virtual DisplayObject*		getChildAt(int index);
		virtual DisplayObject*		getChildByName(string name);
		virtual int					getChildIndex(DisplayObject* obj);
		virtual int					getChildIndex(string name);
		virtual void				removeChild(DisplayObject* obj);
		virtual void				removeChildAt(int index);
		virtual void				removeAllChildren();
		
		// Getters
		
		// Position
		virtual const float			left()  { return position.x; }
		virtual const float			top()   { return position.y; }
		virtual const float			front() { return position.z; }
		virtual const float			right() { return left()  + size.x; }
		virtual const float			bottom(){ return top()   + size.y; }
		virtual const float			back()  { return front() + size.z; }
		virtual const float			centerX(){ return size.x * 0.5f + position.x; }
		virtual const float			centerY(){ return size.y * 0.5f + position.y; }
		virtual const float			centerZ(){ return size.z * 0.5f + position.z; }
		virtual const Vec3			absolutePos();
		virtual const float			absoluteLeft();
		virtual const float			absoluteTop();
		virtual const float			absoluteFront();
		virtual const float			absoluteRight() { return absoluteLeft()  + size.x; }
		virtual const float			absoluteBottom(){ return absoluteTop()   + size.y; }
		virtual const float			absoluteBack()  { return absoluteFront() + size.z; }
		
		// Size
		virtual const float			width()  { return size.x; }
		virtual const float			height() { return size.y; }
		virtual const float			depth()  { return size.z; }
		
		virtual const bool hitTest(float x, float y) {
			return Apollo::inRange(x, absoluteLeft(), absoluteRight()) && Apollo::inRange(y, absoluteTop(), absoluteBottom());
		}
		
		virtual const bool hitTest(Vec2 pos, Vec2 size) {
			float	vRight  = pos.x + size.x,
					vBottom = pos.y + size.y;
			bool overlapX =	Apollo::inRange(pos.x, absoluteLeft(), absoluteRight()) || Apollo::inRange(pos.x+size.x, absoluteLeft(), absoluteRight()) ||
							Apollo::inRange(absoluteLeft(), pos.x, vRight)  || Apollo::inRange(absoluteRight(), pos.x, vRight);
			bool overlapY =	Apollo::inRange(pos.y, absoluteTop(), absoluteBottom()) || Apollo::inRange(vBottom, absoluteTop(), absoluteBottom()) ||
							Apollo::inRange(absoluteTop(), pos.y, vBottom)  || Apollo::inRange(absoluteBottom(), pos.y, vBottom);
			return overlapX && overlapY;
		}
		
		virtual const bool hitTest(DisplayObject *dObj) {
			float	vLeft   = dObj->absoluteLeft(),
					vRight  = dObj->absoluteRight(),
					vTop    = dObj->absoluteTop(),
					vBottom = dObj->absoluteBottom();
			bool overlapX =	Apollo::inRange(vLeft, absoluteLeft(), absoluteRight()) || Apollo::inRange(vRight, absoluteLeft(), absoluteRight()) ||
							Apollo::inRange(absoluteLeft(), vLeft, vRight)  || Apollo::inRange(absoluteRight(), vLeft, vRight);
			bool overlapY =	Apollo::inRange(vTop, absoluteTop(), absoluteBottom()) || Apollo::inRange(vBottom, absoluteTop(), absoluteBottom()) ||
							Apollo::inRange(absoluteTop(), vTop, vBottom)  || Apollo::inRange(absoluteBottom(), vTop, vBottom);
			return overlapX && overlapY;
		}
		
		const int numChildren() {
			return (int)children.size();
		}
		
		const float opacity() {
			if(parent) return alpha * parent->alpha;
			return alpha;
		}
		
		const float opacityHex() { return opacity() * 255.f; }
		
		// Setters
		
		virtual void				left(float value)  { position.x = value; }
		virtual void				top(float value)   { position.y = value; }
		virtual void				front(float value) { position.z = value; }
		virtual void				right(float value) { left( value - size.x); }
		virtual void				bottom(float value){ top(  value - size.y); }
		virtual void				back(float value)  { front(value - size.z); }
		virtual void				centerX(float value)  { left( value - (size.x * 0.5f)); }
		virtual void				centerY(float value)  { top(  value - (size.y * 0.5f)); }
		virtual void				centerZ(float value)  { front(value - (size.z * 0.5f)); }
		virtual void				width(float value)  { size.x = value; }
		virtual void				height(float value) { size.y = value; }
		virtual void				depth(float value)  { size.z = value; }
		
	protected:
		
//		gl::FBO						screenshot;
		
		bool						sortChildren;
		
		virtual void				updateChildren();
		virtual void				drawChildren();
		virtual void				render() {}
		
	private:
		
		static int					displayObjectCount;
		bool operator<(const DisplayObject& val) const { return zIndex < val.zIndex; }
		
	};
	
	struct DisplayObjectSort {
		inline bool operator() (DisplayObject *a, DisplayObject *b) {
			return a->position.z < b->position.z;
		}
	};
	
}
