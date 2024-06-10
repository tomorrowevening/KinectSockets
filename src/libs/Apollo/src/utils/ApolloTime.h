//
//  ApolloTime.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include <time.h>
#include <stdio.h>
#ifdef APOLLO_COCOA
#include <sys/time.h>
#endif

namespace Apollo {
    
    double getElapsedMS(double from = -1);
	double getSystemMS();
	unsigned long long getSystemTime();
	
	static double startTime = getSystemMS();
    
}
