//
//  ApolloEvent.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloStrings.h"

namespace Apollo {
	
	class EventDispatcher;
	
	class Event {
	public:
		
		static const string		ADDED;
		static const string		REMOVED;
		static const string		ENABLE;
		static const string		DISABLE;
		static const string		UPDATE;
		static const string		DRAW;
		static const string		RESIZE;
		
		string					type;
		bool					stopped;
		
		Event() {
			this->stopped		= false;
		}
		
		Event(const string type) {
			this->type			= type;
			this->stopped		= false;
		}
		virtual ~Event() {}
		
		// Getters
		
		EventDispatcher* getDispatcher() const {
			return dispatcher;
		}
		
		// Setters
		
		void setDispatcher(EventDispatcher *dispatcher) {
			this->dispatcher = dispatcher;
		}
		
	protected:
		
		EventDispatcher *dispatcher;
		
	};
	
	class KeyEvent : public Event {
	public:
		
		static const string		DOWN;
		static const string		UP;
		
		int						keyCode;
		
		KeyEvent(const string type, int keyCode) {
			this->type		= type;
			this->keyCode	= keyCode;
		}
		
	};
	
	class AnimationEvent : public Event {
	public:
		
		static const string		ON_UPDATE;
		static const string		ON_COMPLETE;
		
		string					identifer;
		int						index;
		
		AnimationEvent(const string type, string sId, int index = 0) {
			this->type		= type;
			this->identifer	= sId;
			this->index		= index;
		}
		
	};
	
	/**
	 * Convert all Mouse & Touch events into Action Events
	 */
	class ActionEvent : public Event {
	public:
		
		static const string		DOWN;
		static const string		MOVE;
		static const string		UP;
		static const string		OVER;
		static const string		OUT;
		static const string		DOUBLE_TAP;
		static const string		DRAGGED;
		static const string		SCROLLED;
		
		int						index, x, y;
		float					pressure;
		
		ActionEvent(const string type, int x, int y, int index = 0, float pressure = 0) {
			this->type		= type;
			this->x			= x;
			this->y			= y;
			this->index		= index;
			this->pressure	= pressure;
		}
		
	};
	
}
