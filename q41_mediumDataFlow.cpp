#include <iosteam>
#include <cstdio>

using namespace std;

template <typename T> class DynamicArray{
private:
	vector<T> minHeap;
	vector<T> maxHeap;
public:
	void insert(T num){
		if(((minHeap.size() + maxHeap.size()) & 1) == 0){
			if(maxHeap.size() > 0 && num < maxHeap[0]){
				maxHeap.push_back(num);
				push_heap(maxHeap.begin(),maxHeap.end(),less<T>());

				num = maxHeap[0];

				pop_heap(maxHeap.begin(),maxHeap.end(),less<T>());
				maxHeap.pop_back();
			}
			minHeap.push_back(num);
			push_heap(minHeap.begin(), minHeap.end(),greater<T>());
		}else{
			if(minHeap.size() > 0 && minHeap[0] < num){
				minHeap.push_back(num);
				push_heap(minHeap.begin(),minHeap.end(),greater<T>());

				num = minHeap[0];

				pop_heap(minHeap.begin(),minHeap.end(),greater<T>());
				minHeap.pop_back();
			}
			maxHeap.push_back(num);
			push_heap(max.begin(),max.end(),less<T>());
		}
	}
	T getMedium(){
		int size = minHeap.size() + maxHeap.size();
		if(size == 0){
			throw exception("No data !!");
		}
		T median;
		if((size & 1) == 0){
			median = (minHeap[0] + maxHeap[0]) >> 1;
		}else{
			median = minHeap[0];
		}
		return median;
	}
};

