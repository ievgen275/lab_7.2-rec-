#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.2(rec)/PR_7.2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSearchMinEven)
		{
			const int n = 3;
			const int k = 4;
			int** a = new int* [n];
			for (int i = 0; i < n; i++) {
				a[i] = new int[k];
			}

			a[0] = new int[k] {5, 3, 9, 2};
			a[1] = new int[k] {7, 1, 4, 6};
			a[2] = new int[k] {8, 2, 5, 3};

			int minEven = INT_MAX;
			SearchMinEven(a, n, k, minEven, 0, 0);

			Assert::AreEqual(8, minEven);

			for (int i = 0; i < n; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
