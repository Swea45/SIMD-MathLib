#include "pch.h"
#include "CppUnitTest.h"
#include "../MathLib/Matrix/Matrix4x4f/Matrix4x4f.h"
#include "../MathLib/Util/Random.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Matrix4x4f
{
	TEST_CLASS(Construction)
	{
	public:
		
		TEST_METHOD(Default)
		{
			Mat4x4f testMatrix;

			Assert::AreEqual(1.0f, testMatrix.p00, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p01, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p02, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p03, L"Default constructor did not create a identity matrix");
		
			Assert::AreEqual(0.0f, testMatrix.p10, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(1.0f, testMatrix.p11, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p12, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p13, L"Default constructor did not create a identity matrix");

			Assert::AreEqual(0.0f, testMatrix.p20, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p21, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(1.0f, testMatrix.p22, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p23, L"Default constructor did not create a identity matrix");

			Assert::AreEqual(0.0f, testMatrix.p30, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p31, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p32, L"Default constructor did not create a identity matrix");
			Assert::AreEqual(1.0f, testMatrix.p33, L"Default constructor did not create a identity matrix");

		}

		TEST_METHOD(With_Position)
		{
			Mat4x4f testMatrix({ 10.0f, 0.0f, 12.0f });

			Assert::AreEqual(1.0f, testMatrix.p00, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p01, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p02, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p03, L"Position constructor did not create a identity matrix");

			Assert::AreEqual(0.0f, testMatrix.p10, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(1.0f, testMatrix.p11, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p12, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p13, L"Position constructor did not create a identity matrix");

			Assert::AreEqual(0.0f, testMatrix.p20, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p21, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(1.0f, testMatrix.p22, L"Position constructor did not create a identity matrix");
			Assert::AreEqual(0.0f, testMatrix.p23, L"Position constructor did not create a identity matrix");

			Assert::AreEqual(10.0f, testMatrix.p30, L"Position constructor did not get correct x position");
			Assert::AreEqual(0.0f, testMatrix.p31, L"Position constructor did not get correct y position");
			Assert::AreEqual(12.0f, testMatrix.p32, L"Position constructor did not get correct z position");
			Assert::AreEqual(1.0f, testMatrix.p33, L"Position constructor did not create a identity matrix");

		}

		TEST_METHOD(Copy)
		{

			float size = 1000.0f;
			int runs = 1000;
			for (int i = 0; i < runs; i++)
			{
				Mat4x4f resultMatrix;
				//Randomize values
				{
					resultMatrix.p00 = BB::Random(-size, size);
					resultMatrix.p01 = BB::Random(-size, size);
					resultMatrix.p02 = BB::Random(-size, size);
					resultMatrix.p03 = BB::Random(-size, size);

					resultMatrix.p10 = BB::Random(-size, size);
					resultMatrix.p11 = BB::Random(-size, size);
					resultMatrix.p12 = BB::Random(-size, size);
					resultMatrix.p13 = BB::Random(-size, size);

					resultMatrix.p20 = BB::Random(-size, size);
					resultMatrix.p21 = BB::Random(-size, size);
					resultMatrix.p22 = BB::Random(-size, size);
					resultMatrix.p23 = BB::Random(-size, size);

					resultMatrix.p30 = BB::Random(-size, size);
					resultMatrix.p31 = BB::Random(-size, size);
					resultMatrix.p32 = BB::Random(-size, size);
					resultMatrix.p33 = BB::Random(-size, size);
				}

				//Check values
				{
					Mat4x4f testMatrix(resultMatrix);

					Assert::AreEqual(resultMatrix.p00, testMatrix.p00, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p01, testMatrix.p01, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p02, testMatrix.p02, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p03, testMatrix.p03, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p10, testMatrix.p10, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p11, testMatrix.p11, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p12, testMatrix.p12, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p13, testMatrix.p13, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p20, testMatrix.p20, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p21, testMatrix.p21, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p22, testMatrix.p22, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p23, testMatrix.p23, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p30, testMatrix.p30, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p31, testMatrix.p31, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p32, testMatrix.p32, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p33, testMatrix.p33, L"Copy constructor got the wrong value after copying");
				}
			}

		}

		TEST_METHOD(Copy_Rows)
		{

			float size = 1000.0f;
			int runs = 1000;
			for (int i = 0; i < runs; i++)
			{
				Mat4x4f resultMatrix;
				//Randomize values
				{
					resultMatrix.p00 = BB::Random(-size, size);
					resultMatrix.p01 = BB::Random(-size, size);
					resultMatrix.p02 = BB::Random(-size, size);
					resultMatrix.p03 = BB::Random(-size, size);

					resultMatrix.p10 = BB::Random(-size, size);
					resultMatrix.p11 = BB::Random(-size, size);
					resultMatrix.p12 = BB::Random(-size, size);
					resultMatrix.p13 = BB::Random(-size, size);

					resultMatrix.p20 = BB::Random(-size, size);
					resultMatrix.p21 = BB::Random(-size, size);
					resultMatrix.p22 = BB::Random(-size, size);
					resultMatrix.p23 = BB::Random(-size, size);

					resultMatrix.p30 = BB::Random(-size, size);
					resultMatrix.p31 = BB::Random(-size, size);
					resultMatrix.p32 = BB::Random(-size, size);
					resultMatrix.p33 = BB::Random(-size, size);
				}

				//Check values
				{
					Mat4x4f testMatrix(resultMatrix.row[0], resultMatrix.row[1], resultMatrix.row[2], resultMatrix.row[3]);

					Assert::AreEqual(resultMatrix.p00, testMatrix.p00, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p01, testMatrix.p01, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p02, testMatrix.p02, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p03, testMatrix.p03, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p10, testMatrix.p10, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p11, testMatrix.p11, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p12, testMatrix.p12, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p13, testMatrix.p13, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p20, testMatrix.p20, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p21, testMatrix.p21, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p22, testMatrix.p22, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p23, testMatrix.p23, L"Copy constructor got the wrong value after copying");

					Assert::AreEqual(resultMatrix.p30, testMatrix.p30, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p31, testMatrix.p31, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p32, testMatrix.p32, L"Copy constructor got the wrong value after copying");
					Assert::AreEqual(resultMatrix.p33, testMatrix.p33, L"Copy constructor got the wrong value after copying");
				}
			}

		}

	};

	TEST_CLASS(Operators)
	{
		TEST_METHOD(Equal)
		{
			//Identity test
			{
				Mat4x4f mat1;
				Mat4x4f mat2;
				Mat4x4f fMat1({ 10, 10, 10 });
				Assert::IsTrue(mat1 == mat2, L"Comparing two identity matrixes are not returning true");
				Assert::IsTrue(mat1 != fMat1, L"Comparing two different matrixes is returning wrong");
			}

			//Random values{
			{
				Mat4x4f mat1;
				Mat4x4f mat2;


				float size = 1000.0f;
				int runs = 1000;
				for (int i = 0; i < runs; i++)
				{
					mat1.p00 = mat2.p00 = BB::Random(-size, size);
					mat1.p01 = mat2.p01 = BB::Random(-size, size);
					mat1.p02 = mat2.p02 = BB::Random(-size, size);
					mat1.p03 = mat2.p03 = BB::Random(-size, size);

					mat1.p10 = mat2.p10 = BB::Random(-size, size);
					mat1.p11 = mat2.p11 = BB::Random(-size, size);
					mat1.p12 = mat2.p12 = BB::Random(-size, size);
					mat1.p13 = mat2.p13 = BB::Random(-size, size);

					mat1.p20 = mat2.p20 = BB::Random(-size, size);
					mat1.p21 = mat2.p21 = BB::Random(-size, size);
					mat1.p22 = mat2.p22 = BB::Random(-size, size);
					mat1.p23 = mat2.p23 = BB::Random(-size, size);

					mat1.p30 = mat2.p30 = BB::Random(-size, size);
					mat1.p31 = mat2.p31 = BB::Random(-size, size);
					mat1.p32 = mat2.p32 = BB::Random(-size, size);
					mat1.p33 = mat2.p33 = BB::Random(-size, size);

					Assert::IsTrue(mat1 == mat2, L"Comparing two matrixes is not returning correct");
				}
			}
		}

		TEST_METHOD(ADD)
		{
			Mat4x4f mat1;
			Mat4x4f mat2;

			float valueOne = 0.0f;
			float valueTwo = 0.0f;

			float size = 1000.0f;
			int runs = 1000;
			for (int i = 0; i < runs; i++)
			{
				float result[16];
				for (int i = 0; i < 16; i++)
				{
					valueOne = BB::Random(-siz0oe, size);
					valueTwo = BB::Random(-size, size);

					mat1.data[i] = valueOne;
					mat2.data[i] = valueTwo;
					result[i] = valueOne + valueTwo;
				}

				Mat4x4f resultMatrix = mat1 + mat2;

				for (int i = 0; i < 16; i++)
				{
					Assert::AreEqual(result[i], resultMatrix.data[i], L"Matrix adding is not done correctly");
				}
			}
		}

	};
}
