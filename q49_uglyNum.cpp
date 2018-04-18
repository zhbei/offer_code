#include <iostream>
#include <vector>
using namespace std;

bool isUgly(int num){
	while(num%2 == 0)
		num /= 2;
	while(num%3 == 0)
		num /= 3;
	while(num%5 == 0)
		num /= 5;
	return num == 1;
}
int uglyNum_1(int num){
	if(num <= 0) return 0;
	if(num == 1) return 1;
	int count = 1;
	int i = 1;
	while(count < num){
		++i;
		if(isUgly(i)){
			++count;
		}
	}
	return i;
}
int uglyNum_2(int num){
	if(num <= 0)return 0;
	if(num == 1)return 1;
	vector<int> ugly(num,-1);
	int u2 = 0,u3 = 0,u5 = 0;
	ugly[0] = 1;
	int next = 1;
	while(next < num){
		int nextNum = min(2*ugly[u2],min(3*ugly[u3],5*ugly[u5]));
		ugly[next] = nextNum;
		while(ugly[u2] * 2 <= nextNum)
			++u2;
		while(ugly[u3] * 3 <= nextNum)
			++u3;
		while(ugly[u5] * 5 <= nextNum)
			++u5;
		++next; 
	}
	return ugly[next-1];
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(uglyNum_1(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");

    if(uglyNum_2(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}

