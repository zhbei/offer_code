#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

int lower(vector<int> &nums,int start,int end,int key){
	if(nums.size() == 0){
		return -1;
	}
	int mid;
	while(start < end){
		mid = start + (end - start)/2;
		if(nums[mid]  == key){
			if(mid == 0 || nums[mid-1] < key){
				return mid;
			}else{
				end = mid;
			}
		}else if(nums[mid] > key){
			end = mid;
		}else{
			start = mid + 1;
		}
	}
	return -1;
}
int upper(vector<int> &nums,int start,int end,int key){
	if(nums.size() == 0){
		return -1;
	}
	int mid;
	while(start < end){
		mid = start + (end - start)/2;
		if(nums[mid]  == key){
			if(mid + 1 == (int)nums.size() || nums[mid+1] > key){
				return mid;
			}else{
				start = mid;
			}
		}else if(nums[mid] > key){
			end = mid;
		}else{
			start = mid + 1;
		}
	}
	return  -1;
}
int repeat(vector<int> &nums,int key){
	if(nums.size() == 0)return 0;
	int start = lower(nums,0,nums.size(),key);
	int end = upper(nums,0,nums.size(),key);
	//cout << start << '\t' << end << endl;
	if(start != -1 && end != -1)
		return end - start + 1;
	else
		return 0;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> data, int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = repeat(data, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    vector<int> data = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    vector<int> data = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    vector<int> data = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    vector<int> data = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    vector<int> data = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    vector<int> data = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    vector<int> data = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    vector<int> data = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    vector<int> data = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    vector<int> data = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
	vector<int> data;
    Test("Test11", data, 0, 0, 0);
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

    return 0;
}