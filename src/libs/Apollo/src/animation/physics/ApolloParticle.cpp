//
//  ApolloParticle.cpp
//  Apollo
//
//  Created by Colin Duffy on 8/11/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloParticle.h"

namespace Apollo {
	
	int Particle::totalParticles = 0;
	
	Particle::Particle(float x, float y, float z, float vx, float vy, float vz) {
		pos.set(x, y, z);
		acc.set(vx, vy, vz);
//		friction = 0.7f;
		friction = randomRange(0.4f, 0.8f);
		identifer = "Particle:" + toString(totalParticles);
		++totalParticles;
	}
	
	Particle::Particle(Vec3 pos, Vec3 vel) {
		this->pos = pos;
		this->vel = vel;
//		friction = 0.7f;
		friction = randomRange(0.4f, 0.8f);
		identifer = "Particle:" + toString(totalParticles);
		++totalParticles;
	}
	
	void Particle::update(float time, float gravity) {
		// Add history
#if PARTICLE_HISTORY_LENGTH > 0
		history.insert( history.begin(), pos );
		if(history.size() > PARTICLE_INTERPOLATION_PRECISION) history.pop_back();
#endif
		
		// Velocity
		vel.x +=  acc.x * time;
		vel.y += (acc.y + gravity) * time;
		vel.z +=  acc.z * time;
		
		// Update pos
		pos += vel * time;
		
		// Apply friction
		acc = -vel * friction;
		
		// Update listeners
		if( totalHandlers() > 0 ) {
			AnimationEvent aEvt = AnimationEvent(AnimationEvent::ON_UPDATE, identifer);
			dispatchEvent( aEvt );
			if(dead()) {
				aEvt = AnimationEvent(AnimationEvent::ON_COMPLETE, identifer);
				dispatchEvent( aEvt );
			}
		}
	}
	
}
