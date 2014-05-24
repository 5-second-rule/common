#pragma once
#include "../common.h"
#include "../Matrix4.h"

namespace Common{
	class COMMONDLL Transformation
	{
	public:
		Transformation();
		~Transformation();

		//--------------------- PointToWorldSpace --------------------------------
		//
		//  Transforms a point from the agent's local space into world space
		//------------------------------------------------------------------------
		static Vector4 pointToWorldSpace(const Vector4 &point,
			const Vector4 &agent_side,
			const Vector4 &agend_top,
			const Vector4 &agend_heading,
			const Vector4 &agent_position);

		//--------------------- vectorToWorldSpace --------------------------------
		//
		//  Transforms a vector from the agent's local space into world space
		//------------------------------------------------------------------------
		static Vector4 vectorToWorldSpace(const Vector4 &vec,
			const Vector4 &AgentSide,
			const Vector4 &AgentTop,
			const Vector4 &AgentHeading);

		//--------------------- pointToLocalSpace --------------------------------
		//
		//  Transforms a point into world space to agent's local space
		//------------------------------------------------------------------------
		static Vector4 pointToLocalSpace(const Vector4 &point,
			const Vector4 &agent_side,
			const Vector4 &agend_top,
			const Vector4 &agend_heading,
			const Vector4 &agent_position);

		//--------------------- VectorToLocalSpace --------------------------------
		//
		//------------------------------------------------------------------------
		static Vector4 vectorToLocalSpace(const Vector4 &vec,
			const Vector4 &AgentSide,
			const Vector4 &AgentTop,
			const Vector4 &AgentHeading);
	};
}