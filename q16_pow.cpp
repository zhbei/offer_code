#include <iostream>

using namespace std;
bool g_InvalidInput = false;
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
double myPow(double base,int n){
	g_InvalidInput = false;
	if(equal(base,0.0) && n < 0){
		g_InvalidInput = true;
		return 0.0;
	}
	if(n == 0)return 1.0;
	if(n == 1)return base;
	unsigned p = 0;
	bool minus = false;
	if(n < 0){
		p = -n;
		minus = true;
	}else{
		p = n;
	}
	double ans = 1;
	while(p){
		ans *= base;
		--p;
	}
	if(minus){
		ans = 1/ans;
	}
	return ans;
}
double unsignedPow(double base, unsigned p){
	if(p == 1)return base;
	double ans = unsignedPow(base, p >> 1);
	ans *= ans;
	if(p & 0x01)
		ans *= base;
	return ans;
}
double myPow_1(double base, int n){
	if(equal(base,0.0) && n < 0){
		g_InvalidInput = true;
		return 0.0;
	}
	if(n == 0)return 1.0;
	if(n == 1)return base;
	unsigned p = 0;
	bool minus = false;
	if(n < 0){
		p = -n;
		minus = true;
	}else{
		p = n;
	}
	double ans = unsignedPow(base,p);
	if(minus){
		ans = 1/ans;
	}
	return ans;
}


// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = myPow(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
    result = myPow_1(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << testName << " passed" << std::endl;
    else
        std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    return 0;
}