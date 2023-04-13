#include <cmath>

#ifndef ENGINE_MATH_H
#define ENGINE_MATH_H

namespace ENGINE
{
	struct Vector2
	{
		float x, y;

		Vector2() : x(0), y(0) {}
		Vector2(float x, float y) : x(x), y(y) {}

		Vector2 operator-() const { /* 流立 备泅 窍扁 */ }

		Vector2 operator*(const float& value) const { /* 流立 备泅 窍扁 */ }
		Vector2 operator/(const float& value) const { /* 流立 备泅 窍扁 */ }
		Vector2 operator*=(const float& value) { /* 流立 备泅 窍扁 */ }
		Vector2 operator/=(const float& value) { /* 流立 备泅 窍扁 */ }

		Vector2 operator+(const Vector2& v) const { /* 流立 备泅 窍扁 */ }
		Vector2 operator-(const Vector2& v) const { /* 流立 备泅 窍扁 */ }
		Vector2 operator+=(const Vector2& v) { /* 流立 备泅 窍扁 */ }
		Vector2 operator-=(const Vector2& v) { /* 流立 备泅 窍扁 */ }

	};

	inline bool operator== (const Vector2& lhs, const Vector2& rhs) { /* 流立 备泅 窍扁 */ }
	inline bool operator!= (const Vector2& lhs, const Vector2& rhs) { /* 流立 备泅 窍扁 */ }

	const float Epsilon = 0.0001f;

	inline bool Equal(float lhs, float rhs) { return (std::abs(lhs - rhs) <= Epsilon); }

#ifndef clamp
#define clamp(v, a, b) (a < b) ? min(max(v, a), b) : min(max(v, b), a)
#endif // !clamp

	int Repeat(int value, const int& max);
}

#endif // !ENGINE_MATH_H