//
//  ApolloGLDraw.h
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloGL.h"
#include "ApolloColor.h"
#include "ApolloVec2.h"
#include "ApolloVec3.h"

namespace Apollo {
	
	void fill();
	void noFill();
	
	void enableAlpha();
	void enableDepth();
	void enableSmooth();
	void disableAlpha();
	void disableDepth();
	void disableSmooth();
	
	void pushMatrix();
	void popMatrix();
	
	void rotateX(float degrees);
	void rotateY(float degrees);
	void rotateZ(float degrees);
	void rotate(Vec3 value);
	void scale(float x, float y, float z = 1.f);
	void scale(Vec3 value);
	void translate(float x, float y, float z = 0);
	void translate(Vec3 value);
	void setLineWidth(float wid);
	
	// Draw
	void drawLine(float x1, float y1, float x2, float y2);
	void drawLine(float x1, float y1, float z1, float x2, float y2, float z2);
	void drawRect(float x, float y, float wid, float hei);
	void drawRect(float x, float y, float z, float wid, float hei);
	void drawCircle(float x, float y, float radius);
	void drawCircle(float x, float y, float z, float radius);
	void drawText(string txt, float x, float y);
	
	// Color
	void setColor(float r, float g, float b, float a = 255.f);
	void setColor(float brightness, float alpha = 255.f);
	void setColorGL(float r, float g, float b, float a = 1.f);
	void setColorGL(float brightness, float alpha = 1.f);
	void setColor(Color color);
	
}
