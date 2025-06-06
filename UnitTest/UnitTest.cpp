#include "pch.h"
#include "CppUnitTest.h"
#include "..\MathLib\Vector3.h"

#include <chrono>
#include <iostream>
using namespace std::chrono;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class OtherVector3f
{
public:	
	float myX;
	float myY;
	float myZ;

	OtherVector3f() : myX(6.0f), myY(0.1f), myZ(52.1f){	}

};

class OtherVector4f
{
public:	
	float myX;
	float myY;
	float myZ;
	float myW;

	OtherVector4f() : myX(6.0f), myY(0.1f), myZ(52.1f), myW(15.0f) {}

};


namespace Vector3
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
	TEST_CLASS(Extra)
	{
		TEST_METHOD(Print)
		{
			Vec3f vec(1.11111f, 1.23456f, 1.98765f);
			const char* message = "X: 1.111 Y: 1.234 Z: 1.987";
			const char* actual = vec.C_str(); 
			Assert::IsTrue(actual == message && "C string is not equal");  
		}
	};
}
