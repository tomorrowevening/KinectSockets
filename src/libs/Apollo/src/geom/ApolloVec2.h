//
//  ApolloVec2.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloMath.h"

namespace Apollo {
    
    class Vec3;
	class Vec2 {
	public:
		
		float x, y;
		Vec2(float _x = 0, float _y = 0):x(_x), y(_y){}
		Vec2(const Vec2& v){ x = v.x; y = v.y; }
		Vec2(const Vec3& v);
		
		void normalize() {
			float delim = 1.0f / length();
			x *= delim;
			y *= delim;
		}
		
		// Getters
		float distanceTo(float ox, float oy) { return Apollo::distance(x, y, ox, oy); }
		float distanceTo(const Vec2& other)  { return Apollo::distance(x, y, other.x, other.y); }
		float length() { return sqrt(x*x + y*y); }
		static Vec2 range(float minX, float maxX, float minY, float maxY, float per);
		static Vec2 randomRange(float minX, float maxX, float minY, float maxY);
		static Vec2 random(float maxX, float maxY);
		Vec2 getNormalize() {
			Vec2 clone = Vec2();
			clone.set(x, y);
			clone.normalize();
			return clone;
		}
		
		// Setters
		void set(float _x, float _y){ x = _x; y = _y; }
		void set(const Vec2& v){ x = v.x; y = v.y; }
		
		// Operators
		bool operator==( const Vec2& vec ) const;
		bool operator!=( const Vec2& vec ) const;
		Vec2  operator+( const Vec2& vec ) const;
		Vec2& operator+=( const Vec2& vec );
		Vec2  operator-( const Vec2& vec ) const;
		Vec2& operator-=( const Vec2& vec );
		Vec2  operator*( const Vec2& vec ) const;
		Vec2& operator*=( const Vec2& vec );
		Vec2  operator/( const Vec2& vec ) const;
		Vec2& operator/=( const Vec2& vec );
		
		Vec2  operator+( const float f ) const;
		Vec2& operator+=( const float f );
		Vec2  operator-( const float f ) const;
		Vec2& operator-=( const float f );
		Vec2  operator-() const;
		Vec2  operator*( const float f ) const;
		Vec2& operator*=( const float f );
		Vec2  operator/( const float f ) const;
		Vec2& operator/=( const float f );
	};
	
	Vec2 operator+( float f, const Vec2& vec );
	Vec2 operator-( float f, const Vec2& vec );
	Vec2 operator*( float f, const Vec2& vec );
	Vec2 operator/( float f, const Vec2& vec );
    
}
