#include "Transformation.h"

using namespace Common;
Transformation::Transformation()
{
}


Transformation::~Transformation()
{
}

Vector4 Transformation::pointToWorldSpace(const Vector4 &point,
	const Vector4 &agent_side,
	const Vector4 &agent_top,
	const Vector4 &agent_heading,
	const Vector4 &agent_position){
	Matrix4 matTransformation = Matrix4::base(agent_side, agent_top, agent_heading, agent_position);
	return matTransformation.multiply(point);
}

Vector4 Transformation::vectorToWorldSpace(const Vector4 &vec,
	const Vector4 &agent_heading,
	const Vector4 &agent_side,
	const Vector4 &agent_top)
{
	// Rotation
	Matrix4 rotationMatrix;
	rotationMatrix.setLines(agent_side, agent_top, agent_heading, Vector4(0, 0, 0, 1));
	return rotationMatrix.multiply(vec);
}

Vector4 Transformation::pointToLocalSpace(const Vector4 &point,
	const Vector4 &agent_heading,
	const Vector4 &agent_side,
	const Vector4 &agent_top,
	const Vector4 &agent_position){
	Matrix4 matTransformation = Matrix4::base(agent_side, agent_top, agent_heading, -agent_position);
	return matTransformation.multiply(point);
}

Vector4 Transformation::vectorToLocalSpace(const Vector4 &vec,
	const Vector4 &agent_heading,
	const Vector4 &agent_side,
	const Vector4 &agent_top)
{
	// Rotation
	Matrix4 rotationMatrix = Matrix4::base(agent_side, agent_top, agent_heading, Vector4(0, 0, 0));
	return rotationMatrix.multiply(vec);
}
