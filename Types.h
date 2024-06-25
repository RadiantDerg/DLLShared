#ifndef __TYPES_H
#define __TYPES_H

struct Vector2
{
	Vector2(Hedgehog::Math::CVector2 in) : x(in.x()), y(in.y()) {}
	float x;
	float y;
};

struct Vector3
{
	Vector3 (Hedgehog::Math::CVector in) : x(in.x()), y(in.y()), z(in.z()) {}
	float x;
	float y;
	float z;
};

#endif __TYPES_H