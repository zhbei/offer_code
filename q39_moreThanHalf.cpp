#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int moreThanHalf(vector<int> &nums){
	size_t len = nums.size();
	if(len == 0){
		return 0;
	}
	if(len <= 2)
		return nums[0];
	int result = nums[0];
	size_t count = 0;
	for(int i : nums){
		if(result == i){
			++count;
		}else{
			--count;
			if(count == 0){
				result = i;
				count = 1;
			}
		}
	}
	count = 0;
	for(int i: nums){
		if(i == result){
			++count;
		}
	}
	if(count*2 > len)
		return result;
	else
		return 0;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);


    printf("Test for solution1: ");
    int result = moreThanHalf(numbers);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    vector<int> numbers = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    vector<int> numbers = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    vector<int> numbers = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
   vector<int> numbers = {1};
   Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
	vector<int> numbers;
    Test("Test6", numbers, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}