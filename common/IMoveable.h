#pragma once
#include "common.h"

#include "Vector4.h"
#include "Matrix4.h"

namespace Common {
	class COMMONDLL IMoveable {
	public:
		/* Relative */
		virtual void move(float dx, float dy, float dz) = 0;
		virtual void move(const Vector4& delta) = 0;

		virtual void rotate(float x, float y, float z) = 0;
		virtual void rotate(const Vector4& vector, float degrees) = 0;

		/* Absolute */
		virtual void setScale(float scale) = 0;

		virtual void setPosition(float x, float y, float z) = 0;
		virtual void setPosition(const Vector4& pos) = 0;

		virtual void setRotation(float x, float y, float z) = 0;

		/* Getters */
		virtual const Vector4& getPosition() const = 0;
		virtual const Matrix4& getRotation() const = 0;
		virtual const float getScale() const = 0;
	};
}