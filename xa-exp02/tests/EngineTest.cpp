#include "stdafx.h"
#include "CppUnitTest.h"

#include "core/Engine.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests {

	TEST_CLASS(EngineTest) {
	public:
		
		TEST_METHOD(EngineShouldBeInstantiable) {
			Engine engine;

			Assert::IsNotNull(&engine);
		}

	};
}