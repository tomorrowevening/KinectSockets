//
//  ApolloOFDispatcher.h
//  Apollo
//
//  Created by Colin Duffy on 8/12/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "ApolloCore.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	class OFDispatcher {
	public:
		
		OFDispatcher() {
			enable();
		}
		
		~OFDispatcher() {
			disable();
		}
		
		void enable();
		void disable();
		
		// Handlers
		void evtUpdateHandler(ofEventArgs& evt) {
			Event aEvt = Event(Event::UPDATE);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtDrawHandler(ofEventArgs& evt) {
			Event aEvt = Event(Event::DRAW);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtKeyDownHandler(ofKeyEventArgs& evt) {
			KeyEvent aEvt = KeyEvent(KeyEvent::DOWN, evt.key);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtKeyUpHandler(ofKeyEventArgs& evt) {
			KeyEvent aEvt = KeyEvent(KeyEvent::UP, evt.key);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtMouseDraggedHandler(ofMouseEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::DRAGGED, evt.x, evt.y, evt.button);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtMouseMovedHandler(ofMouseEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::MOVE, evt.x, evt.y, evt.button);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtMousePressedHandler(ofMouseEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::DOWN, evt.x, evt.y, evt.button);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtMouseReleasedHandler(ofMouseEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::UP, evt.x, evt.y, evt.button);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtMouseScrolledHandler(ofMouseEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::SCROLLED, evt.x, evt.y, evt.button);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		
		void evtTouchCancelHandler(ofTouchEventArgs& evt) {}
		void evtTouchDoubleTapHandler(ofTouchEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::DOUBLE_TAP, evt.x, evt.y, evt.id, evt.pressure);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtTouchDownHandler(ofTouchEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::DOWN, evt.x, evt.y, evt.id, evt.pressure);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtTouchMoveHandler(ofTouchEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::MOVE, evt.x, evt.y, evt.id, evt.pressure);
			Dispatcher.dispatchEvent(aEvt);
		}
		
		void evtTouchUpHandler(ofTouchEventArgs& evt) {
			ActionEvent aEvt = ActionEvent(ActionEvent::UP, evt.x, evt.y, evt.id, evt.pressure);
			Dispatcher.dispatchEvent(aEvt);
		}
		
	};
	
}
