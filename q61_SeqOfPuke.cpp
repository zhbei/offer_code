#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

bool isSeq(vector<int> &nums){
	int size = nums.size();
	if(size == 0)return false;

	sort(nums.begin(),nums.end());

	int i = 0;
	while(i < size && nums[i] == 0)
		++i;

	int count = i;
	int gap = 0;
	while(i+1 < size){
		if(nums[i] >= nums[i+1])return false;
		gap += nums[i+1] - nums[i] -1;
		++i;
	}
	//cout << gap << '\t' << count << endl;
	return gap <= count ? true:false;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isSeq(numbers) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    vector<int> numbers = { 1, 3, 2, 5, 4 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    vector<int> numbers = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    vector<int> numbers = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    vector<int> numbers = { 0, 3, 1, 6, 4 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    vector<int> numbers = { 1, 3, 0, 5, 0 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    vector<int> numbers = { 1, 3, 0, 7, 0 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    vector<int> numbers = { 1, 0, 0, 5, 0 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    vector<int> numbers = { 1, 0, 0, 7, 0 };
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    vector<int> numbers = { 3, 0, 0, 0, 0 };
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    vector<int> numbers = { 0, 0, 0, 0, 0 };
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    vector<int> numbers = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
	vector<int> numbers;
    Test("Test12", numbers, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}