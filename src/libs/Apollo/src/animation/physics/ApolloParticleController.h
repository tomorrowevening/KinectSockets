//
//  ApolloParticleController.h
//  Apollo
//
//  Created by Colin Duffy on 8/11/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloParticle.h"

namespace Apollo {
	
	class ParticleController {
	public:
		
		float time, gravity;
		vector<Particle> particles;
		
		ParticleController();
		virtual ~ParticleController();
		
		virtual void addParticle(Vec3 pos, Vec3 vel = Vec3());
		virtual void addParticle(string pID, Vec3 pos, Vec3 vel = Vec3());
		virtual void update();
		virtual void removeDeadParticles();
		
		virtual void magnet(Vec3 pos, float strength = 0.5f, float radius = 0.f);
		
		const int total() {
			return particles.size();
		}
		
	};
	
}
