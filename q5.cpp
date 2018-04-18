#include <iostream> 
#include <vector>

using namespace std;

void repalceSpace(char src[],size_t length){
	if(src == NULL || length <= 0){
		return;
	}

	size_t numOfSpace = 0, realLen = 0;
	int i = 0;
	while(src[i] != '\0'){
		++realLen;
		if(src[i] == ' '){
			++numOfSpace;
		}
		++i;
	}
	realLen += 2 * numOfSpace;
	if(realLen > length)
		return;
	while(i >= 0){
		if(src[i] != ' '){
			src[realLen] = src[i];
		}else{
			src[realLen] = '0';
			src[--realLen] = '2';
			src[--realLen] = '%';
		}
		--i;
		--realLen;
	}
}
void test(){
	char a[20] = "hello world";
	repalceSpace(a,20);
	cout << a << endl; 
}
void test1(){
	char a[20] = " hello world ";
	repalceSpace(a,20);
	cout << a << endl; 
}
void test2(){
	char a[20] = "    ";
	repalceSpace(a,20);
	cout << a << endl; 
}
void test3(){
	char a[20] = "h e  l l o w orld";
	repalceSpace(a,20);
	cout << a << endl; 
}
int main(){
	test();
	test1();
	test2();
	test3();
	return 0;
}