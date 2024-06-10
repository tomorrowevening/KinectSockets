//
//  ApolloButton.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloToggle.h"

namespace Apollo {
	
	string	Toggle::TOGGLE			= "Apollo::Toggle::Toggle";
	int		Toggle::toggleIndex		= 0;
	
	Toggle::Toggle() {
		_selected = false;
		name = "toggle_" + Apollo::toString(Toggle::toggleIndex);
		++Toggle::toggleIndex;
	}
	
	Toggle::~Toggle() { disable(); }
	
	void Toggle::select() {
		_selected = true;
	}
	
	void Toggle::deselect() {
		_selected = false;
	}
	
	void Toggle::toggle() {
		_selected ? deselect() : select();
		Event aEvt = Event(Toggle::TOGGLE);
		dispatchEvent( aEvt );
	}
	
	void Toggle::render() {
		if(_isDown) {
			Apollo::setColorGL(1.f, 0, 0);
		}
#ifndef APOLLO_COCOA_TOUCH
		else if(_isOver) {
			Apollo::setColorGL(0.8f);
		}
#endif
		else {
			Apollo::setColorGL(0, _enabled ? 1.f : 0.5f);
		}
		Apollo::drawRect(0, 0, size.x, size.y);
		
		if(_selected) {
			Apollo::setColorGL(1.0f, 0, 0, 0.5f);
			Apollo::drawRect(0, 0, size.x, size.y);
		}
		
		Apollo::setColorGL(1);
		Apollo::drawText(name, 10, 15);
	}
	
	void Toggle::evtHandler(Event *evt) {
		Button::evtHandler(evt);
		//
		const string eType = evt->type;
		ActionEvent *aEvt = (ActionEvent*)evt;
		if(eType == ActionEvent::DOWN) {
			if(hitTest(aEvt->x, aEvt->y)) {
				toggle();
			}
		}
	}
	
}
