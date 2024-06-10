//
//  ApolloParticleController.cpp
//  Apollo
//
//  Created by Colin Duffy on 8/11/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloParticleController.h"

namespace Apollo {
	
	ParticleController::ParticleController() {
		time = 1.f;
		gravity = 0.8f;
	}
	
	ParticleController::~ParticleController() {
		particles.clear();
	}
	
	void ParticleController::update() {
		int _total = total();
		for(int i = 0; i < _total; ++i) {
			particles[i].update(time, -gravity);
		}
	}
	
	void ParticleController::removeDeadParticles() {
		for(int i = 0; i < particles.size(); ++i) {
			if(particles[i].dead()) {
				// Remove
				particles.erase( particles.begin() + i );
				--i;
			}
		}
	}
	
	void ParticleController::addParticle(Vec3 pos, Vec3 vel) {
		addParticle(toString(total()), pos, vel);
	}
	
	void ParticleController::addParticle(string pID, Vec3 pos, Vec3 vel) {
		Particle p = Particle(pos, vel);
		p.identifer = pID;
		particles.push_back( p );
	}
	
	void ParticleController::magnet(Vec3 pos, float strength, float radius) {
		const bool checkD = radius > 0;
		int i, _total = total();
		for(i = 0; i < _total; ++i) {
			Particle p = particles[i];
			float distance = p.pos.distanceTo(pos);
			float effect = 1.f;
			if(checkD) {
				if(distance < radius) {
					effect = (1.f - (distance / radius)) * strength;
				} else {
					effect = 0;
				}
			}
//			float angle = p.pos.
		}
	}
	
}
