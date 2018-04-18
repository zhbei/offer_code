#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool sumOfK(vector<int> &nums,int key,int &num1,int &num2){
	int size = nums.size();
	if(size <= 1)return false;
	int left = 0,right = size - 1;
	while(left < right){
		int sum = nums[left] + nums[right];
		if(sum < key){
			++left;
		}else if(sum > key){
			--right;
		}else{
			num1 = nums[left];
			num2 = nums[right];
			return true;
		}
	}
	return false;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> data, int length, int sum, bool expectedReturn)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    
    int num1, num2;
    int result = sumOfK(data, sum, num1, num2);
    if(result == expectedReturn)
    {
        if(result)
        {
            if(num1 + num2 == sum)
                printf("Passed. \n");
            else
                printf("FAILED. \n");
        }
        else
            printf("Passed. \n");
    }
    else
        printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
    vector<int> data = {1, 2, 4, 7, 11, 15};
    Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
    vector<int> data = {1, 2, 4, 7, 11, 16};
    Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
    vector<int> data = {1, 2, 4, 7, 11, 16};
    Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
	vector<int> data;
    Test("Test4", data, 0, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}