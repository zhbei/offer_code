#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void print(int start,int end){
	for(int i = start; i <= end; ++i){
		cout << i << '\t';
	}
	cout << endl;
}
void sumOfK(int sum){
	int small = 1, big = 2;
	int middle = (sum + 1) >> 1;
	int cur = 3;

	while(small < middle){
		if(cur < sum){
			++big;
			cur += big;
		}else if(cur > sum){
			cur -= small;
			++small;
		}else{
			print(small,big);
			cur -= small;
			++small;
		}
	}
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    sumOfK(sum);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}
