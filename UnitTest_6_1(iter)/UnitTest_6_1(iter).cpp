#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_6_1(iter)\Lab_6_1(iter)\Lab_6_1(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61iter
{
	TEST_CLASS(UnitTest61iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 1;
			int a[n];
			int S = 0;
			int z = 0;
			a[0] = 13;

			Search(a, n, z, S);
			Assert::AreEqual(S, 0);
		}
	};
}
