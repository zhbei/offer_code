#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int maxProfit(vector<int> &mums){
	int size = nums.size();
	int minPrice = nums[0];
	int ans = 0;
	for(int i = 1; i < size; ++i){
		if(nums[i] < minPrice){
			minPrice = nums[i];
		}
		int tmp = nums[i] - minPrice;
		if(tmp > ans){
			ans = tmp;
		}
	}
	return ans;
}

