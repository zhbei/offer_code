#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
int partition(vector<int> &nums,int start,int end){
	if(end == start)return start;
	srand(time(NULL));
	int key = rand()%(end - start + 1) + start;
	swap(nums[key],nums[end]);
	for(key = start; key < end; ++key){
		if(nums[key] < nums[end]){
			if(key != start){
				swap(nums[key],nums[start]);
			}
			++start;
		}
	}
	swap(nums[start],nums[end]);
	return start; 
}
vector<int> minmunK(vector<int> &nums,int k){
	int size = nums.size();
	vector<int> ans;
	if(k <= 0)return ans; 
	if(size < k)return ans;

	int index = partition(nums,0,size - 1);
	int start = 0;
	int end = size -1;
	while(index != k-1){
		if(index > k-1){
			end = index - 1;
			index = partition(nums,start,end);
		}else{
			start = index + 1;
			index = partition(nums,start,end);
		}
	}
	for(int i = 0; i < k; ++i){
		ans.push_back(nums[i]);
	}
	return ans;
} 
vector<int> minmumK_2(vector<int> nums,int k){
	int size = nums.size();
	if(k <= 0)return vector<int>(); 
	if(size < k)return vector<int>();

	multiset<int,greater<int>> ans;
	for(int i : nums){
		if(ans.size() < k){
			ans.insert(i);
		}else{
			int biggest = *(ans.begin());
			if(i < biggest){
				ans.erase(ans.begin());
				ans.insert(i);
			}
		}
	}
	vector<int> anss(ans.begin(),ans.end());
	return anss;
}
// ====================测试代码====================
void Test(const char* testName, vector<int> data, int n, vector<int> expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    printf("Expected result: \n");
    for(int i = 0; i < expectedResult.size() ; ++ i)
        printf("%d\t", expectedResult[i]);
    printf("\n");

    printf("Result for solution1:\n");
    vector<int> output = minmunK(data, k);

    for(int i = 0; i < output.size(); ++ i)
        printf("%d\t", output[i]);
    printf("\n");

    vector<int> outputa = minmumK_2(data, k);

    for(int i = 0; i < outputa.size(); ++ i)
        printf("%d\t", outputa[i]);
    printf("\n");

}

// k小于数组的长度
void Test1()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1, 2, 3, 4};
    Test("Test1", data, sizeof(data) / sizeof(int), expected, 4);
}

// k等于数组的长度
void Test2()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, sizeof(data) / sizeof(int), expected, 8);
}

// k大于数组的长度
void Test3()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected;
    Test("Test3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test4()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1};
    Test("Test4", data, sizeof(data) / sizeof(int), expected, 1);
}

// k等于0
void Test5()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected;
    Test("Test5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test6()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 2, 8};
    vector<int> expected = {1, 2};
    Test("Test6", data, sizeof(data) / sizeof(int), expected,2);
}

// 输入空指针
void Test7()
{
    vector<int> expected;
    Test("Test7", expected, 0, expected, 0);
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

    return 0;
}
