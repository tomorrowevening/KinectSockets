//
//  ApolloInputButton.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloInput.h"
#include "ApolloGL.h"

namespace Apollo {
	
	int InputButton::buttonIndex = 0;
	const string InputButton::CLICK = "Apollo::InputButton::Click";
	const string InputButton::defaultText = "Type here...";
	
	InputButton::InputButton() {
		_enabled = _isOver = _isDown = false;
		name = "btnInput_" + Apollo::toString(InputButton::buttonIndex);
		text = defaultText;
		_shifted = false;
		_selected = false;
		++InputButton::buttonIndex;
	}
	
	InputButton::~InputButton() { disable(); }
	
	void InputButton::enable() {
		_enabled = true;
		Dispatcher.addListener(ActionEvent::DOWN,	this);
		Dispatcher.addListener(ActionEvent::UP,		this);
		Dispatcher.addListener(KeyEvent::DOWN,		this);
	}
	
	void InputButton::disable() {
		_enabled = false;
		Dispatcher.removeListener(ActionEvent::DOWN,	this);
		Dispatcher.removeListener(ActionEvent::UP,		this);
		Dispatcher.removeListener(KeyEvent::DOWN,		this);
	}
	
	void InputButton::render() {
		if(_isDown) {
			Apollo::setColorGL(1.f, 0, 0);
		} else if(_selected) {
			Apollo::setColorGL(0.2f, 1.f);
		} else {
			Apollo::setColorGL(0, _enabled ? 1.f : 0.5f);
		}
		Apollo::drawRect(0, 0, size.x, size.y);
		Apollo::setColorGL(1);
		Apollo::drawText(name + ":", 10, 15);
		Apollo::drawText(text, 10, 30);
	}
	
#pragma mark - Handlers
	
	void InputButton::evtHandler(Event *evt) {
		const string eType = evt->type;
		ActionEvent *aEvt = (ActionEvent*)evt;
		if(eType == ActionEvent::DOWN) {
			if(hitTest(aEvt->x, aEvt->y)) {
				if(!_isDown) {
					_selected = true;
					if(text == defaultText) text = "";
					onPress(aEvt);
					Event eEvt = Event(InputButton::CLICK);
					dispatchEvent(eEvt);
				}
				_isDown = true;
			} else {
				_selected = false;
				if(text == "") text = defaultText;
			}
		} else if(eType == ActionEvent::UP) {
			if(_isDown) {
				if(hitTest(aEvt->x, aEvt->y)) {
					onReleased(aEvt);
				} else {
					_selected = false;
					if(text == "") text = defaultText;
					onReleasedOutside(aEvt);
				}
			}
			
			_isDown = false;
		} else if(eType == KeyEvent::DOWN) {
			
			if(!_selected) return;
			KeyEvent *kEvt = (KeyEvent*)evt;
			const int code = kEvt->keyCode;
			if(code == OF_KEY_BACKSPACE) {
				int tLen = text.length();
				if(tLen > 0) {
					text = text.substr(0, tLen-1);
				}
			} else if(code == OF_KEY_SHIFT) {
				_shifted = true;
			} else if(code == OF_KEY_RETURN) {
				text += "\n";
			} else if(code == OF_KEY_TAB) {
				text += "\t";
			} else {
				string sCode = "";
				text.insert(text.end(), code);
			}
			
		} else if(eType == KeyEvent::UP) {
			
			if(!_selected) return;
			KeyEvent *kEvt = (KeyEvent*)evt;
			const int code = kEvt->keyCode;
			if(code == OF_KEY_SHIFT) _shifted = false;
			
		}
	}
}
