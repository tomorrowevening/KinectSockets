//
//  ApolloVec3.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloVec3.h"

namespace Apollo {
    
    Vec3 Vec3::range(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float per) {
		return Vec3(Apollo::lerp(per, minX, maxX), Apollo::lerp(per, minY, maxY), Apollo::lerp(per, minZ, maxZ));
	}
	
	Vec3 Vec3::randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
		return Vec3(Apollo::randomRange(minX, maxX), Apollo::randomRange(minY, maxY), Apollo::randomRange(minZ, maxZ));
	}
	
	Vec3 Vec3::random(float maxX, float maxY, float maxZ) {
		return Vec3(Apollo::random(maxX), Apollo::random(maxY), Apollo::random(maxZ));
	}
	
#pragma mark Operators
	
	bool Vec3::operator==( const Vec3& vec ) const { return vec.x == x && vec.y == y && vec.z == z; }
	bool Vec3::operator!=( const Vec3& vec ) const { return vec.x != x || vec.y != y || vec.z != z; }
	
	Vec3 Vec3::operator+( const Vec3& vec ) const {
		return Vec3( x+vec.x, y+vec.y, z+vec.z);
	}
	
	Vec3& Vec3::operator+=( const Vec3& vec ) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	
	Vec3 Vec3::operator-( const Vec3& vec ) const {
		return Vec3(x-vec.x, y-vec.y, z-vec.z);
	}
	
	Vec3& Vec3::operator-=( const Vec3& vec ) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}
	
	Vec3 Vec3::operator*( const Vec3& vec ) const {
		return Vec3(x*vec.x, y*vec.y, z*vec.z);
	}
	
	Vec3& Vec3::operator*=( const Vec3& vec ) {
		x*=vec.x;
		y*=vec.y;
		z*=vec.z;
		return *this;
	}
	
	Vec3 Vec3::operator/( const Vec3& vec ) const {
		return Vec3( vec.x!=0 ? x/vec.x : x, vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z);
	}
	
	Vec3& Vec3::operator/=( const Vec3& vec ) {
		vec.x!=0 ? x/=vec.x : x;
		vec.y!=0 ? y/=vec.y : y;
		vec.z!=0 ? z/=vec.z : z;
		return *this;
	}
	
	Vec3 Vec3::operator+( const float f ) const {
		return Vec3(x+f, y+f, z+f);
	}
	
	Vec3& Vec3::operator+=( const float f ) {
		x += f;
		y += f;
		z += f;
		return *this;
	}
	
	Vec3 Vec3::operator-( const float f ) const {
		return Vec3( x-f, y-f, z-f);
	}
	
	Vec3& Vec3::operator-=( const float f ) {
		x -= f;
		y -= f;
		z -= f;
		return *this;
	}
	
	Vec3 Vec3::operator-() const {
		return Vec3(-x, -y, -z);
	}
	
	Vec3 Vec3::operator*( const float f ) const {
		return Vec3(x*f, y*f, z*f);
	}
	
	Vec3& Vec3::operator*=( const float f ) {
		x*=f;
		y*=f;
		z*=f;
		return *this;
	}
	
	Vec3 Vec3::operator/( const float f ) const {
		if(f == 0) return Vec3(x, y);
		return Vec3(x/f, y/f, z/f);
	}
	
	Vec3& Vec3::operator/=( const float f ) {
		if(f == 0) return *this;
		x/=f;
		y/=f;
		z/=f;
		return *this;
	}
	
	// Non-instance methods
	
	Vec3 operator+( float f, const Vec3& vec ) {
		return Vec3( f+vec.x, f+vec.y, f+vec.z);
	}
	
	Vec3 operator-( float f, const Vec3& vec ) {
		return Vec3( f-vec.x, f-vec.y, f-vec.z);
	}
	
	Vec3 operator*( float f, const Vec3& vec ) {
		return Vec3( f*vec.x, f-vec.y, f-vec.z);
	}
	
	Vec3 operator/( float f, const Vec3& vec ) {
		return Vec3( f/vec.x, f/vec.y, f/vec.z);
	}
    
}
