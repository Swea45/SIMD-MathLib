#include "pch.h"
#include "CppUnitTest.h"
#include "..\MathLib\Vector\Vector4f\Vector4f.h"
#include "..\MathLib\Util\Random.h"
#include "..\MathLib\Util\CommonMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector4f
{
	TEST_CLASS(Construction)
	{
	public:
		
		TEST_METHOD(Default)
		{
			Vec4f testVector;

			Assert::AreEqual(testVector.x, 0.0f, L"X is not assigned correctly");
			Assert::AreEqual(testVector.y, 0.0f, L"Y is not assigned correctly");
			Assert::AreEqual(testVector.z, 0.0f, L"Z is not assigned correctly");
			Assert::AreEqual(testVector.w, 0.0f, L"W is not assigned correctly");
		}

		TEST_METHOD(Parameter)
		{
			Vec4f testVector(1.0f, 2.0f, 3.0f, 4.0f);

			Assert::AreEqual(testVector.x, 1.0f, L"X is not assigned correctly");
			Assert::AreEqual(testVector.y, 2.0f, L"Y is not assigned correctly");
			Assert::AreEqual(testVector.z, 3.0f, L"Z is not assigned correctly");
			Assert::AreEqual(testVector.w, 4.0f, L"W is not assigned correctly");
		}

		TEST_METHOD(SingleParameter)
		{
			Vec4f testVector(5.0f);

			Assert::AreEqual(testVector.x, 5.0f, L"X is not assigned correctly");
			Assert::AreEqual(testVector.y, 5.0f, L"Y is not assigned correctly");
			Assert::AreEqual(testVector.z, 5.0f, L"Z is not assigned correctly");
			Assert::AreEqual(testVector.w, 5.0f, L"W is not assigned correctly");
		}

		TEST_METHOD(Copy)
		{
			const Vec4f originalVector(5.0f, 10.0f, 15.0f, 20.0f);
			Vec4f testVector(originalVector); 


			Assert::AreEqual(testVector.x, originalVector.x, L"X is not assigned correctly"); 
			Assert::AreEqual(testVector.y, originalVector.y, L"Y is not assigned correctly"); 
			Assert::AreEqual(testVector.z, originalVector.z, L"Z is not assigned correctly"); 
			Assert::AreEqual(testVector.w, originalVector.w, L"W is not assigned correctly");
		}
	};
	TEST_CLASS(Operators)
	{
		TEST_METHOD(Equals)
		{
			Vec4f vec1(50.0f, 100.0f, 150.0f, 200.0f);
			Vec4f vec2(50.0f, 100.0f, 150.0f, 200.0f);
			Vec4f vec3(100.0f, 100.0f, 200.0f, 200.0f);

			Assert::IsTrue(vec1 == vec2 && "Vector is not comparing correctly");
			Assert::IsFalse(vec1 == vec3 && "Vector is not comparing correctly");

			Assert::IsTrue(vec1 != vec3 && "Vector is not comparing correctly");
			Assert::IsFalse(vec1 != vec2 && "Vector is not comparing correctly");

			Assert::IsTrue(vec1 != vec3 && "Vector is not comparing correctly");
		}


		TEST_METHOD(Add)
		{
			Vec4f vec1(50.0f, 100.0f, 150.0f, 100.0f);
			Vec4f vec2(50.0f, 100.0f, 150.0f, 100.0f);
			Vec4f vec3(100.0f, 200.0f, 300.0f, 200.0f);

			Vec4f difVec = vec1 + vec2;
			Assert::IsTrue(difVec == vec3 && "Vector not adding correctly");

			Vec4f sammeVec = vec1 + vec1;
			Assert::IsTrue(sammeVec == vec3 && "Vector not adding correctly");

			vec1 += vec2;
			Assert::IsTrue(vec1 == vec3 && "Vector not adding correctly");

			Vec4f maxVec(FLT_MAX);

			Vec4f overflowVec = maxVec + maxVec;
			Assert::IsTrue(std::isinf(overflowVec.x) && "Vector X did not result in a overflow");
			Assert::IsTrue(std::isinf(overflowVec.y) && "Vector Y did not result in a overflow");
			Assert::IsTrue(std::isinf(overflowVec.z) && "Vector Z did not result in a overflow");
			Assert::IsTrue(std::isinf(overflowVec.z) && "Vector W did not result in a overflow");

		}

		TEST_METHOD(Sub)
		{
			Vec4f vec1(50.0f, 100.0f, 150.0f, 150.0f);
			Vec4f vec2(50.0f, 100.0f, 150.0f, 150.0f);
			Vec4f vec3(100.0f, 200.0f, 300.0f, 300.0f);

			Vec4f difVec = vec3 - vec1;
			Assert::IsTrue(difVec == vec2 && "Vector not subtracting correctly");

			Vec4f sammeVec = vec1 - vec1;
			Assert::IsTrue(sammeVec == Vec4f(0, 0, 0, 0) && "Vector not subtracting correctly");

			vec3 -= vec2;
			Assert::IsTrue(vec3 == vec1 && "Vector not subtracting correctly");

		}

		TEST_METHOD(Mul_Vec)
		{
			Vec4f vec1(50.0f, 100.0f, 150.0f, 100.0f);
			Vec4f vec2(50.0f, 100.0f, 150.0f, 0.0f);

			Vec4f difVec = vec1 * vec2;
			Assert::IsTrue(difVec == Vec4f(2500.0f, 10000.0f, 22500.0f, 0.0f), L"Vector not multiplying with vector correctly");

			Vec4f sammeVec = vec1 * vec1;
			Assert::IsTrue(sammeVec == Vec4f(2500.0f, 10000.0f, 22500.0f, 10000.0f), L"Vector not multiplying with vector correctly");

			vec1 *= vec2;
			Assert::IsTrue(vec1 == Vec4f(2500.0f, 10000.0f, 22500.0f, 0.0f), L"Vector not multiplying with vector correctly");
		}

		TEST_METHOD(Mul_Scalar)
		{
			Vec4f vec1 = { 5.0f, 10.0f, 15.0f, 20.0f };
			float scalar = 5.0f;
			const Vec4f result = { 5.0f * scalar, 10.0f * scalar, 15.0f * scalar, 20.0f * scalar };

			Assert::IsTrue(vec1 * scalar == result && "Vector not multiplying with scalar correctly");
			Assert::IsTrue(scalar * vec1 == result && "Vector not multiplying with scalar correctly");

			Assert::IsTrue(vec1 * 5 == result && "Vector not multiplying with scalar correctly");
			Assert::IsTrue(5 * vec1 == result && "Vector not multiplying with scalar correctly");

			vec1 *= scalar;
			Assert::IsTrue(vec1 == result && "Vector not multiplying with scalar correctly");
		}

		TEST_METHOD(Div)
		{
			Vec4f vec1(5.0f, 1.0f, 15.0f, -5.0f);
			Vec4f vec2(10.0f, 2.0f, 5.0f, 0.5f);
			float scalar = 5.0f;

			Vec4f difVec = vec1 / vec2;
			Assert::IsTrue(difVec == Vec4f(0.5f, 0.5f, 3.0f, -10.0f) && "Vector not dividing correctly");

			Vec4f sammeVec = vec1 / vec1;
			Assert::IsTrue(sammeVec == Vec4f(1.0f, 1.0f, 1.0f, 1.0f) && "Vector not dividing correctly");

			Vec4f scalarVec = vec1 / scalar;
			Assert::IsTrue(scalarVec == Vec4f(1.0f, 0.2f, 3.0f, -1.0f) && "Vector not dividing with scalar correctly");

			vec1 /= vec1;
			Assert::IsTrue(vec1 == Vec4f(1.0f, 1.0f, 1.0f, 1.0f) && "Vector not dividing correctly");

			vec2 /= 2.0f;
			Assert::IsTrue(vec2 == Vec4f(5.0f, 1.0f, 2.5f, 0.25f) && "Vector not dividing correctly");

		}

		TEST_METHOD(UnaryNegation)
		{

			Vec4f vec1(5.0f, -1.0f, 15.0f, -6.2f);
			Vec4f falseResult(5.0f, 1.0f, 15.0f, -6.2f);
			Vec4f result(-5.0f, 1.0f, -15.0f, 6.2f);

			Assert::IsTrue(-vec1 == result);
			Assert::IsFalse(-vec1 == falseResult);
		}

	};
	TEST_CLASS(Functions)
	{
		TEST_METHOD(LengthSqr)
		{
			Vec4f vec(3.0f, 4.0f, 0.0f, 0.0f);
			Assert::AreEqual(vec.LengthSqr(), 25.0f, L"LengthSqr is not returning correct length");

			vec.z = 5.0f;
			Assert::AreEqual(vec.LengthSqr(), 50.0f, L"LengthSqr is not returning correct length");

			vec.w = 5.0f;
			Assert::AreEqual(vec.LengthSqr(), 75.0f, L"LengthSqr is not returning correct length");

		}

		TEST_METHOD(Length)
		{
			Vec4f vec(3.0f, 4.0f, 0.0f, 0.0f);
			Assert::AreEqual(vec.Length(), 5.0f, L"Length is not returning correct length");

			vec.z = 5.0f;
			Assert::AreEqual(vec.Length(), 7.071068f, L"Length is not returning correct length");

			vec.w = 5.0f;
			Assert::AreEqual(vec.Length(), 8.66025448f, L"Length is not returning correct length");

			int runs = 100;
			const float scale = 1000.0f;
			for (int i = 0; i < runs; i++)
			{
				const float x = BB::Random(-scale, scale);
				const float y = BB::Random(-scale, scale);
				const float z = BB::Random(-scale, scale);
				const float w = BB::Random(-scale, scale);

				Vec4f randomVec(x, y, z, w);
				float correct = sqrt((x * x) + (y * y) + (z * z) + (w * w));
				float res = randomVec.Length();
				Assert::IsTrue(BB::AlmostEqual(randomVec.Length(), correct, 0.001f), L"Length is not returning correct length");
			}



		}

		TEST_METHOD(Normalize)
		{
			// Create new Vector that is Normalized
			{
				Vec4f single(1.0f, 0.0f, 0.0f, 0.0f);
				Assert::IsTrue(single.GetNormalized() == single, L"Normalizing is not done properly");

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);
					const float z = BB::Random(-scale, scale);
					const float w = BB::Random(-scale, scale);

					Vec4f randomVec(x, y, z, w);
					float length = sqrt((x * x) + (y * y) + (z * z) + (w * w));
					Vec4f correct = randomVec / length; 

					Vec4f normalizedVec = randomVec.GetNormalized();
					//Assert::IsTrue(randomVec.GetNormalized() == correct, L"Normalizing is not done properly"); 
					Assert::IsTrue(BB::AlmostEqual(normalizedVec.x, correct.x, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(normalizedVec.y, correct.y, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(normalizedVec.z, correct.z, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(normalizedVec.w, correct.w, 0.000001f), L"Length is not returning correct length");
				}
			}

			// Normalize the current vector
			{
				Vec4f single(1.0f, 0.0f, 0.0f, 0.0f); 
				Vec4f singleCorrect(1.0f, 0.0f, 0.0f, 0.0f); 
				single.Normalize(); 
				Assert::IsTrue(single == singleCorrect, L"Normalizing is not done properly");

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);
					const float z = BB::Random(-scale, scale);
					const float w = BB::Random(-scale, scale);

					Vec4f randomVec(x, y, z, w);
					float length = sqrt((x * x) + (y * y) + (z * z) + (w * w));
					Vec4f correct = randomVec / length; 

					randomVec.Normalize(); 
					Assert::IsTrue(BB::AlmostEqual(randomVec.x, correct.x, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(randomVec.y, correct.y, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(randomVec.z, correct.z, 0.000001f), L"Length is not returning correct length");
					Assert::IsTrue(BB::AlmostEqual(randomVec.w, correct.w, 0.000001f), L"Length is not returning correct length");
				}
			}
		}

		TEST_METHOD(Dot)
		{
			Vec4f a(1.0f, 0.0f, 0.0f, 0.0f);
			Vec4f b(0.0f, 1.0f, 0.0f, 0.0f);
			Vec4f c(2.0f, 3.0f, 4.0f, 5.0f);

			// Dot of perpendicular vectors should be 0
			Assert::AreEqual(a.Dot(b), 0.0f, 1e-5f, L"Dot product of perpendicular vectors should be zero.");

			// Dot of vector with itself should be its length squared
			Assert::AreEqual(c.Dot(c), 54.0f, 1e-5f, L"Dot product of vector with itself should equal squared magnitude.");
			// 2^2 + 3^2 + 4^2 + 5^2 = 4 + 9 + 16 + 25 = 54

			// Dot of two arbitrary vectors
			Vec4f d(1.0f, 0.0f, -1.0f, 2.0f);
			float expected = c.x * d.x + c.y * d.y + c.z * d.z + c.w * d.w;
			Assert::AreEqual(c.Dot(d), expected, 1e-5f, L"Dot product of c and d is incorrect.");
		}

	};
}
