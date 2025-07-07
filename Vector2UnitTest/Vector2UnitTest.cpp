#include "pch.h"
#include "CppUnitTest.h"
#include "..\MathLib\Vector\Vec2f.h"
#include "..\MathLib\Util\Random.h"
#include "..\MathLib\Util\CommonMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector2f_Scalar
{
	TEST_CLASS(Define)
	{
	public:
#ifdef Vec2fBasic
		TEST_METHOD(Scalar)
		{
			Vector2fScalar fullNameVec(50.0f, 25.0f);
			Vec2f shortcutVec(50.0f, 25.0f);

			Assert::IsTrue(fullNameVec == shortcutVec, L"Defining Scalar vector2 to Vec2f is not working");
		}
#else

#endif // Vec2fBasic

	};


	TEST_CLASS(Construction)
	{
	public:
		TEST_METHOD(Default)
		{
			Vec2f testVector;

			Assert::AreEqual(testVector.x, 0.0f);
			Assert::AreEqual(testVector.y, 0.0f);
		}

		TEST_METHOD(Parameter)
		{
			Vec2f testVector(1, 2);
			Assert::AreEqual(1.0f, testVector.x, L"X is not assigned correctly", LINE_INFO());
			Assert::AreEqual(2.0f, testVector.y, L"Y is not assigned correctly", LINE_INFO());

			Vec2f negativeTestVector(-1, -2);
			Assert::AreEqual(-1.0f, negativeTestVector.x, L"X is not assigned correctly", LINE_INFO());
			Assert::AreEqual(-2.0f, negativeTestVector.y, L"Y is not assigned correctly", LINE_INFO());

			Vec2f assignedVector = { 1, 2 };
			Assert::AreEqual(1.0f, assignedVector.x, L"X is not assigned correctly", LINE_INFO());
			Assert::AreEqual(2.0f, assignedVector.y, L"Y is not assigned correctly", LINE_INFO());

		}

		TEST_METHOD(SingleParamter)
		{
			Vec2f testVector(5.0f);
			Assert::AreEqual(5.0f, testVector.x, L"X is not assigned correctly with single parameter");
			Assert::AreEqual(5.0f, testVector.y, L"Y is not assigned correctly with single parameter");
			
			Vec2f negativeTestVector(-5.0f);
			Assert::AreEqual(-5.0f, negativeTestVector.x, L"X is not assigned correctly with single parameter");
			Assert::AreEqual(-5.0f, negativeTestVector.y, L"Y is not assigned correctly with single parameter");
		}

		TEST_METHOD(Copy)
		{
			const Vec2f originalVector(5.0f, 10.0f);
			Vec2f testVector(originalVector);
			
			Assert::AreEqual(testVector.x, originalVector.x, L"X is not copied correctly");
			Assert::AreEqual(testVector.y, originalVector.y, L"Y is not copied correctly");
		}
	};

	TEST_CLASS(Operators)
	{
	public:
		TEST_METHOD(Equals)
		{
			Vec2f vec1(50.0f, 100.0f);
			Vec2f vec2(50.0f, 100.0f);
			Vec2f vec3(100.0f, 150.0f);

			Assert::IsTrue(vec1 == vec2, L"Vector is not comparing correctly");
			Assert::IsFalse(vec1 == vec3, L"Vector is not comparing correctly");

			Assert::IsTrue(vec1 != vec3, L"Vector is not comparing correctly");
			Assert::IsFalse(vec1 != vec2, L"Vector is not comparing correctly");
		}

		TEST_METHOD(Add)
		{
			Vec2f vec1(50.0f, 100.0f);
			Vec2f vec2(50.0f, 100.0f);
			Vec2f vec3(100.0f, 200.0f);

			Vec2f difVec = vec1 + vec2;
			Assert::IsTrue(difVec == vec3 && "Vector not adding correctly");

			Vec2f sammeVec = vec1 + vec1;
			Assert::IsTrue(sammeVec == vec3 && "Vector not adding correctly");

			vec1 += vec2;
			Assert::IsTrue(vec1 == vec3 && "Vector not adding correctly");

			Vec2f maxVec(FLT_MAX);

			Vec2f overflowVec = maxVec + maxVec;
			Assert::IsTrue(std::isinf(overflowVec.x) && "Vector X did not result in a overflow");
			Assert::IsTrue(std::isinf(overflowVec.y) && "Vector Y did not result in a overflow");
		}

		TEST_METHOD(Sub)
		{
			Vec2f vec1(50.0f, 100.0f);
			Vec2f vec2(50.0f, 100.0f);
			Vec2f vec3(100.0f, 200.0f);

			Vec2f difVec = vec3 - vec1;
			Assert::IsTrue(difVec == vec2 && "Vector not subtracting correctly");

			Vec2f sammeVec = vec1 - vec1; 
			Assert::IsTrue(sammeVec == Vec2f(0, 0) && "Vector not subtracting correctly");

			vec3 -= vec2;
			Assert::IsTrue(vec3 == vec1 && "Vector not subtracting correctly");

		}

		TEST_METHOD(Mul_Vec)
		{
			Vec2f vec1(50.0f, 100.0f);
			Vec2f vec2(50.0f, 100.0f);

			Vec2f difVec = vec1 * vec2;
			Assert::IsTrue(difVec == Vec2f(2500.0f, 10000.0f) && "Vector not multiplying with vector correctly");

			Vec2f sammeVec = vec1 * vec1;
			Assert::IsTrue(sammeVec == Vec2f(2500.0f, 10000.0f) && "Vector not multiplying with vector correctly");

			vec1 *= vec2;
			Assert::IsTrue(vec1 == Vec2f(2500.0f, 10000.0f) && "Vector not multiplying with vector correctly");
		}

		TEST_METHOD(Mul_Scalar)
		{
			Vec2f vec1 = { 5.0f, 10.0f }; 
			float scalar = 5.0f;
			const Vec2f result = { 5.0f * scalar, 10.0f * scalar};

			Assert::IsTrue(vec1 * scalar == result && "Vector not multiplying with scalar correctly");
			Assert::IsTrue(scalar * vec1 == result && "Vector not multiplying with scalar correctly");

			Assert::IsTrue(vec1 * 5 == result && "Vector not multiplying with scalar correctly");
			Assert::IsTrue(5 * vec1 == result && "Vector not multiplying with scalar correctly");

			vec1 *= scalar;
			Assert::IsTrue(vec1 == result && "Vector not multiplying with scalar correctly");
		}

		TEST_METHOD(Div)
		{
			Vec2f vec1(5.0f, 1.0f);
			Vec2f vec2(10.0f, 2.0f); 
			float scalar = 5.0f;

			Vec2f difVec = vec1 / vec2;
			Assert::IsTrue(difVec == Vec2f(0.5f, 0.5f) && "Vector not dividing correctly");

			Vec2f sammeVec = vec1 / vec1;
			Assert::IsTrue(sammeVec == Vec2f(1.0f, 1.0f) && "Vector not dividing correctly");

			Vec2f scalarVec = vec1 / scalar;
			Assert::IsTrue(scalarVec == Vec2f(1.0f, 0.2f) && "Vector not dividing with scalar correctly");

			vec1 /= vec1;
			Assert::IsTrue(vec1 == Vec2f(1.0f, 1.0f) && "Vector not dividing correctly");

			vec2 /= 2.0f;
			Assert::IsTrue(vec2 == Vec2f(5.0f, 1.0f) && "Vector not dividing correctly");
		}

		TEST_METHOD(UnaryNegation)
		{

			Vec2f vec1(5.0f, -1.0f);
			Vec2f falseResult(5.0f, 1.0f);
			Vec2f result(-5.0f, 1.0f);

			Assert::IsTrue(-vec1 == result);
			Assert::IsFalse(-vec1 == falseResult);
			Assert::IsFalse(-vec1 == vec1);
		}
	};

	TEST_CLASS(Functions)
	{
	public:
		TEST_METHOD(LengthSqr)
		{
			Vec2f vec(3.0f, 4.0f); 
			Assert::AreEqual(vec.LengthSqr(), 25.0f, L"LengthSqr is not returning correct length");
		}

		TEST_METHOD(Length)
		{
			Vec2f vec(3.0f, 4.0f);
			Assert::AreEqual(vec.Length(), 5.0f, L"Length is not returning correct length");

			int runs = 100;
			const float scale = 1000.0f;
			for (int i = 0; i < runs; i++)
			{
				const float x = BB::Random(-scale, scale);
				const float y = BB::Random(-scale, scale);

				Vec2f randomVec(x, y);
				float correct = sqrt((x * x) + (y * y)); 

				Assert::IsTrue(randomVec.Length() == correct, L"Length is not returning correct length");
			}
		}
		TEST_METHOD(Normalize)
		{
			// Create new Vector that is Normalized
			{
				Vec2f single(1.0f, 0.0f);
				Assert::IsTrue(single.GetNormalized() == single, L"Normalizing is not done properly");

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);

					Vec2f randomVec(x, y);
					float length = sqrt((x * x) + (y * y));
					Vec2f correct = randomVec / length;

					Assert::IsTrue(randomVec.GetNormalized() == correct, L"Normalizing is not done properly");
				}
			}

			// Normalize the current vector
			{
				Vec2f single(1.0f, 0.0f);
				Vec2f singleCorrect(1.0f, 0.0f);
				single.Normalize();
				Assert::IsTrue(single == singleCorrect, L"Normalizing is not done properly");

				int runs = 100;
				const float scale = 100.0f;
				for (int i = 0; i < runs; i++)
				{
					const float x = BB::Random(-scale, scale);
					const float y = BB::Random(-scale, scale);

					Vec2f randomVec(x, y);
					float length = sqrt((x * x) + (y * y));
					Vec2f correct = randomVec / length;

					randomVec.Normalize();
					Assert::IsTrue(randomVec == correct, L"Normalizing is not done properly");
				}
			}
		}

		TEST_METHOD(Dot)
		{
			Vec2f a(1.0f, 0.0f); 
			Vec2f b(0.0f, 1.0f); 
			Vec2f c(2.0f, 3.0f); 

			// Dot of perpendicular vectors should be 0
			Assert::AreEqual(0.0f, a.Dot(b), 1e-5f, L"Dot product of perpendicular vectors should be zero.");

			// Dot of vector with itself should be its length squared
			Assert::AreEqual(13.0f, c.Dot(c), 1e-5f, L"Dot product of vector with itself should equal squared magnitude.");

			// Dot of two arbitrary vectors
			Vec2f d(1.0f, 0.0f);
			float expected = c.x * d.x + c.y * d.y; 
			Assert::AreEqual(c.Dot(d), expected, 1e-5f, L"Dot product of c and d is incorrect.");
		}

		TEST_METHOD(DistanceTo)
		{
			Vec2f startVec(5.0f, 10.0f);
			Vec2f endVec(10.0f, -10.0f);

			Assert::IsTrue(startVec.DistanceTo(startVec) == Vec2f(0.0f, 0.0f), L"DistansTo on a object on the same place is not correct");
			Assert::IsTrue(startVec.DistanceTo(endVec) == Vec2f(5.0f, -20.0f), L"DistansTo on a object on another position is not correct");
		}

		TEST_METHOD(Rotate_InPlace)
		{
			Vec2f v(1.0f, 0.0f); 
			v.Rotate(static_cast<float>(BB::PI_F / 2));  // 90 degrees

			Vec2f expected(0.0f, 1.0f);

			Assert::IsTrue(BB::AlmostEqual(v.x, expected.x), L"RotateZ did not produce expected result.");
			Assert::IsTrue(BB::AlmostEqual(v.y, expected.y), L"RotateZ did not produce expected result.");
		}

		TEST_METHOD(GetRotatedZ_ReturnsNew)
		{
			Vec2f v(1.0f, 0.0f);
			Vec2f result = v.GetRotated(static_cast<float>(BB::PI_F / 2));

			Vec2f expected(0.0f, 1.0f); 

			Assert::IsTrue(BB::AlmostEqual(result.x, expected.x), L"GetRotatedZ did not return expected vector.");
			Assert::IsTrue(BB::AlmostEqual(result.y, expected.y), L"GetRotatedZ did not return expected vector.");
		}
	};
}
