//
//  ApolloEventDispatcher.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include <vector>
#include "ApolloEventHandler.h"
#include "ApolloStrings.h"

using namespace std;

namespace Apollo {
	
	class Event;
	
	typedef struct {
		EventHandler *handler;
		string type;
	} EventData;
	
	class EventDispatcher {
	public:
		
		static int				total;
		string					name;
		
		EventDispatcher();
		virtual ~EventDispatcher();
		
		virtual void			addListener(const string eventType, EventHandler *handler);
		virtual void			removeListener(const string eventType, EventHandler *handler);
		virtual void			removeAllListeners();
		virtual void			dispatchEvent(Event &event);
		
		// Getters
		virtual int				totalHandlers();
		virtual bool			hasListener(const string eventType);
		
	protected:
		
		vector<EventData>		handlers;
		
	};
	
	extern EventDispatcher		Dispatcher;
	
}
