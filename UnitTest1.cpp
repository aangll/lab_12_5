#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_5/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* top = nullptr;
            bool found;
            
            pushWordToStack(top, "word");
            pushWordToStack(top, "world");
            pushWordToStack(top, "lord");
            pushWordToStack(top, "windows");

                if (top->value == "windows")
                {
                   found = true;
                }
               
            
            Assert::IsTrue(found);


		}
	};
}
