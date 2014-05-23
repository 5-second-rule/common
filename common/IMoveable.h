#pragma once
#include "common.h"

#include "Vector4.h"
#include "Matrix4.h"

namespace Common {
	class COMMONDLL IMoveable {
	public:
		/* Relative */
		void move(float dx, float dy, float dz);
		void move(const Vector4& delta);

		void rotate(float x, float y, float z);
		void rotate(const Vector4& vector, float degrees);

		/* Absolute */
		void setScale(float scale);

		void setPosition(float x, float y, float z);
		void setPosition(const Vector4& pos);

		void setRotation(float x, float y, float z);

		/* Getters */
		const Vector4 getPosition() const;
		const Matrix4 getRotation() const;
		const float getScale() const;
	};
}