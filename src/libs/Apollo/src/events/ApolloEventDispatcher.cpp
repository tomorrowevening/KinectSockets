//
//  ApolloEventDispatcher.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	EventDispatcher Dispatcher;
	int EventDispatcher::total = 0;
	
	EventDispatcher::EventDispatcher() {
		name = "EventDispatcher::" + toString(EventDispatcher::total);
		++EventDispatcher::total;
	}
	
	EventDispatcher::~EventDispatcher() {
		removeAllListeners();
	}
	
	void EventDispatcher::addListener(const string eventType, EventHandler *handler) {
		EventData eData;
		eData.handler	= handler;
		eData.type		= eventType;
		handlers.push_back( eData );
	}
	
	void EventDispatcher::removeListener(const string eventType, EventHandler *handler) {
		int i, total = totalHandlers();
		for(i = 0; i < total; ++i) {
			if(handlers[i].type == eventType && handlers[i].handler == handler) {
				handlers.erase(handlers.begin() + i); // delete
				return;
			}
		}
	}
	
	void EventDispatcher::removeAllListeners() {
		handlers.clear();
	}
	
	void EventDispatcher::dispatchEvent(Event &event) {
		if( !hasListener(event.type) ) return;
		
		event.setDispatcher(this);
		
		int i, total = totalHandlers();
		for(i = 0; i < total; ++i) {
			if(handlers[i].type == event.type) {
				handlers[i].handler->evtHandler(&event);
			}
		}
	}
	
#pragma mark - Getters
	
	int EventDispatcher::totalHandlers() {
		return handlers.size();
	}
	
	bool EventDispatcher::hasListener(const string eventType) {
		int i, total = totalHandlers();
		for(i = 0; i < total; ++i) {
			if(handlers[i].type == eventType) return true;
		}
		return false;
	}
	
}
