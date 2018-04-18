#include <iostream>
#include <limits.h>

using namespace std;

int input_error = 0;



long long strToIntCore(char *str){
	long long result = 0;
	if(*str == '\0'){
		input_error = 1;
		return 0;
	}
	while(*str != '\0'){
		if(*str >= '0' && *str <= '9')
			result = result*10 + *str - '0';
		else{
			input_error = 1;
			return 0;
		}
	}
	return result;
}
int strToInt(char *str){
	if(str == NULL || *str == '\0'){
		input_error = 1;
		return 0;
	}
	long long result = 0;
	long long op = 1;
	if(*str == '+'){
		++str;
	}else if(*str == '-'){
		++str;
		op = -1;
	}
	result = op * strToIntCore(str);	
	if(result < INT_MIN){
		input_error = 4;
		return 0;
	}else if(result > INT_MAX){
		input_error = 3;
		return 0;
	}
	return int(result);
}
void test(){
	char* str;
	cout << strToInt(str) << endl;
}
void test1(){
	char* str = "-12345";
	cout << strToInt(str) << endl;
}
void test2(){
	char* str = "+12345";
	cout << strToInt(str) << endl;
}
void test3(){
	char* str = "+12345678901";
	cout << strToInt(str) << endl;
}
void test4(){
	char* str = "12345";
	cout << strToInt(str) << endl;
}
int main(){
	test();
	test1();
	test2();
	test3();
	test4();
	return 0;
}