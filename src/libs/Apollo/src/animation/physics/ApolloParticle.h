//
//  ApolloParticle.h
//  Apollo
//
//  Created by Colin Duffy on 8/11/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloVec3.h"
#include "ApolloMath.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"
#include "ApolloStrings.h"

namespace Apollo {
	
#ifndef PARTICLE_HISTORY_LENGTH
	#define PARTICLE_HISTORY_LENGTH				20
	#define PARTICLE_INTERPOLATION_PRECISION	0.01
#endif
	
	class Particle : public EventDispatcher {
	public:
		
		static int		totalParticles;
		
		float			friction;
		Vec3			acc, pos, vel;
		vector<Vec3>	history;
		string			identifer;
		
		Particle(float x = 0, float y = 0, float z = 0, float vx = 0, float vy = 0, float vz = 0);
		Particle(Vec3 pos = Vec3(), Vec3 vel = Vec3());
		
		virtual void update(float time = 1.f, float gravity = 0.f);
		
		const bool dead() {
			return (acc.length() + vel.length()) < PARTICLE_INTERPOLATION_PRECISION;
		}
		
	};
	
}
