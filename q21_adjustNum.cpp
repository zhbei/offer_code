#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void adjust(vector<int> &num){
	if(num.size() <= 1)return;

	size_t i = 0, j = num.size() -1;
	while(i < j){
		while(i < j && (num[i] & 0x01) == 1){
			++i;
		}
		while(j > i && (num[j] & 0x01) == 0){
			--j;
		}
		if(j <= i)return;
		if((num[i] & 0x01) == 0){
			swap(num[i],num[j]);
		}
		++i;--j;
	}
}
bool isEven(int num){
	return (num & 0x01) == 0;
}
void adjust_1(vector<int> &num,bool(*fun)(int)){
	if(num.size() <= 1)return;

	size_t i = 0, j = num.size() -1;
	while(i < j){
		while(i < j && !fun(num[i])){
			++i;
		}
		while(j > i && fun(num[j])){
			--j;
		}
		if(j <= i)return;
		if(!fun(num[i])){
			swap(num[i],num[j]);
		}
		++i;--j;
	}
}
// ====================测试代码====================
void PrintArray(vector<int> numbers)
{
    if(numbers.size() <= 0)
        return;

    for(size_t i = 0; i < numbers.size(); ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(char* testName, std::vector<int> numbers)
{
	int length = numbers.size();
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    vector<int> copy(length,0);
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers);
    adjust(numbers);
    PrintArray(numbers);

    printf("Test for solution 2:\n");
    PrintArray(copy);
    adjust_1(copy,&isEven);
    PrintArray(copy);

}

void Test1()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers);
}

void Test2()
{
    vector<int> numbers = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers);
}

void Test3()
{
    vector<int> numbers = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers);
}

void Test4()
{
    vector<int> numbers = {1,3,5,7,9};
    Test("Test4", numbers);
}

void Test5()
{
    vector<int> numbers = {2,4,6,8,10};
    Test("Test5", numbers);
}

void Test6()
{
	vector<int> numbers;
    Test("Test6", numbers);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}