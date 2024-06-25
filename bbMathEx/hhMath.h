#ifdef BB_EXCLUDE_MATH_DEFINITIONS
#pragma once

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