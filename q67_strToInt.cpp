#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

int invalid = 0;
int strToInt(const char * str){
	invalid = 0;
	if(str == NULL){
		invalid = 1;
		return 0;
	}
	long long minus = 1;
	if(*str == '-'){
		minus = -1;
		++str;
	}else if(*str == '+'){
		minus = 1;
		++str;
	}
	long long ans = 0;
	if(*str == '\0'){
		invalid = 1;
		return 0;
	}
	while(*str != '\0'){
		if(*str >= '0' && *str <= '9'){
			ans = ans * 10 + *str - '0';
			++str;
		}else{
			invalid = 1;
			return 0;
		}
	}
	ans = ans * minus;
	if(ans > INT_MAX || ans < INT_MIN){
		invalid = 1;
		return 0;
	}
	return ans;
}

// ====================测试代码====================
void Test(const char* string)
{
    int result = strToInt(string);
    if(result == 0 && invalid == 1)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(NULL);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}

