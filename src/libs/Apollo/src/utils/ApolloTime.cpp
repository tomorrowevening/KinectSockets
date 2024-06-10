//
//  ApolloTime.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloTime.h"

namespace Apollo {
    
    double getElapsedMS(double from) {
		return getSystemMS() - (from != -1 ? from : startTime);
	}
	
	double getSystemMS() {
		return (double)getSystemTime();
	}
	
	unsigned long long getSystemTime() {
#ifndef APOLLO_MSW
		struct timeval now;
		gettimeofday( &now, NULL );
		return (unsigned long long) now.tv_usec/1000 + (unsigned long long) now.tv_sec*1000;
#else
		return timeGetTime();
#endif
	}
    
}
