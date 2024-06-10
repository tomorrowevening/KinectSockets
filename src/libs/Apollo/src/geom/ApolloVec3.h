//
//  ApolloVec3.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloMath.h"
#include "ApolloVec2.h"

namespace Apollo {
    
    class Vec3 {
	public:
		
		float x, y, z;
		Vec3(float _x = 0, float _y = 0, float _z = 0){
			x = _x; y = _y; z = _z;
		}
		Vec3(const Vec3& v){ x = v.x; y = v.y; z = v.z; }
		Vec3(const Vec2& v);
		
		virtual void normalize() {
			float delim = 1.0f / length();
			x *= delim;
			y *= delim;
			z *= delim;
		}
		
		// Getters
		virtual float angle(Vec3 other) { return getAngleRad(x, y, other.x, other.y); }
		virtual float distanceTo(float ox, float oy, float oz) { return Apollo::distance(x, y, z, ox, oy, oz); }
		virtual float distanceTo(const Vec3& other) { return Apollo::distance(x, y, z, other.x, other.y, other.z); }
		virtual float length() { return sqrt(x*x + y*y + z*z); }
		virtual Vec3 difference(Vec3 other) { return Vec3(x-other.x, y-other.y, z-other.z); }
		static Vec3 range(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float per);
		static Vec3 randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
		static Vec3 random(float maxX, float maxY, float maxZ);
		
		// Setters
		virtual void set(float _x, float _y, float _z){ x = _x; y = _y; z = _z; }
		virtual void set(const Vec3& v){ x = v.x; y = v.y; z = v.z; }
		
		// Operators
		bool operator==( const Vec3& vec ) const;
		bool operator!=( const Vec3& vec ) const;
		Vec3  operator+( const Vec3& vec ) const;
		Vec3& operator+=( const Vec3& vec );
		Vec3  operator-( const Vec3& vec ) const;
		Vec3& operator-=( const Vec3& vec );
		Vec3  operator*( const Vec3& vec ) const;
		Vec3& operator*=( const Vec3& vec );
		Vec3  operator/( const Vec3& vec ) const;
		Vec3& operator/=( const Vec3& vec );
		
		Vec3  operator+( const float f ) const;
		Vec3& operator+=( const float f );
		Vec3  operator-( const float f ) const;
		Vec3& operator-=( const float f );
		Vec3  operator-() const;
		Vec3  operator*( const float f ) const;
		Vec3& operator*=( const float f );
		Vec3  operator/( const float f ) const;
		Vec3& operator/=( const float f );
	};
	
	Vec3 operator+( float f, const Vec3& vec );
	Vec3 operator-( float f, const Vec3& vec );
	Vec3 operator*( float f, const Vec3& vec );
	Vec3 operator/( float f, const Vec3& vec );
	
	inline Vec3::Vec3( const Vec2 &v):x(v.x), y(v.y), z(0) {}
    
}
