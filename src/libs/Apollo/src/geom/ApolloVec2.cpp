//
//  ApolloVec2.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloVec2.h"
#include "ApolloVec3.h"

namespace Apollo {
    
    Vec2::Vec2(const Vec3& v) {
		x = v.x;
		y = v.y;
	}
	
	Vec2 Vec2::range(float minX, float maxX, float minY, float maxY, float per) {
		return Vec2(Apollo::lerp(per, minX, maxX), Apollo::lerp(per, minY, maxY));
	}
	
	Vec2 Vec2::randomRange(float minX, float maxX, float minY, float maxY) {
		return Vec2(Apollo::randomRange(minX, maxX), Apollo::randomRange(minY, maxY));
	}
	
	Vec2 Vec2::random(float maxX, float maxY) {
		return Vec2(Apollo::random(maxX), Apollo::random(maxY));
	}
	
#pragma mark Operators
    
	bool Vec2::operator==( const Vec2& vec ) const { return vec.x == x && vec.y == y; }
	bool Vec2::operator!=( const Vec2& vec ) const { return vec.x != x || vec.y != y; }
    
	Vec2 Vec2::operator+( const Vec2& vec ) const {
		return Vec2( x+vec.x, y+vec.y);
	}
    
	Vec2& Vec2::operator+=( const Vec2& vec ) {
		x += vec.x;
		y += vec.y;
		return *this;
	}
    
	Vec2 Vec2::operator-( const Vec2& vec ) const {
		return Vec2(x-vec.x, y-vec.y);
	}
    
	Vec2& Vec2::operator-=( const Vec2& vec ) {
		x -= vec.x;
		y -= vec.y;
		return *this;
	}
    
	Vec2 Vec2::operator*( const Vec2& vec ) const {
		return Vec2(x*vec.x, y*vec.y);
	}
    
	Vec2& Vec2::operator*=( const Vec2& vec ) {
		x*=vec.x;
		y*=vec.y;
		return *this;
	}
    
	Vec2 Vec2::operator/( const Vec2& vec ) const {
		return Vec2( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y);
	}
    
	Vec2& Vec2::operator/=( const Vec2& vec ) {
		vec.x!=0 ? x/=vec.x : x;
		vec.y!=0 ? y/=vec.y : y;
		return *this;
	}
    
	Vec2 Vec2::operator+( const float f ) const {
		return Vec2( x+f, y+f);
	}
    
	Vec2& Vec2::operator+=( const float f ) {
		x += f;
		y += f;
		return *this;
	}
    
	Vec2 Vec2::operator-( const float f ) const {
		return Vec2( x-f, y-f);
	}
    
	Vec2& Vec2::operator-=( const float f ) {
		x -= f;
		y -= f;
		return *this;
	}
    
	Vec2 Vec2::operator-() const {
		return Vec2(-x, -y);
	}
    
	Vec2 Vec2::operator*( const float f ) const {
		return Vec2(x*f, y*f);
	}
    
	Vec2& Vec2::operator*=( const float f ) {
		x*=f;
		y*=f;
		return *this;
	}
    
	Vec2 Vec2::operator/( const float f ) const {
		if(f == 0) return Vec2(x, y);
		
		return Vec2(x/f, y/f);
	}
    
	Vec2& Vec2::operator/=( const float f ) {
		if(f == 0) return *this;
		
		x/=f;
		y/=f;
		return *this;
	}
	
	// Non-instance methods
	
	Vec2 operator+( float f, const Vec2& vec ) {
		return Vec2( f+vec.x, f+vec.y);
	}
	
	Vec2 operator-( float f, const Vec2& vec ) {
		return Vec2( f-vec.x, f-vec.y);
	}
	
	Vec2 operator*( float f, const Vec2& vec ) {
		return Vec2( f*vec.x, f*vec.y);
	}
	
	Vec2 operator/( float f, const Vec2& vec ) {
		return Vec2( f/vec.x, f/vec.y);
	}
    
}
