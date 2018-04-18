#include <iostream>
#include <cstdio>
#include <vector>

int indexEqual(vector<int> &nums){
	int size = nums.size();

	if(size == 0) return 0;

	int left = 0, right = size - 1;
	while(left < right){
		int mid = (left + right) >> 1;
		if(mid < nums[mid]){
			right = mid - 1;
		}else if(mid > nums[mid]){
			left = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}