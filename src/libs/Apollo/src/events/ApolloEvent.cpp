//
//  ApolloEvent.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloEvent.h"

namespace Apollo {
	
	const string Event::ADDED					= "Event::added";
	const string Event::REMOVED					= "Event::removed";
	const string Event::ENABLE					= "Event::enable";
	const string Event::DISABLE					= "Event::disable";
	const string Event::UPDATE					= "Event::update";
	const string Event::DRAW					= "Event::draw";
	const string Event::RESIZE					= "Event::resize";
	
	const string KeyEvent::DOWN					= "KeyEvent::down";
	const string KeyEvent::UP					= "KeyEvent::up";
	
	const string AnimationEvent::ON_UPDATE		= "AnimationEvent::onUpdate";
	const string AnimationEvent::ON_COMPLETE	= "AnimationEvent::onComplete";
	
	const string ActionEvent::DOWN				= "ActionEvent::down";
	const string ActionEvent::MOVE				= "ActionEvent::move";
	const string ActionEvent::UP				= "ActionEvent::up";
	const string ActionEvent::OVER				= "ActionEvent::over";
	const string ActionEvent::OUT				= "ActionEvent::out";
	const string ActionEvent::DRAGGED			= "ActionEvent::dragged";
	const string ActionEvent::SCROLLED			= "ActionEvent::scrolled";
	const string ActionEvent::DOUBLE_TAP		= "ActionEvent::doubleTap";
	
}
