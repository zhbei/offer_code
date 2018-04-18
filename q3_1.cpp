#include <iostream>
#include <vector>

using namespace std;

int coutRang(int left,int right,vector<int> nums){
	int count = 0;
	for(auto it = nums.begin(); it != nums.end(); ++it){
		if(*it > left && *it <= right){
			++count;
		}
	}
	return count;
}

int findRepeat(vector<int> & nums){
	int size = nums.size();
	if(size <= 1)return -1;
	int left = 0, right = size -1;
	while(left < right){
		int mid = left + (right - left + 1) / 2;
		if(coutRang(left,mid - 1,nums) > mid - left - 1){
			right = mid - 1;
		}else if(coutRang(mid,right,nums) > right - mid){
			left = mid;
		}else{
			return mid;
		}
	}
	return -1;
}
int findRepeat1(vector<int> &nums){
	int size = nums.size();
	if(size <= 1)return -1;
	vector<bool> visited(size-1,false);
	for(auto it = nums.begin(); it != nums.end(); ++it){
		if(visited[*it])return *it;
		visited[*it] = true;
	}
	return -1;
}
void test1(){
	std::vector<int> v;
	cout << findRepeat(v) << endl;	
	cout << findRepeat1(v) << endl;
}
void test2(){
	std::vector<int> v = {10,2,3,4,5,6,7,8,9,1,10,11,12,13};
	cout << findRepeat(v) << endl;	
	cout << findRepeat1(v) << endl;
}
void test3(){
	std::vector<int> v = {1,1,1,1,1,1,1,1};
	cout << findRepeat(v) << endl;	
	cout << findRepeat1(v) << endl;
}
void test4(){
	std::vector<int> v = {1,1,2,2,3,3,4,4,5,5,6,6};
	cout << findRepeat(v) << endl;	
	cout << findRepeat1(v) << endl;
}
int main(){
	test1();
	test2();
	test3();
	test4();
	return 0;
}