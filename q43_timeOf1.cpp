#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;


int PowerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0; i < n; ++ i)
        result *= 10;

    return result;
}
int count(char* num){
	if(num == NULL || *num == '\0')
		return 0;
	int first = *num - '0';
	unsigned len = strlen(num);
	if(len == 1 && first == 0)
		return 0;
	if(len == 1 && first > 0)
		return 1;
	int ans = 0;
	if(first > 1){
		ans = PowerBase10(len-1);
		//ans = int(pow(10,len-1));
		cout << PowerBase10(len-1) << '\t' << int(pow(10.0,len-1)) << endl;
	}else if(first == 1){
		ans = atoi(num+1) + 1;
	}

	ans += first * (len - 1) * PowerBase10(len-2);
	cout << PowerBase10(len-2) << '\t' << int(pow(10.0,len-2)) << endl;
	//ans += first * (len - 1) * int(pow(10,len-2));
	ans += count(num+1);
	return ans;
}

int numberOf1(int n){
	int ans = 0;
	char num[20];
	sprintf(num,"%d",n);
	ans = count(num);
	cout << ans << endl;
	return ans;
}



void Test(const char* testName, int n, int expected)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);
    
    if(numberOf1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n"); 
    if(NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n"); 

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}