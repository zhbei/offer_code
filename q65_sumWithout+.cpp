#include <iostream>
#include <cstdio>

using namespace std;

int add(int num1,int num2){
	int sum,carry;
	do{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}while(num2 != 0);
	return sum;

}

int main(){
	cout << add(-1,-1) << endl;
	cout << add(-1,1) << endl;
	cout << add(1,1) << endl;
	cout << add(1,0) << endl;
	cout << add(0,1) << endl;
	return 0;
}