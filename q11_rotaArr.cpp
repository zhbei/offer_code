#include <iostream>
#include <vector>
using namespace std;

int seqmin(vector<int> &nums){
	int ans = INT_MAX;
	for(int a : nums){
		if(a < ans){
			ans = a;
		}
	}
	return ans;
}
int min(vector<int> &nums){
	if(nums.size() <= 0) return 0;
	int left = 0,right = nums.size()-1,mid = 0;
	while(nums[left] >= nums[right]){
		if(right - left == 1){
			return nums[right];
		}
		if(nums[left] == nums[mid] && nums[mid] == nums[right]){
			return seqmin(nums);
		}
		if(nums[left] <= nums[mid]){
			left = mid+1;
		}else if(nums[right] >= nums[mid]){
			right = mid; 
		}
	}
	return nums[left];
}
void test(){
	vector<int> nums = {1,1,2,0,1,1,1,1,1};
	cout << min(nums) << endl;
}
int main(){
	test();
}