#ifndef __TYPES_H
#define __TYPES_H

struct Vector2
{
	Vector2(float x, float y) : x(x), y(y) {}
#ifdef BB_OFFSETOF
	Vector2(Hedgehog::Math::CVector2  in) : x(in.x()), y(in.y()) {}
	Vector2(Hedgehog::Math::CVector2* in) : x(in->x()), y(in->y()) {}
#endif
	float x;
	float y;
};

struct Vector3
{
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
#ifdef BB_OFFSETOF
	Vector3(Hedgehog::Math::CVector  in) : x(in.x()), y(in.y()), z(in.z()) {}
	Vector3(Hedgehog::Math::CVector* in) : x(in->x()), y(in->y()), z(in->z()) {}
#endif
	float x;
	float y;
	float z;

	Vector3 operator+=(const Vector3& in)
	{
		this->x += in.x;
		this->y += in.y;
		this->y += in.y;
		return *this;
	}
	Vector3 operator*(const Vector3& in)
	{
		this->x * in.x;
		this->y * in.y;
		this->z * in.z;
		return *this;
	}
};

struct Vector4
{
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
#ifdef BB_OFFSETOF
	Vector4(Hedgehog::Math::CVector4& in) : x(in.x()), y(in.y()), z(in.z()), w(in.w()) {}
	Vector4(Hedgehog::Math::CVector4* in) : x(in->x()), y(in->y()), z(in->z()), w(in->w()) {}
#endif
	float x;
	float y;
	float z;
	float w;
};

struct Matrix44
{
	Matrix44(Vector4 a, Vector4 b, Vector4 c, Vector4 d) : r0(a), r1(b), r2(c), r3(d) {}
#ifdef BB_OFFSETOF
	Matrix44(Hedgehog::Math::CMatrix44& in) :
		r0({ in(0, 0), in(0, 1), in(0, 2), in(0, 3) }),
		r1({ in(1, 0), in(1, 1), in(1, 2), in(1, 3) }),
		r2({ in(2, 0), in(2, 1), in(2, 2), in(2, 3) }),
		r3({ in(3, 0), in(3, 1), in(3, 2), in(3, 3) }) {}
#endif
	Vector4 r0;
	Vector4 r1;
	Vector4 r2;
	Vector4 r3;
};

#endif __TYPES_H