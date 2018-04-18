#include <vector>
#include <cstdio>
using namespace std;

int maxSubSum_1(vector<int> nums){
	if(nums.size() == 0)
		return 0;
	int cur = 0;
	int maxS = 0x80000000;
	for(int a : nums){
		cur += a;
		maxS = max(maxS,cur);
		if(cur < 0){
			cur = 0;
		}
	}
	return maxS;
}
int maxSubSum_2(vector<int> nums){
	if(nums.size() == 0)return 0;
	vector<int> dp(nums.size()+1,0);
	int maxS = 0x80000000;
	for(int i = 0; i < (int)(nums.size());++i){
		if(dp[i] < 0){
			dp[i+1] = nums[i];
		}else{
			dp[i+1] = dp[i] + nums[i];
		}
		maxS = max(dp[i+1],maxS);
	}
	return maxS;
}
// ====================测试代码====================
void Test(char* testName, vector<int> pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = maxSubSum_1(pData);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
    result = maxSubSum_2(pData);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    vector<int> data = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    vector<int> data  = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    vector<int> data = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}