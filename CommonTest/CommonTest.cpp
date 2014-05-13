// CommonTest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cmath>

#include "stdafx.h"
#include "../common/4D/Matrix4.h"
#include "../common/4D/Vector4.h"

using namespace Common;
int _tmain(int argc, _TCHAR* argv[])
{
	Vector4 x(sqrt(2), sqrt(2), 0, 0);
	Vector4 y(-sqrt(2), sqrt(2), 0, 0);
	Vector4 z(0, 0, 0, 0);
	Vector4 b(sqrt(2), sqrt(2), 0, 1);
	x.normalize();
	y.normalize();
	z.normalize();
	Matrix4 trans(x, y, z, Vector4(0, 0, 0, 1));
	Vector4 transformed = trans.multiply(b);
	trans.print();
	transformed.print();

	system("pause");
}

