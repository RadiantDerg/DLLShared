#ifdef BB_EXCLUDE_MATH_DEFINITIONS
#pragma once
#include "hhCMatrix.h"
#include "hhCVector4.h"

namespace Hedgehog::Math
{
	float* CMatrix::GetRowColumn(int row, int column) const
	{
		float* This = (float*)this;
		return &This[4 * column + row];
	}

	float* CMatrix::GetRowColumn(CMatrix* This, int row, int column)
	{
		float* f = (float*)This;
		return &f[4 * column + row];
	}

	float CMatrix::GetFloat(int row, int column) const
	{
		float* f = (float*)this;
		return f[4 * column + row];
	}

	void CMatrix::CreateFromAxis(CMatrix* This, CVector* xAxis, CVector* yAxis, CVector* zAxis)
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(void, __thiscall, func, 0x006F0EA0,
			CMatrix * _This,
			CVector * x, CVector * y, CVector * z);

		// UNDONE: May not be necessary, worth verifying?
		//*This = CMatrix::Identity();
		func(This, xAxis, yAxis, zAxis);
#else
		*GetRowColumn(This, 0, 0) = xAxis->x();
		*GetRowColumn(This, 0, 1) = xAxis->y();
		*GetRowColumn(This, 0, 2) = xAxis->z();
		*GetRowColumn(This, 1, 0) = yAxis->x();
		*GetRowColumn(This, 1, 1) = yAxis->y();
		*GetRowColumn(This, 1, 2) = yAxis->z();
		*GetRowColumn(This, 2, 0) = zAxis->x();
		*GetRowColumn(This, 2, 1) = zAxis->y();
		*GetRowColumn(This, 2, 2) = zAxis->z();
#endif
	}

	CMatrix CMatrix::CreateFromAxis(const CVector& xAxis, const CVector& yAxis, const CVector& zAxis)
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(void, __thiscall, func, 0x006F0EA0,
			CMatrix * _This,
			const CVector & x, const CVector & y, const CVector & z);

		CMatrix result = CMatrix::Identity();
		func(&result, xAxis, yAxis, zAxis);
		return result;
#else
		CMatrix out = CMatrix::Identity();
		*GetRowColumn(&out, 0, 0) = xAxis.x();
		*GetRowColumn(&out, 0, 1) = xAxis.y();
		*GetRowColumn(&out, 0, 2) = xAxis.z();
		*GetRowColumn(&out, 1, 0) = yAxis.x();
		*GetRowColumn(&out, 1, 1) = yAxis.y();
		*GetRowColumn(&out, 1, 2) = yAxis.z();
		*GetRowColumn(&out, 2, 0) = zAxis.x();
		*GetRowColumn(&out, 2, 1) = zAxis.y();
		*GetRowColumn(&out, 2, 2) = zAxis.z();
		return out;
#endif
	}

	CMatrix* CMatrix::Transpose(CMatrix* This, CMatrix* Result)
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(void*, __thiscall, func, 0x009BECC0, void* _This, void* z);
		return (CMatrix*)func(This, Result);
#else
		* Result = ((Eigen::Matrix4f*)&This)->transpose();
		return Result;
#endif
	}

	CVector CMatrix::GetVectorFromRow(int row) const
	{
		
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x006F1530, const CMatrix * This, const CVector & _result, int _row);

		CVector result(0, 0, 0);
		func(this, result, row);
		return result;
#else
		const float z = GetFloat(row, 2);
		const float y = GetFloat(row, 1);
		const float x = GetFloat(row, 0);
		return CVector(x, y, z);
#endif
	}

	CVector CMatrix::GetVectorFromColumn(int column) const
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x006F14E0, const CMatrix * This, const CVector & _result, int _column);

		CVector result(0, 0, 0);
		func(this, result, column);
		return result;
#else
		const float z = GetFloat(2, column);
		const float y = GetFloat(1, column);
		const float x = GetFloat(0, column);
		return CVector(x, y, z);
#endif
	}

	CVector* CMatrix::TransformNormal(CMatrix44* This, CVector* result, CVector* vec)
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x009BE800, CMatrix44 * _This, CVector * _result, CVector * _vec);
		return func(This, result, vec);
#else
		float* F = (float*)This;
		__m128 add =
			_mm_add_ps(
				_mm_add_ps(
					_mm_mul_ps(_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 0), *(__m128*)F),
					_mm_mul_ps(_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 85), *(__m128*)(F + 4))),
				_mm_mul_ps(_mm_shuffle_ps(*(__m128*)vec, *(__m128*)vec, 170), *(__m128*)(F + 8)));

		*result = *(CVector*)&add;
		return result;
#endif
	}

	Eigen::Matrix3f CMatrix::GetRotationMatrix()
	{
		float* data = (float*)this;
		float out[9] = { data[0], data[1], data[2],
						 data[4], data[5], data[6],
						 data[8], data[9], data[10] };

		return *(Eigen::Matrix3f*)&out;
	}

	void CMatrix44::CreateFromAxis(CMatrix44* This, const CVector* xAxis, const CVector* yAxis, const CVector* zAxis)
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(void, __thiscall, func, 0x006F0EA0, CMatrix44* _This, const CVector* x, const CVector* y, const CVector* z);

		*This = CMatrix44::Identity();
		func(This, xAxis, yAxis, zAxis);
#else
		*This->GetRowColumn(0, 0) = xAxis->x();
		*This->GetRowColumn(0, 1) = xAxis->y();
		*This->GetRowColumn(0, 2) = xAxis->z();
		*This->GetRowColumn(1, 0) = yAxis->x();
		*This->GetRowColumn(1, 1) = yAxis->y();
		*This->GetRowColumn(1, 2) = yAxis->z();
		*This->GetRowColumn(2, 0) = zAxis->x();
		*This->GetRowColumn(2, 1) = zAxis->y();
		*This->GetRowColumn(2, 2) = zAxis->z();
#endif
	}

	CMatrix44 CMatrix44::CreateFromAxis(const CVector& xAxis, const CVector& yAxis, const CVector& zAxis)
	{
		CMatrix44 mat = {};
		CreateFromAxis(&mat, &xAxis, &yAxis, &zAxis);
		return mat;
	}

	CMatrix44 CMatrix44::CreateFromAxis(CVector* xAxis, CVector* yAxis, CVector* zAxis)
	{
		CMatrix44* mat = nullptr;
		CreateFromAxis(mat, xAxis, yAxis, zAxis);
		return *mat;
	}

	void CMatrix44::SetFromAxis(CVector* xAxis, CVector* yAxis, CVector* zAxis)
	{
		CreateFromAxis(this, xAxis, yAxis, zAxis);
	}

	float CMatrix44::GetFloatFromMatrix(int row, int column) const
	{
		return reinterpret_cast<const float*>(this)[4 * column + row];
	}

	float* CMatrix44::GetRowColumn(int row, int column) const
	{
		float* This = (float*)this;
		return &This[4 * column + row];
	}

	CVector CMatrix44::GetVectorFromRow(int row) const
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x006F1530, const CMatrix44 * This, const CVector & result, int _row);
		CVector result(0, 0, 0);
		func(this, result, row);
		return result;
#else
		const float z = GetFloatFromMatrix(row, 2);
		const float y = GetFloatFromMatrix(row, 1);
		const float x = GetFloatFromMatrix(row, 0);
		return CVector(x, y, z);
#endif
	}

	CVector CMatrix44::GetVectorFromColumn(int row) const
	{

#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x006F14E0, const CMatrix44 * This, const CVector & _result, int _column);
		CVector result(0, 0, 0);
		func(this, result, row);
		return result;
#else
		const float z = GetFloatFromMatrix(2, row);
		const float y = GetFloatFromMatrix(1, row);
		const float x = GetFloatFromMatrix(0, row);
		return CVector(x, y, z);
#endif
	}

	CVector CMatrix44::TransformVector(const CVector& vector) const
	{
#ifdef _USE_INGAME_MATH
		BB_FUNCTION_PTR(CVector*, __thiscall, func, 0x009BE800, const CMatrix44 * This, const CVector& result, const CVector& vec);
		CVector result(0, 0, 0);
		func(this, result, vector);
		return result;
#else
		CVector* vectorRows = (CVector*)this;
		return vector.x() * vectorRows[0]
			+ vector.y() * vectorRows[1]
			+ vector.z() * vectorRows[2];
#endif
	}

	void CMatrix44::RotateYaw(float angle)
	{
		BB_FUNCTION_PTR(void, __thiscall, func, 0x009BE460, CMatrix44 * This, const float f);
		func(this, angle);
#ifdef _USE_INGAME_MATH

#else

#endif
	}

	void CMatrix44::RotatePitch(float angle)
	{
		BB_FUNCTION_PTR(void, __thiscall, func, 0x009BE420, CMatrix44 * This, const float f);
		func(this, angle);
#ifdef _USE_INGAME_MATH

#else

#endif
	}

}
#endif