//
//  ApolloButton.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloDisplayObject.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"
#include "ApolloStrings.h"
#include "ApolloVec2.h"
#include "ApolloVec3.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	class Button : public DisplayObject {
	public:
		
		static int buttonIndex;
		static string CLICK, DRAG_START, DRAG_END;
		
		bool draggable;
		
		Button();
		virtual ~Button();
		
		virtual void enable();
		virtual void disable();
		
		// Getters
		const bool enabled() { return _enabled; }
		const bool isPressed() { return _isDown; }
		const bool isOver() { return _isOver; }
		
	protected:
		
		bool _enabled, _isOver, _isDown, _isDragging;
		Vec2 _touchOffset;
		int _touchOffsetID;
		
		void enableMouse();
		void enableTouch();
		void disableMouse();
		void disableTouch();
		
		virtual void onDrag(ActionEvent *evt) {}
		virtual void onMove(ActionEvent *evt) {}
		virtual void onPress(ActionEvent *evt) {}
		virtual void onRollOver(ActionEvent *evt) {}
		virtual void onRollOut(ActionEvent *evt) {}
		virtual void onReleased(ActionEvent *evt) {}
		virtual void onReleasedOutside(ActionEvent *evt) {}
		virtual void onScroll(ActionEvent *evt) {}
		virtual void onDoubleTap(ActionEvent *evt) {}
		
		virtual void render();
		virtual void evtHandler(Event *event);
		
	private:
		
	};
}
