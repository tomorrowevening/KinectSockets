//
//  AnimationEnum.h
//  Apollo
//  Created by Colin Duffy on 5/7/13.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloVec2.h"
#include "ApolloVec3.h"

namespace Apollo {
	
	//////////////////////////////////////////////////
	// Penner Eases
	//////////////////////////////////////////////////
	
	typedef enum {
		EaseLinear = 0,
		
		EaseCircIn,
		EaseCircInOut,
		EaseCircOut,
		
		EaseCubicIn,
		EaseCubicInOut,
		EaseCubicOut,
		
		EaseExpoIn,
		EaseExpoInOut,
		EaseExpoOut,
		
		EaseQuadIn,
		EaseQuadInOut,
		EaseQuadOut,
		
		EaseQuartIn,
		EaseQuartInOut,
		EaseQuartOut,
		
		EaseQuintIn,
		EaseQuintInOut,
		EaseQuintOut,
		
		EaseSineIn,
		EaseSineInOut,
		EaseSineOut
		
	} PennerEases;
	
	//////////////////////////////////////////////////
	// Cubic Ease
	//////////////////////////////////////////////////
	
	class CubicEase {
	public:
		
		static const int BEZIER_SEGMENTS = 12;
		
		Vec2 c0, c1;
		float curves[6];
		
		CubicEase(float x0 = 0.333f, float y0 = 0.333f, float x1 = 0.667f, float y1 = 0.667f) {
			set(x0, y0, x1, y1);
		}
		
		bool operator==( const CubicEase& cEase ) {
			return cEase.c0 == c0 && cEase.c1 == c1;
		}
		
		bool operator!=( const CubicEase& cEase ) {
			return cEase.c0 != c0 || cEase.c1 != c1;
		}
		
		//////////////////////////////////////////////////
#pragma mark - Getters
		//////////////////////////////////////////////////
		
		float getCurvePercent(float percent) {
			float dfx = curves[0];
			if (dfx ==  0)	return percent;
			if (dfx == -1)	return 0;
			
			float dfy   = curves[1];
			float ddfx  = curves[2];
			float ddfy  = curves[3];
			float dddfx = curves[4];
			float dddfy = curves[5];
			float x = dfx;
			float y = dfy;
			int i = BEZIER_SEGMENTS - 2;
			while (true) {
				if (x >= percent) {
					float lastX = x - dfx;
					float lastY = y - dfy;
					return lastY + (y - lastY) * (percent - lastX) / (x - lastX);
				}
				if (i == 0) break;
				i--;
				dfx  += ddfx;
				dfy  += ddfy;
				ddfx += dddfx;
				ddfy += dddfy;
				x += dfx;
				y += dfy;
			}
			return y + (1 - y) * (percent - x) / (1 - x);
		}
		
		static CubicEase getPenner(PennerEases ease) {
			CubicEase cEase;
			switch (ease) {
					// Circ
				case EaseCircIn:
					cEase.set(0.600, 0.040, 0.980, 0.335);		break;
				case EaseCircInOut:
					cEase.set(0.785, 0.135, 0.150, 0.860);		break;
				case EaseCircOut:
					cEase.set(0.075, 0.820, 0.165, 1.000);		break;
					
					// Cubic
				case EaseCubicIn:
					cEase.set(0.550, 0.055, 0.675, 0.190);		break;
				case EaseCubicInOut:
					cEase.set(0.645, 0.045, 0.355, 1.000);		break;
				case EaseCubicOut:
					cEase.set(0.215, 0.610, 0.355, 1.000);		break;
					
					// Expo
				case EaseExpoIn:
					cEase.set(0.950, 0.050, 0.795, 0.035);		break;
				case EaseExpoInOut:
					cEase.set(1.000, 0.000, 0.000, 1.000);		break;
				case EaseExpoOut:
					cEase.set(0.190, 1.000, 0.220, 1.000);		break;
					
					// Quad
				case EaseQuadIn:
					cEase.set(0.550, 0.085, 0.680, 0.530);		break;
				case EaseQuadInOut:
					cEase.set(0.455, 0.030, 0.515, 0.955);		break;
				case EaseQuadOut:
					cEase.set(0.250, 0.460, 0.450, 0.940);		break;
					
					// Quart
				case EaseQuartIn:
					cEase.set(0.895, 0.030, 0.685, 0.220);		break;
				case EaseQuartInOut:
					cEase.set(0.860, 0.000, 0.070, 1.000);		break;
				case EaseQuartOut:
					cEase.set(0.230, 1.000, 0.320, 1.000);		break;
					
					// Quint
				case EaseQuintIn:
					cEase.set(0.755, 0.050, 0.855, 0.060);		break;
				case EaseQuintInOut:
					cEase.set(0.770, 0.000, 0.175, 1.000);		break;
				case EaseQuintOut:
					cEase.set(0.165, 0.840, 0.440, 1.000);		break;
					
					// Sine
				case EaseSineIn:
					cEase.set(0.470, 0.000, 0.745, 0.715);		break;
				case EaseSineInOut:
					cEase.set(0.445, 0.050, 0.550, 0.950);		break;
				case EaseSineOut:
					cEase.set(0.390, 0.575, 0.565, 1.000);		break;
					
					// Linear
				case EaseLinear:
				default:
					cEase.set(0.333f, 0.333f, 0.667f, 0.667f);	break;
			}
			return cEase;
		}
		
		//////////////////////////////////////////////////
#pragma mark - Setters
		//////////////////////////////////////////////////
		
		void copy(const CubicEase& cEase) { set(cEase.c0.x, cEase.c0.y, cEase.c1.x, cEase.c1.y); }
		void set(const Vec2& e0, const Vec2& e1) { set(e0.x, e0.y, e1.x, e1.y); }
		
		void setLinear() { curves[0] =  0; }
		void setStepped(){ curves[0] = -1; }
		void setPenner(PennerEases ease) { copy(getPenner(ease)); }
		
		void set(float x0, float y0, float x1, float y1) {
			c0.set(x0, y0); c1.set(x1, y1);
			
			float subdiv_step = 1.f / (float)BEZIER_SEGMENTS;
			float subdiv_step2 = subdiv_step * subdiv_step;
			float subdiv_step3 = subdiv_step2 * subdiv_step;
			float pre1 = 3 * subdiv_step;
			float pre2 = 3 * subdiv_step2;
			float pre4 = 6 * subdiv_step2;
			float pre5 = 6 * subdiv_step3;
			float tmp1x = -c0.x * 2 + c1.x;
			float tmp1y = -c0.y * 2 + c1.y;
			float tmp2x = (c0.x - c1.x) * 3 + 1;
			float tmp2y = (c0.y - c1.y) * 3 + 1;
			
			curves[0] = c0.x * pre1 + tmp1x * pre2 + tmp2x * subdiv_step3;
			curves[1] = c0.y * pre1 + tmp1y * pre2 + tmp2y * subdiv_step3;
			curves[2] = tmp1x * pre4 + tmp2x * pre5;
			curves[3] = tmp1y * pre4 + tmp2y * pre5;
			curves[4] = tmp2x * pre5;
			curves[5] = tmp2y * pre5;
		}
		
	};
	
}
