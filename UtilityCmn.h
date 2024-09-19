#pragma once


namespace Utils
{
	class Math
	{
	public:
		/// <summary>Create a random float32 value</summary>
		float static Randf32(float min, float max)
		{
			using namespace std;
			float random = (float)rand() / (float)RAND_MAX;
			float output = random * (max - min);
			return min + output;
		}

		/// <summary>Naive Interpolation</summary>
		/// <param name="a">Point A</param>
		/// <param name="b">Point B</param>
		/// <param name="t">Time</param>
		static double NaiveLerp(double a, double b, double t)
		{
			return a + t * (b - a);
		}
	};


	class App
	{
	public:
		// From https://github.com/brianuuu
		uint32_t static GetMultiLevelAddress(uint32_t startAddress, const std::vector<uint32_t>& offsets)
		{
			uint32_t addr = *(uint32_t*)startAddress;
			for (uint32_t i = 0; i < offsets.size(); i++)
			{
				uint32_t const& ofst = offsets[i];
				addr += ofst;

				if (i < offsets.size() - 1)
				{
					addr = *(uint32_t*)addr;
				}
			}
			return addr;
		}
	};


	//Temporary holding spot, dont use me!
	class Misc
	{
	public:
		/// <summary>Returns the name of <T>class</summary>
		static inline const char* GetClassObjectName(const void* pObject)
		{
			try
			{
				class _dummy_virtual_class
				{
					virtual ~_dummy_virtual_class() = 0;
				};
				return typeid(*reinterpret_cast<const _dummy_virtual_class*>(pObject)).name();
			}
			catch (std::exception& e)
			{
				(void)e;
				return "Invalid";//"Invalid: " << e.what();
			}
		}


		template<typename Scalar>
		static inline Eigen::Matrix<Scalar, 4, 4> MakePerspectiveMatrix(const Scalar fieldOfView, const Scalar aspectRatio, const Scalar zNear, const Scalar zFar)
		{
			const Scalar yScale = (Scalar)1 / std::tan(fieldOfView / (Scalar)2);
			const Scalar xScale = yScale / aspectRatio;

			Eigen::Matrix<Scalar, 4, 4> matrix;

			matrix <<
				xScale, 0, 0, 0,
				0, yScale, 0, 0,
				0, 0, -(zFar + zNear) / (zFar - zNear), -2 * zNear * zFar / (zFar - zNear),
				0, 0, -1, 0;

			return matrix;
		}


		template<typename Scalar>
		static inline Eigen::Matrix<Scalar, 4, 4> MakeOrthographicMatrix(const Scalar zNear, const Scalar zFar, Scalar orthoSize, Scalar aspectRatio)
		{
			Eigen::Matrix<Scalar, 4, 4> matrix;
			const Scalar top = orthoSize;
			const Scalar bottom = -orthoSize;
			const Scalar right = orthoSize * aspectRatio;
			const Scalar left = -right;
			matrix <<
				2 / (right - left), 0, 0, 0,
				0, 2 / (top - bottom), 0, 0,
				0, 0, 1 / (zNear - zFar), 0,
				(left + right) / (left - right), (top + bottom) / (bottom - top), zNear / (zNear - zFar), 1;

			return matrix;
		}
	};
}