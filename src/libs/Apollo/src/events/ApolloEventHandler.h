//
//  ApolloEventHandler.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloEvent.h"

namespace Apollo {
	
	class EventHandler {
	public:
		EventHandler() {}
		virtual ~EventHandler() {}
		virtual void evtHandler(Event *event) {}
	};
	
}
