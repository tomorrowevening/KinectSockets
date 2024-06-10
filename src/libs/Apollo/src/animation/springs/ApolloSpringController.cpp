//
//  ApolloSpringController.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloSpringController.h"

namespace Apollo {
	
	SpringController Springy;
	
	SpringController::SpringController() {
		
	}
	
	SpringController::~SpringController() {
		springs.clear();
		vSprings.clear();
	}
	
	void SpringController::update() {
		int i;
		for(i = 0; i < springs.size(); ++i) {
			springs[i].update();
			if( springs[i].complete() ) {
				springs.erase( springs.begin() + i );
				--i;
			}
		}
		
		for(i = 0; i < vSprings.size(); ++i) {
			vSprings[i].update();
			if( vSprings[i].complete() ) {
				vSprings.erase( vSprings.begin() + i );
				--i;
			}
		}
	}
	
	void SpringController::draw() {
		for(int i = 0; i < vSprings.size(); ++i) {
			vSprings[i].draw();
		}
		
		//
		string total = toString( (int)vSprings.size() );
		Apollo::setColor(0);
		Apollo::drawRect(0, 0, 200, 30);
		Apollo::setColor(255);
		Apollo::drawText(total, 15, 15);
	}
	
	void SpringController::to(float *item, float target, float friction, float mass, float spring) {
		int i, total = springs.size();
		for(i = 0; i < total; ++i) {
			if(item == springs[i].pointer) {
				springs[i].friction	= friction;
				springs[i].mass		= mass;
				springs[i].bounce	= spring;
				springs[i].target	= target;
				springs[i].value	= item[0];
				return;
			}
		}
		
		Spring ani;
		ani.friction	= friction;
		ani.mass		= mass;
		ani.bounce		= spring;
		ani.target		= target;
		ani.value		= item[0];
		ani.pointer		= item;
		springs.push_back( ani );
	}
	
	void SpringController::to(Vec3 *item, Vec3 target, float friction, float mass, float spring) {
		int i, total = vSprings.size();
		for(i = 0; i < total; ++i) {
			if(item == vSprings[i].pointer) {
				vSprings[i].friction	= friction;
				vSprings[i].mass		= mass;
				vSprings[i].bounce		= spring;
				vSprings[i].target		= target;
				vSprings[i].value		= item[0];
				return;
			}
		}
		
		SpringVec ani;
		ani.friction	= friction;
		ani.mass		= mass;
		ani.bounce		= spring;
		ani.target		= target;
		ani.value		= item[0];
		ani.pointer		= item;
		vSprings.push_back( ani );
	}
	
	void SpringController::removeAllSprings() {
		int i = vSprings.size()-1;
		for(i; i > -1; --i) {
			vSprings.erase( vSprings.begin() + i );
		}
		vSprings.clear();
	}
	
}
