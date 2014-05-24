// CommonTest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cmath>

#include "stdafx.h"
#include "../common/Matrix4.h"
#include "../common/Vector4.h"

using namespace Common;
int _tmain(int argc, _TCHAR* argv[])
{
	float sqrt2 = (float) sqrt(2);
	Vector4 x(sqrt2, sqrt2, 0, 0);
	Vector4 y(-sqrt2, sqrt2, 0, 0);
	Vector4 z(0, 0, 0, 0);
	Vector4 b(sqrt2, sqrt2, 0, 1);
	x.normalize();
	y.normalize();
	z.normalize();
	Matrix4 trans = Matrix4::base(x, y, z, Vector4(0, 0, 0));
	Vector4 transformed = trans.multiply(b);
	trans.print();
	transformed.print();

	system("pause");
}

