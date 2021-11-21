#include "CppUnitTest.h"
#include "../Intellias SDET Camp Technical Task/Union.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntelliasSDETCampTechnicalTaskUnitTests
{
	TEST_CLASS(UnionTests)
	{
		
	public:


		TEST_METHOD(ConnectedTesst1)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 0, 1 });
			arr.push_back({ 1, 0 });
			Assert::IsFalse(un.Connected(arr));			
		}

		TEST_METHOD(ConnectedTesst2)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 0 });
			try
			{
				un.Connected(arr);
				Assert::Fail();
			}
			catch (std::exception) {}			
		}

		TEST_METHOD(ConnectedTesst3)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 0, 1 });
			arr.push_back({ 1 });
			try
			{
				un.Connected(arr);
				Assert::Fail();
			}
			catch (std::exception) {}
		}

		TEST_METHOD(ConnectedTesst4)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 0, 1 });
			arr.push_back({ 1, 0, 0 });
			try
			{
				un.Connected(arr);
				Assert::Fail();
			}
			catch (std::exception) {}
		}

		TEST_METHOD(ConnectedTesst5)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 1, 1, 1, 0, 0 });
			arr.push_back({ 1, 0, 1, 0, 0 });
			arr.push_back({ 0, 0, 1, 1, 1 });
			arr.push_back({ 1, 0, 1, 0, 1 });
			arr.push_back({ 1, 0, 0, 0, 1 });
			Assert::IsTrue(un.Connected(arr));
		}

		TEST_METHOD(ConnectedTesst6)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 1, 1, 1, 0, 0 });
			arr.push_back({ 1, 0, 1, 0, 0 });
			arr.push_back({ 0, 0, 0, 1, 1 });
			arr.push_back({ 1, 0, 1, 0, 1 });
			arr.push_back({ 1, 0, 0, 0, 1 });
			Assert::IsFalse(un.Connected(arr));
		}

		TEST_METHOD(ConnectedTesst7)
		{
			Union un;
			vector<vector<int>> arr;
			arr.push_back({ 1, 0, 0, 0, 0 });
			arr.push_back({ 0, 1, 0, 0, 0 });
			arr.push_back({ 0, 0, 1, 0, 0 });
			arr.push_back({ 0, 0, 0, 1, 0 });
			arr.push_back({ 0, 0, 0, 0, 1 });
			Assert::IsFalse(un.Connected(arr));
		}
	};
}
