#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxProduct(int n){
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	vector<int> product(n+1,0);

	product[1] = 1;
	product[2] = 2;
	product[3] = 3;
	int max = 0;
	for(int i = 4; i <= n; ++i){
		max = 0;
		for(int j = 1; j <= i/2; ++j){
			int products = product[j] * product[i-j];
			if(max < products){
				max = products;
			}
		}
		product[i] = max;
	}
	max = product[n];
	return max;
}

int maxProduct_greed(int n){
	if(n < 2)
		return 0;
	if(n == 2)
		return 1;
	if(n == 3)
		return 2;
	int ans = 1;
	int num = n/3;
	int mod = n%3;
	ans = pow(3,num);
	if(mod == 1){
		ans = ans/3 * 4;
	}else if(mod == 2){
		ans = pow(3,num)*2;
	}
	return ans;
}
// ====================测试代码====================
void test(const char* testName, int length, int expected)
{
    int result1 = maxProduct(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProduct_greed(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}
