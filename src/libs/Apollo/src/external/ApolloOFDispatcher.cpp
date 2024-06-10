//
//  ApolloOFDispatcher.cpp
//  Apollo
//
//  Created by Colin Duffy on 8/12/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloOFDispatcher.h"

namespace Apollo {
	
	void OFDispatcher::enable() {
		ofAddListener(ofEvents().update, this, &OFDispatcher::evtUpdateHandler);
		ofAddListener(ofEvents().draw, this, &OFDispatcher::evtDrawHandler);
		
#ifdef APOLLO_COCOA_TOUCH
		ofAddListener(ofEvents().touchCancelled, this, &OFDispatcher::evtTouchCancelHandler);
		ofAddListener(ofEvents().touchDoubleTap, this, &OFDispatcher::evtTouchDoubleTapHandler);
		ofAddListener(ofEvents().touchDown, this, &OFDispatcher::evtTouchDownHandler);
		ofAddListener(ofEvents().touchMoved, this, &OFDispatcher::evtTouchMoveHandler);
		ofAddListener(ofEvents().touchUp, this, &OFDispatcher::evtTouchUpHandler);
#else
		ofAddListener(ofEvents().keyPressed, this, &OFDispatcher::evtKeyDownHandler);
		ofAddListener(ofEvents().keyReleased, this, &OFDispatcher::evtKeyUpHandler);
		
		ofAddListener(ofEvents().mouseDragged, this, &OFDispatcher::evtMouseDraggedHandler);
		ofAddListener(ofEvents().mouseMoved, this, &OFDispatcher::evtMouseMovedHandler);
		ofAddListener(ofEvents().mousePressed, this, &OFDispatcher::evtMousePressedHandler);
		ofAddListener(ofEvents().mouseReleased, this, &OFDispatcher::evtMouseReleasedHandler);
#endif
	}
	
	void OFDispatcher::disable() {
		ofRemoveListener(ofEvents().update, this, &OFDispatcher::evtUpdateHandler);
		ofRemoveListener(ofEvents().draw, this, &OFDispatcher::evtDrawHandler);
		
#ifdef APOLLO_COCOA_TOUCH
		ofRemoveListener(ofEvents().touchCancelled, this, &OFDispatcher::evtTouchCancelHandler);
		ofRemoveListener(ofEvents().touchDoubleTap, this, &OFDispatcher::evtTouchDoubleTapHandler);
		ofRemoveListener(ofEvents().touchDown, this, &OFDispatcher::evtTouchDownHandler);
		ofRemoveListener(ofEvents().touchMoved, this, &OFDispatcher::evtTouchMoveHandler);
		ofRemoveListener(ofEvents().touchUp, this, &OFDispatcher::evtTouchUpHandler);
#else
		ofRemoveListener(ofEvents().keyPressed, this, &OFDispatcher::evtKeyDownHandler);
		ofRemoveListener(ofEvents().keyReleased, this, &OFDispatcher::evtKeyUpHandler);
		
		ofRemoveListener(ofEvents().mouseDragged, this, &OFDispatcher::evtMouseDraggedHandler);
		ofRemoveListener(ofEvents().mouseMoved, this, &OFDispatcher::evtMouseMovedHandler);
		ofRemoveListener(ofEvents().mousePressed, this, &OFDispatcher::evtMousePressedHandler);
		ofRemoveListener(ofEvents().mouseReleased, this, &OFDispatcher::evtMouseReleasedHandler);
#endif
	}
	
}
