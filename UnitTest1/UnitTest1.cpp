#include "pch.h"
#include "CppUnitTest.h"
#include "../laba12.3.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;

			int x = 0;
			for (int i = 0; i < 4; i++)
			{
				x = i;
				Create(first, last, x);
			}

			Spusok* T = first;

			int v1 = 0, v2 = 5;

			T = first;
			Process(T, v1, v2, last);
			T = first;

			int l = T->link1->inf;
			Assert::AreEqual(l, 5);
		}
	};
}
