//
//  ApolloButton.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloButton.h"
#include "ApolloGL.h"

namespace Apollo {
	
	string	Button::CLICK			= "Apollo::Button::Click";
	string	Button::DRAG_START		= "Apollo::Button::DragStart";
	string	Button::DRAG_END		= "Apollo::Button::DragEnd";
	int		Button::buttonIndex		= 0;
	
	Button::Button() {
		_enabled = _isOver = _isDown = draggable = false;
		name = "btn_" + Apollo::toString(Button::buttonIndex);
		++Button::buttonIndex;
	}
	
	Button::~Button() { disable(); }
	
	void Button::enable() {
		_enabled = true;
#ifdef APOLLO_COCOA_TOUCH
		enableTouch();
#else
		enableMouse();
#endif
	}
	
	void Button::disable() {
		_enabled = false;
#ifdef APOLLO_COCOA_TOUCH
		disableTouch();
#else
		disableMouse();
#endif
	}
	
	void Button::render() {
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
		Apollo::setColorGL(1);
		Apollo::drawText(name, 10, 15);
	}
	
#pragma mark - Private
	
	void Button::enableMouse() {
		Dispatcher.addListener(ActionEvent::DRAGGED,		this);
		Dispatcher.addListener(ActionEvent::MOVE,			this);
		Dispatcher.addListener(ActionEvent::DOWN,			this);
		Dispatcher.addListener(ActionEvent::UP,				this);
		Dispatcher.addListener(ActionEvent::SCROLLED,		this);
	}
	
	void Button::enableTouch() {
		Dispatcher.addListener(ActionEvent::DOUBLE_TAP,		this);
		Dispatcher.addListener(ActionEvent::DOWN,			this);
		Dispatcher.addListener(ActionEvent::MOVE,			this);
		Dispatcher.addListener(ActionEvent::UP,				this);
	}
	
	void Button::disableMouse() {
		Dispatcher.removeListener(ActionEvent::DRAGGED,		this);
		Dispatcher.removeListener(ActionEvent::MOVE,		this);
		Dispatcher.removeListener(ActionEvent::DOWN,		this);
		Dispatcher.removeListener(ActionEvent::UP,			this);
		Dispatcher.removeListener(ActionEvent::SCROLLED,	this);
	}
	
	void Button::disableTouch() {
		Dispatcher.removeListener(ActionEvent::DOUBLE_TAP,	this);
		Dispatcher.removeListener(ActionEvent::DOWN,		this);
		Dispatcher.removeListener(ActionEvent::MOVE,		this);
		Dispatcher.removeListener(ActionEvent::UP,			this);
	}
	
#pragma mark - Handlers
	
	void Button::evtHandler(Event *evt) {
		const string eType = evt->type;
		ActionEvent *aEvt = (ActionEvent*)evt;
		if(eType == ActionEvent::DOWN) {
			if(hitTest(aEvt->x, aEvt->y)) {
				if(!_isDown) {
					if(draggable) {
						_touchOffset.set(aEvt->x-absoluteLeft(), aEvt->y-absoluteTop());
						_touchOffsetID = aEvt->index;
					}
					onPress(aEvt);
					Event aEvt = Event(Button::CLICK);
					dispatchEvent( aEvt );
				}
				_isDown = true;
			}
		} else if(eType == ActionEvent::UP) {
			if(aEvt->index == _touchOffsetID) {
				_touchOffset.set(0, 0);
				_touchOffsetID = 0;
			}
			
			if(_isDown) {
				if(hitTest(aEvt->x, aEvt->y)) {
					onReleased(aEvt);
				} else {
					onReleasedOutside(aEvt);
				}
				if(_isDragging) {
					_isDragging = false;
					Event eEvt = Event(Button::DRAG_END);
					dispatchEvent( eEvt );
				}
			}
			
			_isDown = false;
		} else if(eType == ActionEvent::MOVE) {
			if(hitTest(aEvt->x, aEvt->y)) {
				if(!_isOver) onRollOver(aEvt);
				_isOver = true;
				onMove(aEvt);
			} else if(_isOver) {
				onRollOut(aEvt);
				_isOver = false;
			}
		} else if(eType == ActionEvent::SCROLLED) {
			onScroll(aEvt);
		} else if(eType == ActionEvent::DRAGGED) {
			if(_isDown) {
				if(!_isDragging) {
					Event aEvt = Event(Button::DRAG_START);
					dispatchEvent( aEvt );
				}
				_isDragging = true;
				onDrag(aEvt);
			}
		} else if(eType == ActionEvent::DOUBLE_TAP) {
			if(hitTest(aEvt->x, aEvt->y)) onDoubleTap(aEvt);
		}
	}
}
