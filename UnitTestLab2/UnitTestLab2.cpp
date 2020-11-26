#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2{
	TEST_CLASS(UnitTestLab2){
	private:
		const int n = 8;
		int a[8]{ 0, -5, -45, 75, -3, 67, 0, 4 };
		char b[8]{ 'a', '6', '0', '!', 'D', '}', '?', 'A' };
		int c[8]{ -54, 0, 0, 0, 3, 4, 4, 5 };
		int d[6]{ 4, 3, 3, 0, 0, -4 };
	public:
		TEST_METHOD_INITIALIZE(init) {
		}
		TEST_METHOD(testBinarySearch){
			Assert::AreEqual(BinarySearch(c, n, 3), 4);
			Assert::AreEqual(BinarySearch(c, n, 0), 3);
			Assert::AreEqual(BinarySearch(c, n, 4), 5);
			Assert::AreEqual(BinarySearch(c, n, -54), 0);
			Assert::AreEqual(BinarySearch(c, n, 1), -1);
		}
		TEST_METHOD(testQuickSort) {
			int l = 0;
			int r = n - 1;
			QuickSort(a, l, r);
			Assert::AreEqual(a[0], -45);
			Assert::AreEqual(a[1], -5);
			Assert::AreEqual(a[2], -3);
			Assert::AreEqual(a[3], 0);
			Assert::AreEqual(a[4], 0);
			Assert::AreEqual(a[5], 4);
			Assert::AreEqual(a[6], 67);
			Assert::AreEqual(a[7], 75);
		}
		TEST_METHOD(testBubbleSort) {
			BubbleSort(a, n);
			Assert::AreEqual(a[0], -45);
			Assert::AreEqual(a[1], -5);
			Assert::AreEqual(a[2], -3);
			Assert::AreEqual(a[3], 0);
			Assert::AreEqual(a[4], 0);
			Assert::AreEqual(a[5], 4);
			Assert::AreEqual(a[6], 67);
			Assert::AreEqual(a[7], 75);
		}
		TEST_METHOD(testBogoSort) {
			BogoSort(d, 6);
			Assert::AreEqual(d[0], -4);
			Assert::AreEqual(d[1], 0);
			Assert::AreEqual(d[2], 0);
			Assert::AreEqual(d[3], 3);
			Assert::AreEqual(d[4], 3);
			Assert::AreEqual(d[5], 4);
		}
		TEST_METHOD(testCountingSort) {
			CountingSort(b, n);
			Assert::AreEqual(b[0], '!');
			Assert::AreEqual(b[1], '0');
			Assert::AreEqual(b[2], '6');
			Assert::AreEqual(b[3], '?');
			Assert::AreEqual(b[4], 'A');
			Assert::AreEqual(b[5], 'D');
			Assert::AreEqual(b[6], 'a');
			Assert::AreEqual(b[7], '}');
		}
	};
}
