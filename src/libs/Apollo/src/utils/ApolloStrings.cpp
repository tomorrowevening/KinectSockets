//
//  ApolloStrings.cpp
//  Apollo
//
//  Created by Colin Duffy on 7/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloStrings.h"

namespace Apollo {
    
    template <class T>
	string toString(const T& value) {
		ostringstream out;
		out << value;
		return out.str();
	}
	
	template<class T>
	string toString(const vector<T>& values) {
		stringstream out;
		int n = values.size();
		out << "{";
		if(n > 0) {
			for(int i = 0; i < n - 1; i++) {
				out << values[i] << ", ";
			}
			out << values[n - 1];
		}
		out << "}";
		return out.str();
	}
    
	int hexToInt(string hexValue) {
		unsigned int x;
		std::stringstream ss;
		ss << std::hex << hexValue;
		ss >> x;
		return x;
	}
	
	string formatDigits(int num, int totalDigits, string prefix, string suffix) {
		int i, n;
		int hundreds = 1;
		string result = "";
		for(i = 0; i <= totalDigits; ++i) {
			hundreds *= 10;
			if(num < hundreds) {
				for(n = i; n < totalDigits-1; ++n) {
					result += "0";
				}
				result += toString(num);
				break;
			}
		}
		
		return prefix + result + suffix;
	}
	
	string fileType(string path) {
		return path.substr(path.find_last_of(".")+1);
	}
	
	vector<string> split(string &text, char delim) {
		vector<string> items;
		
		std::stringstream ss(text);
		std::string item;
		while (std::getline(ss, item, delim)) {
			items.push_back(item);
		}
		
		return items;
	}
    
}
