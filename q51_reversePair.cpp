#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int reverseCore(vector<int> &nums,vector<int> &copy,int start,int end){
	if(start == end){
		copy[start] = nums[start];
		return 0;
	}

	int len = (end - start)/2;
	int left = reverseCore(copy,nums,start,start+len);
	int right = reverseCore(copy,nums,start+len+1,end);

	int i = start + len;
	int j = end;
	int copyj = end;
	int r = 0;
	while(i >= start && j >= start + len + 1){
		if(nums[i] > nums[j]){
			copy[copyj] = nums[i--];
			r += j - start - len;
		}else{
			copy[copyj] = nums[j--];
		}
		--copyj;
	}
	while(i >= start){
		copy[copyj--] = nums[i--];
	}
	while(j >= start + len + 1){
		copy[copyj--] = nums[j--];
	}
	return r + left + right;
}

int reversePair(vector<int> nums){
	int size = nums.size();
	if(size == 0)return 0;

	vector<int> copy(nums.begin(), nums.end());

	return reverseCore(nums,copy,0,size -1);
}

// ====================测试代码====================
void Test(char* testName, vector<int> data , int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(reversePair(data) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    vector<int> data = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    vector<int> data = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    vector<int> data = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    vector<int> data = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    vector<int> data = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    vector<int> data = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    vector<int> data = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;
	vector<int> data;
    Test("Test8", data, 0, expected);
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

    return 0;
}