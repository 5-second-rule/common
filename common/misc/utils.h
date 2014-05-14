#pragma once

#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>
#include <iomanip>

#include "../Matrix4.h"

namespace Common{

	//a few useful constants
	const int     MaxInt = (std::numeric_limits<int>::max)();
	const double  MaxDouble = (std::numeric_limits<double>::max)();
	const double  MinDouble = (std::numeric_limits<double>::min)();
	const float   MaxFloat = (std::numeric_limits<float>::max)();
	const float   MinFloat = (std::numeric_limits<float>::min)();

	const float   Pi = 3.14159f;
	const float   TwoPi = Pi * 2;

	inline double degreesToRads(double degs)
	{
		return TwoPi * (degs / 360.0);
	}

	inline bool isZero(double val)
	{
		return ((-MinDouble < val) && (val < MinDouble));
	}

	inline bool isZero(float val)
	{
		return ((-MinFloat < val) && (val < MinFloat));
	}

	//----------------------------------------------------------------------------
	//  some random number functions.
	//----------------------------------------------------------------------------

	// Returns a random integer between x and y
	inline int   RandInt(int x, int y)
	{
		assert(y >= x && "<RandInt>: y is less than x");
		return rand() % (y - x + 1) + x;
	}

	// Returns a random double between zero and 1
	inline double randFloat()      { return ((rand()) / (RAND_MAX + 1.0)); }

	// Returns a random double in the range -1 < n < 1
	inline double randomClamped()    { return randFloat() - randFloat(); }

	//-----------------------------------------------------------------------
	//  
	//  some handy little functions
	//-----------------------------------------------------------------------


	inline double Sigmoid(double input, double response = 1.0)
	{
		return (1.0 / (1.0 + exp(-input / response)));
	}


	//returns the maximum of two values
	template <class T>
	inline T MaxOf(const T& a, const T& b)
	{
		if (a > b) return a; return b;
	}

	//returns the minimum of two values
	template <class T>
	inline T MinOf(const T& a, const T& b)
	{
		if (a < b) return a; return b;
	}

	// Compares two real numbers. Returns true if they are equal
	inline bool isEqual(float a, float b)
	{
		if (fabs(a - b) < 1E-12)
		{
			return true;
		}

		return false;
	}

	inline bool isEqual(double a, double b)
	{
		if (fabs(a - b) < 1E-12)
		{
			return true;
		}

		return false;
	}

	inline Vector4 rotateAroundOrigin(const Vector4 &u, float angle){
		return Common::Matrix4::rotate(Vector4(0, 1, 0), angle) * u;
	}

	inline float distanceSquared(const Vector4 &u, const Vector4 &v){
		return (u - v).lengthSquared();
	}

	inline float distance(const Vector4 &u, const Vector4 &v){
		return (u - v).length();
	}

}