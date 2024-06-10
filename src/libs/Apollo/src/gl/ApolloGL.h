//
//  ApolloGL.h
//  Apollo
//
//  Created by Colin Duffy on 7/19/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"

#ifdef APOLLO_OPENFRAMEWORKS
#include "ofMain.h"
#endif

#ifdef APOLLO_CINDER
#endif

#ifdef APOLLO_MAC
#include <OpenGL/gl.h>
#endif

#ifdef APOLLO_MSW
#include <windows.h>
#include "GL\glew.h"
#include "GL\wglew.h"
#include "glu.h"
#endif

#ifdef APOLLO_LINUX
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glx.h>
#endif

#ifdef APOLLO_COCOA_TOUCH
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#endif

#ifdef APOLLO_ANDROID
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

//
#include "ApolloGLDraw.h"

