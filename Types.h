#ifndef __TYPES_H
#define __TYPES_H

struct Vector2
{
	float x;
	float y;

	constexpr Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}
#ifdef BB_OFFSETOF
	Vector2(Hedgehog::Math::CVector2  in) : x(in.x()), y(in.y()) {}
	Vector2(Hedgehog::Math::CVector2* in) : x(in->x()), y(in->y()) {}
#endif
#ifdef IMGUI_API
	Vector2(const ImVec2& in) : x(in.x), y(in.y) {}
#endif
};

struct Vector3
{
	float x;
	float y;
	float z;

	constexpr Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
#ifdef BB_OFFSETOF
	Vector3(Hedgehog::Math::CVector  in) : x(in.x()), y(in.y()), z(in.z()) {}
	Vector3(Hedgehog::Math::CVector* in) : x(in->x()), y(in->y()), z(in->z()) {}
#endif
	Vector3 operator+=(const Vector3& in)
    {
		this->x += in.x;
		this->y += in.y;
		this->y += in.y;
		return *this;
	}
	Vector3 operator-=(const Vector3& in)
	{
		this->x -= in.x;
		this->y -= in.y;
		this->y -= in.y;
		return *this;
	}
	Vector3 operator*(const Vector3& in)
	{
		this->x * in.x;
		this->y * in.y;
		this->z * in.z;
		return *this;
	}
	bool operator==(const Vector3& in) const { return (this->x == in.x && this->y == in.y && this->z == in.z); }
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
#ifdef BB_OFFSETOF
	Vector4(Hedgehog::Math::CVector4& in) : x(in.x()), y(in.y()), z(in.z()), w(in.w()) {}
	Vector4(Hedgehog::Math::CVector4* in) : x(in->x()), y(in->y()), z(in->z()), w(in->w()) {}
#endif
};

struct Quaternion : public Vector4
{
	Quaternion() : Vector4(0.0f, 0.0f, 0.0f, 1.0f) {}
	Quaternion(float x, float y, float z, float w) : Vector4(x, y, z, w) {}
	Quaternion(const Vector4& in) : Vector4(in.x, in.y, in.z, in.w) {}
	Quaternion(const Quaternion& in) : Vector4(in.x, in.y, in.z, in.w) {}
#ifdef BB_OFFSETOF
	Quaternion(Hedgehog::Math::CQuaternion& in) : Vector4(in.x(), in.y(), in.z(), in.w()) {}
	Quaternion(Hedgehog::Math::CQuaternion* in) : Vector4(in->x(), in->y(), in->z(), in->w()) {}
#endif
};

struct Matrix44
{
	Vector4 r0, r1, r2, r3;

	Matrix44() : r0(1.0f, 0.0f, 0.0f, 0.0f), r1(0.0f, 1.0f, 0.0f, 0.0f), r2(0.0f, 0.0f, 1.0f, 0.0f), r3(0.0f, 0.0f, 0.0f, 1.0f) {}
	Matrix44(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d) : r0(a), r1(b), r2(c), r3(d) {}
#ifdef BB_OFFSETOF
	Matrix44(Hedgehog::Math::CMatrix44& in) :
		r0({ in(0, 0), in(0, 1), in(0, 2), in(0, 3) }),
		r1({ in(1, 0), in(1, 1), in(1, 2), in(1, 3) }),
		r2({ in(2, 0), in(2, 1), in(2, 2), in(2, 3) }),
		r3({ in(3, 0), in(3, 1), in(3, 2), in(3, 3) }) {}
#endif
};

#endif __TYPES_H