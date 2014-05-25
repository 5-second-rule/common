#pragma once

#include <cmath>
#include <random>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>
#include <algorithm>

#include "../Matrix4.h"

using namespace std;
namespace Common{
	//a few useful constants
	const int     MaxInt = (std::numeric_limits<int>::max)();
	const double  MaxDouble = (std::numeric_limits<double>::max)();
	const double  MinDouble = (std::numeric_limits<double>::min)();
	const float   MaxFloat = (std::numeric_limits<float>::max)();
	const float   MinFloat = (std::numeric_limits<float>::min)();

	const double   Pi = 3.14159;
	const double   TwoPi = Pi * 2;
	const double   HalfPi = Pi / 2;
	const double   QuarterPi = Pi / 4;

	// Returns a random double between zero and 1
	inline double randFloat() {
		static std::default_random_engine generator;
		static std::uniform_real_distribution<double> distribution(0.0, 1.0);
		return distribution(generator);
	}

	
	// Returns an integer in the interval [a, b]
	inline bool randInt(int a, int b) {
		static std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(a, b);
		return distribution(generator);
	}

	// Returns a bool
	inline bool randBool() {
		return randInt(0, 100) < 50 ? true : false;
	}

	// Returns a random double in the range -1 < n < 1
	inline double randomClamped() {
		return randFloat() - randFloat();
	}



	inline float distanceSquared(const Vector4 &u, const Vector4 &v){
		return (u - v).lengthSquared();
	}

	inline float distance(const Vector4 &u, const Vector4 &v){
		return (u - v).length();
	}

	inline string toString(int a){
		stringstream buffer;
		buffer << a;
		return buffer.str();
	}

	inline string toString(float f){
		stringstream buffer;
		buffer << f;
		return buffer.str();
	}

	inline float toFloat(string f){
		stringstream buffer;
		float tmp;
		buffer << f;
		buffer >> tmp;
		return tmp;
	}

	inline bool toBool(string b){
		if (b == "true")
			return true;
		else
			return false;
	}

	inline char toLowerChar(char c){
		if (c >= 'A' && c <= 'Z'){
			return c - 'A' + 'a';
		}
		return c;
	}

	inline string toLower(string str){
		transform(str.begin(), str.end(), str.begin(), toLowerChar);
		return str;
	}

}