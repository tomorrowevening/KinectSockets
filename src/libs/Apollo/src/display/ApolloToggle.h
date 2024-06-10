//
//  ApolloButton.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloButton.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	class Toggle : public Button {
	public:
		
		static int toggleIndex;
		static string TOGGLE;
		
		Toggle();
		virtual ~Toggle();
		
		virtual void select();
		virtual void deselect();
		virtual void toggle();
		
		virtual void evtHandler(Event *evt);
		
		// Getters
		
		const bool selected() {
			return _selected;
		}
		
		// Setters
		
		void selected(bool value) {
			value ? select() : deselect();
		}
		
	protected:
		
		bool _selected;
		virtual void render();
		
	};
}
