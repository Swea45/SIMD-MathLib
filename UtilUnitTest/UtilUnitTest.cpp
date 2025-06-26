#include "pch.h"
#include "CppUnitTest.h"
#include "..\MathLib\Util\Random.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Random
{
	TEST_CLASS(RandomFunction)
	{
		TEST_METHOD(Int)
		{
			const int minValue = 5;
			const int maxValue = 100;

			const int runs = 100;
			for (int i = 0; i < runs; i++)
			{
				int random = BB::Random(minValue, maxValue);

				Assert::IsTrue(random >= minValue, L"Random int is geting lower values then min value");
				Assert::IsTrue(random <= maxValue, L"Random int is geting larger values then min value");
			}

			BB::GlobalRandomEngine.seed(1);

			int random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 45, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 100, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 74, L"Seeded random is not seeded corectly");
		}

		TEST_METHOD(Float)
		{
			const float minValue = 5.0f;
			const float maxValue = 100.0f;

			const int runs = 100;
			for (int i = 0; i < runs; i++)
			{
				float random = BB::Random(minValue, maxValue);

				Assert::IsTrue(random >= minValue, L"Random int is geting lower values then min value");
				Assert::IsTrue(random <= maxValue, L"Random int is geting larger values then min value");
			}

			BB::GlobalRandomEngine.seed(1);

			float random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 44.6170883f, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 99.7325592f, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 73.4308319f, L"Seeded random is not seeded corectly");

		}

		TEST_METHOD(Double)
		{
			const double minValue = 5.0;
			const double maxValue = 100.0;

			const int runs = 100;
			for (int i = 0; i < runs; i++)
			{
				double random = BB::Random(minValue, maxValue);

				Assert::IsTrue(random >= minValue, L"Random int is geting lower values then min value");
				Assert::IsTrue(random <= maxValue, L"Random int is geting larger values then min value");
			}

			BB::GlobalRandomEngine.seed(1);

			double random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 99.732556781875232, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 93.592949329975724, L"Seeded random is not seeded corectly");
			random = BB::Random(minValue, maxValue);
			Assert::IsTrue(random == 17.171822538369071, L"Seeded random is not seeded corectly");
		}
	};
}