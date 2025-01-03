#ifdef BB_EXCLUDE_MATH_DEFINITIONS
#pragma once

// Many of the methods for CVector and CQuaternion were taken / adapted from the "GMath" library,
// changed to be more friendly to C++ and/or to leverage Eigen.
// While Eigen itself has many per formant and useful math methods, some of the naming can be unintuitive,
// and a rare few operations used in modern game engines like Unity and Unreal don't exist in Eigen or don't have an intuitive analog.
// This hopefully bridges the gap a fair bit; I've had use with these methods so I take advantage of this when I can.
//
// GMath: https://github.com/YclepticStudios/gmath

#include <corecrt_math_defines.h>

#include "hhCVector.h"
#include "hhCQuaternion.h"
#include "hhCVector4.h"

namespace Sonic
{
    using CNoAlignVector = Eigen::Vector3f;
}

// Hedgehog::Math
namespace Hedgehog::Math
{
    using CAabb = Eigen::AlignedBox3f;
    //using CMatrix = Eigen::Affine3f;
    //using CMatrix44 = Eigen::Matrix4f;
    //using CQuaternion = Eigen::Quaternionf;
    //using CVector = Eigen::AlignedVector3<float>;
    using CVector2 = Eigen::Vector2f;
    //using CVector4 = Eigen::Vector4f;
}
#endif