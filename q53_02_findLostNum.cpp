#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int lostNum(vector<int> &nums){
	int size = nums.size();
	if(size == 0)return -1;
	if(size == 1)return nums[0] == 0 ? 1 : 0;
	int left = 0, right = size - 1;
	while(left <= right)
	{
		int mid = (left + right) >> 1;
		if(mid == nums[mid]){
			if(mid + 1 == size || nums[mid+1] == mid+2){
				return mid+1;
			}else{
				left = mid + 1;
			}
		}else if(mid < nums[mid]){
			if(mid == 0 || mid - 1 == nums[mid-1]){
				return mid;
			}else{
				right = mid - 1;
			}
		}
	}
	return -1;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = lostNum(numbers);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    int expected = 0;
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
    vector<int> numbers = { 0, 1, 2, 3, 4 };
    int expected = 5;
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
    vector<int> numbers = { 0, 1, 2, 4, 5 };
    int expected = 3;
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    vector<int> numbers = { 1 };
    int expected = 0;
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    vector<int> numbers = { 0 };
    int expected = 1;
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
    int expected = -1;
    vector<int> numbers;
    Test("Test6", numbers, 0, expected);
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