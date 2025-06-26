#include "pch.h"
#include "CppUnitTest.h"
#include "..\MathLib\Vector\Vector3f\Vector3f.h"
#include "..\MathLib\Util\Random.h"
#include "..\MathLib\Util\CommonMath.h"

#include <chrono>
#include <iostream>
using namespace std::chrono;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector3f
{
	TEST_CLASS(Construction) 
	{
	public:
		
		TEST_METHOD(Default)
		{
			Vec3f testVector;

			Assert::AreEqual(testVector.x, 0.0f);
			Assert::AreEqual(testVector.y, 0.0f);
			Assert::AreEqual(testVector.z, 0.0f);
		}

		TEST_METHOD(Parameter)
		{
			Vec3f testVector(1, 2, 3);
	
			Assert::AreEqual(1.0f, testVector.x, L"X is not assigned correctly", LINE_INFO()); 
			Assert::AreEqual(2.0f, testVector.y, L"Y is not assigned correctly", LINE_INFO()); 
			Assert::AreEqual(3.0f, testVector.z, L"Z is not assigned correctly", LINE_INFO()); 
		}

		TEST_METHOD(SingleParameter)
		{
			Vec3f testVector(5.0f);

			Assert::AreEqual(testVector.x, 5.0f);
			Assert::AreEqual(testVector.y, 5.0f);
			Assert::AreEqual(testVector.z, 5.0f);
		}

		TEST_METHOD(Copy)
		{
			const Vec3f originalVector(5.0f, 10.0f, 15.0f);
			Vec3f testVector(originalVector);


			Assert::AreEqual(testVector.x, originalVector.x);
			Assert::AreEqual(testVector.y, originalVector.y);
			Assert::AreEqual(testVector.z, originalVector.z);
		}

	};
	TEST_CLASS(Operators)
	{
		TEST_METHOD(Equals) 
		{
			Vec3f vec1(50.0f, 100.0f, 150.0f);
			Vec3f vec2(50.0f, 100.0f, 150.0f);
			Vec3f vec3(100.0f, 150.0f, 200.0f);

			Assert::IsTrue(vec1 == vec2 && "Vector is not comparing correctly");
			Assert::IsFalse(vec1 == vec3 && "Vector is not comparing correctly");

			Assert::IsTrue(vec1 != vec3 && "Vector is not comparing correctly");
			Assert::IsFalse(vec1 != vec2 && "Vector is not comparing correctly");

			Assert::IsTrue(vec1 != vec3 && "Vector is not comparing correctly");
		}

		TEST_METHOD(Add)
		{
			Vec3f vec1(50.0f, 100.0f, 150.0f);
			Vec3f vec2(50.0f, 100.0f, 150.0f);
			Vec3f vec3(100.0f, 200.0f, 300.0f);

			Vec3f difVec = vec1 + vec2;
			Assert::IsTrue(difVec == vec3 && "Vector not adding correctly");

			Vec3f sammeVec = vec1 + vec1;
			Assert::IsTrue(sammeVec == vec3 && "Vector not adding correctly");

			vec1 += vec2;
			Assert::IsTrue(vec1 == vec3 && "Vector not adding correctly");

			Vec3f maxVec(FLT_MAX);

			Vec3f overflowVec = maxVec + maxVec;
			Assert::IsTrue(std::isinf(overflowVec.x) && "Vector X did not result in a overflow"); 
			Assert::IsTrue(std::isinf(overflowVec.y) && "Vector Y did not result in a overflow"); 
			Assert::IsTrue(std::isinf(overflowVec.z) && "Vector Z did not result in a overflow"); 

		}


		TEST_METHOD(Sub)
		{
			Vec3f vec1(50.0f, 100.0f, 150.0f);
			Vec3f vec2(50.0f, 100.0f, 150.0f);
			Vec3f vec3(100.0f, 200.0f, 300.0f);

			Vec3f difVec = vec3 - vec1;  
			Assert::IsTrue(difVec == vec2 && "Vector not subtracting correctly");  
			 
			Vec3f sammeVec = vec1 - vec1; 
			Assert::IsTrue(sammeVec == Vec3f( 0, 0, 0 ) && "Vector not subtracting correctly"); 

			vec3 -= vec2;
			Assert::IsTrue(vec3 == vec1 && "Vector not subtracting correctly");  

		}

		TEST_METHOD(Mul_Vec) 
		{
			Vec3f vec1(50.0f, 100.0f, 150.0f);
			Vec3f vec2(50.0f, 100.0f, 150.0f);

			Vec3f difVec = vec1 * vec2; 
			Assert::IsTrue(difVec == Vec3f(2500.0f, 10000.0f, 22500.0f) && "Vector not multiplying with vector correctly"); 

			Vec3f sammeVec = vec1 * vec1;
			Assert::IsTrue(sammeVec == Vec3f(2500.0f, 10000.0f, 22500.0f) && "Vector not multiplying with vector correctly"); 

			vec1 *= vec2; 
			Assert::IsTrue(vec1 == Vec3f(2500.0f, 10000.0f, 22500.0f) && "Vector not multiplying with vector correctly");
		}

		TEST_METHOD(Mul_Scalar)
		{
			Vec3f vec1 = { 5.0f, 10.0f, 15.0f };
			float scalar = 5.0f;
			const Vec3f result = {5.0f * scalar, 10.0f * scalar, 15.0f * scalar };

			Assert::IsTrue(vec1 * scalar == result && "Vector not multiplying with scalar correctly");
			Assert::IsTrue(scalar * vec1 == result && "Vector not multiplying with scalar correctly"); 

			Assert::IsTrue(vec1 * 5 == result && "Vector not multiplying with scalar correctly"); 
			Assert::IsTrue(5 * vec1 == result && "Vector not multiplying with scalar correctly"); 
			
			vec1 *= scalar; 
			Assert::IsTrue(vec1 == result && "Vector not multiplying with scalar correctly");   
		}

		TEST_METHOD(Div)
		{
			Vec3f vec1(5.0f, 1.0f, 15.0f);
			Vec3f vec2(10.0f, 2.0f, 5.0f);
			float scalar = 5.0f;

			Vec3f difVec = vec1 / vec2;
			Assert::IsTrue(difVec == Vec3f(0.5f, 0.5f, 3.0f) && "Vector not dividing correctly"); 

			Vec3f sammeVec = vec1 / vec1;
			Assert::IsTrue(sammeVec == Vec3f(1.0f, 1.0f, 1.0f) && "Vector not dividing correctly");

			Vec3f scalarVec = vec1 / scalar;  
			Assert::IsTrue(scalarVec == Vec3f(1.0f, 0.2f, 3.0f) && "Vector not dividing with scalar correctly"); 

			vec1 /= vec1;
			Assert::IsTrue(vec1 == Vec3f(1.0f, 1.0f, 1.0f) && "Vector not dividing correctly");

			vec2 /= 2.0f;
			Assert::IsTrue(vec2 == Vec3f(5.0f, 1.0f, 2.5f) && "Vector not dividing correctly");
			
		}

		TEST_METHOD(UnaryNegation) 
		{

			Vec3f vec1(5.0f, -1.0f, 15.0f);
			Vec3f falseResult(5.0f, 1.0f, 15.0f);
			Vec3f result(-5.0f, 1.0f, -15.0f); 

			Assert::IsTrue(-vec1 == result); 
			Assert::IsFalse(-vec1 == falseResult); 
		}

	};
	TEST_CLASS(Functions)
	{
		TEST_METHOD(LengthSqr)
		{
			Vec3f vec(3.0f, 4.0f, 0.0f);
			Assert::AreEqual(vec.LengthSqr(), 25.0f, L"LengthSqr is not returning correct length");

			vec.z = 5.0f;
			Assert::AreEqual(vec.LengthSqr(), 50.0f, L"LengthSqr is not returning correct length");

		}

		TEST_METHOD(Length)
		{
			Vec3f vec(3.0f, 4.0f, 0.0f);
			Assert::AreEqual(vec.Length(), 5.0f, L"Length is not returning correct length");

			int runs = 100;
			const float scale = 1000.0f;
			for (int i = 0; i < runs; i++)
			{
				const float x = BB::Random(-scale, scale);  
				const float y = BB::Random(-scale, scale); 
				const float z = BB::Random(-scale, scale); 

				Vec3f randomVec(x, y, z);
				float correct = sqrt((x * x) + (y * y) + (z * z));

				Assert::IsTrue(randomVec.Length() == correct, L"Length is not returning correct length");
			}


			vec.z = 5.0f;
			Assert::AreEqual(vec.Length(), 7.071068f, L"Length is not returning correct length");

		}

		TEST_METHOD(Normalize)
		{
			// Create new Vector that is Normalized
			{
				Vec3f single(1.0f, 0.0f, 0.0f);
				Assert::IsTrue(single.GetNormalized() == single, L"Normalizing is not done properly"); 

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);
					const float z = BB::Random(-scale, scale);

					Vec3f randomVec(x, y, z);
					float length = sqrt((x * x) + (y * y) + (z * z));
					Vec3f correct = randomVec / length;

					Assert::IsTrue(randomVec.GetNormalized() == correct, L"Normalizing is not done properly");
				}
			}

			// Normalize the current vector
			{
				Vec3f single(1.0f, 0.0f, 0.0f);
				Vec3f singleCorrect(1.0f, 0.0f, 0.0f);
				single.Normalize();
				Assert::IsTrue(single == singleCorrect, L"Normalizing is not done properly");

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);
					const float z = BB::Random(-scale, scale);

					Vec3f randomVec(x, y, z);
					float length = sqrt((x * x) + (y * y) + (z * z));
					Vec3f correct = randomVec / length;

					randomVec.Normalize();
					Assert::IsTrue(randomVec == correct, L"Normalizing is not done properly");
				}
			}


		}

		TEST_METHOD(Dot)
		{
			Vec3f a(1.0f, 0.0f, 0.0f); 
			Vec3f b(0.0f, 1.0f, 0.0f); 
			Vec3f c(2.0f, 3.0f, 4.0f); 

			// Dot of perpendicular vectors should be 0
			Assert::AreEqual(a.Dot(b), 0.0f, 1e-5f, L"Dot product of perpendicular vectors should be zero.");

			// Dot of vector with itself should be its length squared
			Assert::AreEqual(c.Dot(c), 29.0f, 1e-5f, L"Dot product of vector with itself should equal squared magnitude.");

			// Dot of two arbitrary vectors
			Vec3f d(1.0f, 0.0f, -1.0f);
			float expected = c.x * d.x + c.y * d.y + c.z * d.z;
			Assert::AreEqual(c.Dot(d), expected, 1e-5f, L"Dot product of c and d is incorrect."); 
		}

		TEST_METHOD(Cross)
		{
			Vec3f xAxis(1.0f, 0.0f, 0.0f);
			Vec3f yAxis(0.0f, 1.0f, 0.0f);
			Vec3f zAxis(0.0f, 0.0f, 1.0f);

			// Cross of x and y should be z
			Vec3f result = xAxis.Cross(yAxis);
			Assert::AreEqual(zAxis.x, result.x, 1e-5f, L"X cross Y should be Z (x)");
			Assert::AreEqual(zAxis.y, result.y, 1e-5f, L"X cross Y should be Z (y)");
			Assert::AreEqual(zAxis.z, result.z, 1e-5f, L"X cross Y should be Z (z)");

			// Cross of y and x should be -z
			Vec3f negZ(0.0f, 0.0f, -1.0f);
			result = yAxis.Cross(xAxis);
			Assert::AreEqual(negZ.x, result.x, 1e-5f, L"Y cross X should be -Z (x)");
			Assert::AreEqual(negZ.y, result.y, 1e-5f, L"Y cross X should be -Z (y)");
			Assert::AreEqual(negZ.z, result.z, 1e-5f, L"Y cross X should be -Z (z)");

			// Cross of a vector with itself should be zero vector
			Vec3f zero(0.0f, 0.0f, 0.0f);
			result = xAxis.Cross(xAxis);
			Assert::AreEqual(zero.x, result.x, 1e-5f, L"Vector cross with itself should be zero (x)");
			Assert::AreEqual(zero.y, result.y, 1e-5f, L"Vector cross with itself should be zero (y)");
			Assert::AreEqual(zero.z, result.z, 1e-5f, L"Vector cross with itself should be zero (z)");

			int runs = 100;
			const float size = 100.0f;
			for (int i = 0; i < runs; ++i)
			{
				Vec3f vec1(BB::Random(-size, size), BB::Random(-size, size), BB::Random(-size, size)); 
				Vec3f vec2(BB::Random(-size, size), BB::Random(-size, size), BB::Random(-size, size)); 

				Vec3f vecCross = vec1.Cross(vec2); 

				Vec3f c2 = vec2.Cross(vec1);  
				Assert::IsTrue(std::abs(vecCross.x + c2.x) < 1e-4f, L"Cross product fails anti-commutativity (x)");
				Assert::IsTrue(std::abs(vecCross.y + c2.y) < 1e-4f, L"Cross product fails anti-commutativity (y)");
				Assert::IsTrue(std::abs(vecCross.z + c2.z) < 1e-4f, L"Cross product fails anti-commutativity (z)");
			}

		}

		TEST_METHOD(DistanceTo)
		{
			Vec3f startVec(5.0f, 10.0f, -5.0f);
			Vec3f endVec(5.0f, -10.0f, 5.0f);

			Assert::IsTrue(startVec.DistanceTo(startVec) == Vec3f(0.0f, 0.0f, 0.0f), L"DistansTo on a object on the same place is not correct");
			Assert::IsTrue(startVec.DistanceTo(endVec) == Vec3f(0.0f, -20.0f, 10.0f), L"DistansTo on a object on the same place is not correct");


		}


		TEST_METHOD(RotateX_InPlace)
		{ 
			Vec3f v(0.0f, 1.0f, 0.0f);
			v.RotateX(static_cast<float>(BB::PI_F / 2));  // 90 degrees

			Vec3f expected(0.0f, 0.0f, 1.0f);

			Assert::IsTrue(BB::AlmostEqual(v.x, expected.x), L"RotateX did not produce expected result.");  
			Assert::IsTrue(BB::AlmostEqual(v.y, expected.y), L"RotateX did not produce expected result.");  
			Assert::IsTrue(BB::AlmostEqual(v.z, expected.z), L"RotateX did not produce expected result.");  
		}

		TEST_METHOD(RotateY_InPlace)
		{
			Vec3f v(1.0f, 0.0f, 0.0f);
			v.RotateY(static_cast<float>(BB::PI_F / 2));  // 90 degrees

			Vec3f expected(0.0f, 0.0f, -1.0f);

			Assert::IsTrue(BB::AlmostEqual(v.x, expected.x), L"RotateY did not produce expected result.");
			Assert::IsTrue(BB::AlmostEqual(v.y, expected.y), L"RotateY did not produce expected result.");
			Assert::IsTrue(BB::AlmostEqual(v.z, expected.z), L"RotateY did not produce expected result.");
		}

		TEST_METHOD(RotateZ_InPlace)
		{
			Vec3f v(1.0f, 0.0f, 0.0f);
			v.RotateZ(static_cast<float>(BB::PI_F / 2));  // 90 degrees

			Vec3f expected(0.0f, 1.0f, 0.0f);

			Assert::IsTrue(BB::AlmostEqual(v.x, expected.x), L"RotateZ did not produce expected result."); 
			Assert::IsTrue(BB::AlmostEqual(v.y, expected.y), L"RotateZ did not produce expected result."); 
			Assert::IsTrue(BB::AlmostEqual(v.z, expected.z), L"RotateZ did not produce expected result."); 
		}

		TEST_METHOD(GetRotatedX_ReturnsNew)
		{
			Vec3f v(0.0f, 1.0f, 0.0f);
			Vec3f result = v.GetRotatedX(static_cast<float>(BB::PI_F / 2));

			Vec3f expected(0.0f, 0.0f, 1.0f);

			Assert::IsTrue(BB::AlmostEqual(result.x, expected.x), L"GetRotatedX did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.y, expected.y), L"GetRotatedX did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.z, expected.z), L"GetRotatedX did not return expected vector.");
		}

		TEST_METHOD(GetRotatedY_ReturnsNew)
		{
			Vec3f v(1.0f, 0.0f, 0.0f);
			Vec3f result = v.GetRotatedY(static_cast<float>(BB::PI_F / 2));

			Vec3f expected(0.0f, 0.0f, -1.0f);

			Assert::IsTrue(BB::AlmostEqual(result.x, expected.x), L"GetRotatedY did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.y, expected.y), L"GetRotatedY did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.z, expected.z), L"GetRotatedY did not return expected vector.");
		}

		TEST_METHOD(GetRotatedZ_ReturnsNew)
		{
			Vec3f v(1.0f, 0.0f, 0.0f);
			Vec3f result = v.GetRotatedZ(static_cast<float>(BB::PI_F / 2));

			Vec3f expected(0.0f, 1.0f, 0.0f);

			Assert::IsTrue(BB::AlmostEqual(result.x, expected.x), L"GetRotatedZ did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.y, expected.y), L"GetRotatedZ did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.z, expected.z), L"GetRotatedZ did not return expected vector.");
		}

		TEST_METHOD(RotateAroundAxis_InPlace)
		{
			Vec3f v(1.0f, 0.0f, 0.0f);
			Vec3f axis(0.0f, 0.0f, 1.0f); // Z-axis

			v.RotateAroundAxis(axis, 90.0f * BB::DegToRad);

			Assert::IsTrue(std::abs(v.x) < 1e-4f, L"X should be ~0 after 90° rotation");
			Assert::IsTrue(std::abs(v.y - 1.0f) < 1e-4f, L"Y should be ~1 after 90° rotation");
			Assert::IsTrue(std::abs(v.z) < 1e-4f, L"Z should remain unchanged");
		}

		TEST_METHOD(GetRotatedAroundAxis_Copy)
		{
			Vec3f original(0.0f, 1.0f, 0.0f);
			Vec3f axis(1.0f, 0.0f, 0.0f); // X-axis

			Vec3f rotated = original.GetRotatedAroundAxis(axis, 90.0f * BB::DegToRad);

			Assert::IsTrue(BB::AlmostEqual(rotated.x, original.x), L"X should remain unchanged");  
			Assert::IsTrue(BB::AlmostEqual(rotated.y, 0.0f), L"Y should be ~0 after 90° rotation");  
			Assert::IsTrue(BB::AlmostEqual(rotated.z, 1.0f), L"Z should be ~1 after 90° rotation");  

			unsigned int runs = 1000;
			const float size = 1000.0f;
			for (int i = 0; i < runs; ++i) 
			{
				// Random vector
				Vec3f v(BB::Random(-size, size), BB::Random(-size, size), BB::Random(-size, size)); 
				if (v.GetNormalized().x == 0 && v.GetNormalized().y == 0 && v.GetNormalized().z == 0) 
					continue; // skip zero vectors

				// Random axis (also non-zero)
				Vec3f axis(BB::Random (-size, size), BB::Random(-size, size), BB::Random(-size, size)); 
				if (axis.GetNormalized().x == 0 && axis.GetNormalized().y == 0 && axis.GetNormalized().z == 0)
					continue; // skip zero axes

				// Random angle in radians
				float angle = BB::Random(1.0f, 359.0f) * BB::DegToRad; 

				// Apply rotation
				Vec3f rotated = v.GetRotatedAroundAxis(axis, angle);

				// Check that length is preserved
				Assert::IsTrue(BB::AlmostEqual(v.Length(), rotated.Length(), 0.001f), L"Length should be preserved"); 

				// Check dot product with axis is preserved
				float dotOriginal = v.Dot(axis.GetNormalized());
				float dotRotated = rotated.Dot(axis.GetNormalized());
				Assert::IsTrue(BB::AlmostEqual(dotOriginal, dotRotated, 0.001f), L"Dot product with axis should be preserved");

				// Reverse rotation and check if we get back to original
				Vec3f reverse = rotated.GetRotatedAroundAxis(axis, -angle);
				Assert::IsTrue(BB::AlmostEqual(v.x, reverse.x, 0.001f), L"Reverse rotation X failed"); 
				Assert::IsTrue(BB::AlmostEqual(v.y, reverse.y, 0.001f), L"Reverse rotation Y failed"); 
				Assert::IsTrue(BB::AlmostEqual(v.z, reverse.z, 0.001f), L"Reverse rotation Z failed"); 
			}


		}

	};
	
}
