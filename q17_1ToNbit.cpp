#include <iostream>
#include <cstring>

using namespace std;

bool increase(char* num,int n){
	int step = 1;
	for(int i = n-1; i >= 0; --i){
		if(num[i] == '0' && step == 0)break;
		int result = num[i] + step - '0';

		if(result > 9){
			step = 1;
			result -= 10;
		}else{
			step = 0;
		}
		num[i] = result + '0';
	}
	return step == 0;
}
void printNum(char* num){
	bool beginZero = false;
	while(*num != '\0'){
		if(!beginZero && *num != '0')
			beginZero = true;
		if(beginZero)
			cout << (*num - '0') ;
		++num;
	}
	if(beginZero)
		cout << "\t";
}
void printNdigital(int n){
	if(n <= 0)
		return;
	char *num = new char[n+1];
	memset(num,'0',n);

	while(increase(num,n)){
		printNum(num);
	}
	delete []num;
	return ;
}
void helper(char * nums,int n,int l){
	if(n == l){
		printNum(nums);
		return ;
	}

	for(int i = 0; i < 10; ++i){
		nums[l] = i + '0';
		helper(nums,n,l+1);
	}
}
void printNdigital_1(int n){
	if(n <= 0)return;
	char* num = new char[n+1];
	helper(num,n,0);
}
int main(){
	printNdigital_1(3);
	return 0;
}
