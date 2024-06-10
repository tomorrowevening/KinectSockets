//
//  ApolloStrings.h
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "ApolloCore.h"

namespace Apollo {
    
    using namespace std;
	using std::ostringstream;
	using std::stringstream;
    
    template <class T>
	string toString(const T& value);
	
	template<class T>
	string toString(const vector<T>& values);
		
	int hexToInt(string hexValue);
	
	string formatDigits(int num, int totalDigits, string prefix, string suffix);
	string fileType(string path);
	vector<string> split(string &text, char delim);
    
}
