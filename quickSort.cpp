#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int partition(vector<int> &nums,int start,int end){
	if(start == end)return start;
	srand(time(NULL));
	int key = rand()%(end - start) + start;
	swap(nums[key],nums[end]);
	int small = start;
	for(key = start; key <= end; ++key){
		if(nums[end] > nums[key]){
			if(small != start)
				swap(nums[small],nums[key]);
			++small;
		}
	}
	swap(nums[small],nums[end]);
	return small;
}
void quickSort(vector<int> &nums,int start,int end){
	if(start == end)return;
	int index = partition(nums,start,end);
	if(start < index)
		quickSort(nums,start,index-1);
	if(index < end)
		quickSort(nums,index+1,end);
}

void test(){
	vector<int> nums = {1,21,12,31,1,41,431,13,45,31,41,45,6,6,8,24,7,2};
	quickSort(nums,0,nums.size()-1);
	for(int a : nums){
		cout << a << " ";
	}
	cout << endl;
}

int main(){
	test();
	return 0;
}