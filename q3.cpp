#include <iostream>
#include <vector>

using namespace std;

int getRepartNum(vector<int> &nums){
	int size = nums.size();
	if(size == 0)return -1;
	for(int i = 0; i < size;){
		if(nums[i] != i){
			if(nums[i] == nums[nums[i]]){
				return nums[i];
			}
			swap(nums[i],nums[nums[i]]);
		}else{
			++i;
		}
	}
	return -1;
}
void test(){
	vector<int> nums = {1,2,3,4,5,6,7,8,9,1};
	cout << getRepartNum(nums) << endl;
}
void test1(){
	vector<int> nums = {0,0,3,4,5,6,7,8,9,0};
	cout << getRepartNum(nums) << endl;
}
void test2(){
	vector<int> nums = {1,2,3,4,5,6,7,8,9,0};
	cout << getRepartNum(nums) << endl;
}
void test3(){
	vector<int> nums = {1,2,3,4,5,5,7,8,9,1};
	cout << getRepartNum(nums) << endl;
}
int main(){
	test();
	test1();
	test2();
	test3();
	return 0;
}