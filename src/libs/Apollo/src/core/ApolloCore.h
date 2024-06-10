//
//  ApolloCore.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once

// Common
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <float.h>
#include <cstdio>

// Array extensions
#include <list>
#include <map>
#include <vector>
#include <iterator>

#if defined(_WIN64) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32)
    #define APOLLO_MSW
#elif defined(linux) || defined(__linux) || defined(__linux__)
    #define APOLLO_LINUX
#elif __APPLE__
    #include "TargetConditionals.h"
    #define APOLLO_COCOA
    #if TARGET_OS_IPHONE
        #define APOLLO_COCOA_TOUCH
        #define APOLLO_GLES
        #if TARGET_IPHONE_SIMULATOR
            #define APOLLO_COCOA_TOUCH_SIMULATOR
        #else
            #define APOLLO_COCOA_TOUCH_DEVICE
        #endif
    #else
        #define APOLLO_MAC
    #endif
#elif defined (ANDROID)
    #define APOLLO_ANDROID
    #define APOLLO_GLES
#endif

namespace Apollo {}

using namespace std;
using std::list;
using std::map;
using std::string;
using std::vector;
using std::iterator;

#ifdef APOLLO_OPENFRAMEWORKS
#include "ofMain.h"
#endif

// Possible macros
// APOLLO_MSW
// APOLLO_LINUX
// APOLLO_GLES
// APOLLO_COCOA
// APOLLO_COCOA_TOUCH
// APOLLO_COCOA_TOUCH_SIMULATOR
// APOLLO_COCOA_TOUCH_DEVICE
// APOLLO_MAC
// APOLLO_ANDROID
