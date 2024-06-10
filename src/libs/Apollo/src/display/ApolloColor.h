//
//  ApolloColor.h
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once

namespace Apollo {
	
	class Color {
	public:
		
		float r, g, b, a;
		
		Color(float r = 0, float g = 0, float b = 0, float a = 255.f) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
		
		void set(float r, float g, float b, float a = -1) {
			this->r = r;
			this->g = g;
			this->b = b;
			if(a > -1) this->a = a;
		}
		
		Color gl() { return Color(r/255.f, g/255.f, b/255.f, a/255.f); }
		
		// Getters
		
		const float redGL()   { return r / 255.f; }
		const float greenGL() { return g / 255.f; }
		const float blueGL()  { return b / 255.f; }
		const float alphaGL() { return a / 255.f; }
		
		// Static colors
		
		static Color black()  { return Color(0, 0, 0); }
		static Color grey()   { return Color(128, 128, 128); }
		static Color white()  { return Color(255, 255, 255); }
		
		static Color red()    { return Color(255, 0, 0); }
		static Color green()  { return Color(0, 255, 0); }
		static Color blue()   { return Color(0, 0, 255); }
		
		static Color orange() { return Color(255, 128, 0); }
		static Color yellow() { return Color(255, 255, 0); }
		static Color pink()   { return Color(255, 0, 255); }
		
	};
}
