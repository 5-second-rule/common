#pragma once
//------------------------------------------------------------------------
//
//  Name: utils.h
//
//  Desc: misc utility functions and constants
//
//  Author: Mat Buckland (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <cmath>
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

	//returns true if the parameter is equal to zero
	inline bool isZero(double val)
	{
		return ((-MinDouble < val) && (val < MinDouble));
	}

	//----------------------------------------------------------------------------
	//  some random number functions.
	//----------------------------------------------------------------------------

	//returns a random integer between x and y
	inline int   randInt(int x, int y)
	{
		assert(y >= x && "<RandInt>: y is less than x");
		return rand() % (y - x + 1) + x;
	}

	//returns a random double between zero and 1
	inline double randFloat()      { return ((rand()) / (RAND_MAX + 1.0)); }

	inline double randInRange(double x, double y)
	{
		return x + randFloat()*(y - x);
	}

	//returns a random bool
	inline bool   randBool()
	{
		if (randFloat() > 0.5) return true;

		else return false;
	}

	//returns a random double in the range -1 < n < 1
	inline double randomClamped()    { return randFloat() - randFloat(); }


	//returns a random number with a normal distribution. See method at
	//http://www.taygeta.com/random/gaussian.html
	inline double RandGaussian(double mean = 0.0, double standard_deviation = 1.0)
	{
		double x1, x2, w, y1;
		static double y2;
		static int use_last = 0;

		if (use_last)		        /* use value from previous call */
		{
			y1 = y2;
			use_last = 0;
		}
		else
		{
			do
			{
				x1 = 2.0 * randFloat() - 1.0;
				x2 = 2.0 * randFloat() - 1.0;
				w = x1 * x1 + x2 * x2;
			} while (w >= 1.0);

			w = sqrt((-2.0 * log(w)) / w);
			y1 = x1 * w;
			y2 = x2 * w;
			use_last = 1;
		}

		return(mean + y1 * standard_deviation);
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