//
//  ApolloGLDraw.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloGLDraw.h"

#ifdef APOLLO_OPENFRAMEWORKS
#include "ofMain.h"
#endif

namespace Apollo {
	
	void fill() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofFill();
#endif
	}
	void noFill() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofNoFill();
#endif
	}
	
	void enableAlpha() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofEnableAlphaBlending();
#endif
	}
	void enableDepth() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofEnableDepthTest();
#endif
	}
	void enableSmooth() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofEnableSmoothing();
#endif
	}
	void disableAlpha() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofDisableAlphaBlending();
#endif
	}
	void disableDepth() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofDisableDepthTest();
#endif
	}
	void disableSmooth() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofDisableSmoothing();
#endif
	}
	
	void pushMatrix() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofPushMatrix();
#endif
	}
	void popMatrix() {
#ifdef APOLLO_OPENFRAMEWORKS
		ofPopMatrix();
#endif
	}
	
	void rotateX(float degrees) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofRotateX(degrees);
#endif
	}
	void rotateY(float degrees) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofRotateY(degrees);
#endif
	}
	void rotateZ(float degrees) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofRotateZ(degrees);
#endif
	}
	void rotate(Vec3 value) {
		rotateX(value.x);
		rotateY(value.y);
		rotateZ(value.z);
	}
	void scale(float x, float y, float z) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofScale(x, y, z);
#endif
	}
	void scale(Vec3 value) {
		scale(value.x, value.y, value.z);
	}
	void translate(float x, float y, float z) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofTranslate(x, y, z);
#endif
	}
	void translate(Vec3 value) {
		translate(value.x, value.y, value.z);
	}
	void setLineWidth(float wid) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofSetLineWidth(wid);
#endif
	}
	
#pragma mark - Drawing
	
	void drawLine(float x1, float y1, float x2, float y2) { drawLine(x1, y1, 0, x2, y2, 0); }
	void drawLine(float x1, float y1, float z1, float x2, float y2, float z2) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofLine(x1, y1, z1, x2, y2, z2);
#endif
	}
	void drawRect(float x, float y, float wid, float hei) { drawRect(x, y, 0, wid, hei); }
	void drawRect(float x, float y, float z, float wid, float hei) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofRect(x, y, wid, hei);
#endif
	}
	void drawCircle(float x, float y, float radius) { drawCircle(x, y, radius, radius); }
	void drawCircle(float x, float y, float width, float height) {
#ifdef APOLLO_OPENFRAMEWORKS
		const float wRadius = width  * 0.5f,
		hRadius = height * 0.5f;
		ofEllipse(x+wRadius, y+hRadius, 0, width, height);
#endif
	}
	void drawText(string txt, float x, float y) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofDrawBitmapString(txt, x, y);
#endif
	}
	
#pragma mark - Color
	
	void setColor(float r, float g, float b, float a) {
#ifdef APOLLO_OPENFRAMEWORKS
		ofSetColor(r, g, b, a);
#endif
	}
	void setColor(float brightness, float alpha) { setColor(brightness, brightness, brightness, alpha); }
	void setColorGL(float r, float g, float b, float a) {
		const float gl = 255.f;
		setColor(r*gl, g*gl, b*gl, a*gl);
	}
	void setColorGL(float brightness, float alpha) { setColorGL(brightness, brightness, brightness, alpha); }
	void setColor(Color color) { setColor(color.r, color.g, color.b, color.a); }
	
}
