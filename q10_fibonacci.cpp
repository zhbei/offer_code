#include <iostream>
using namespace std;

int fib(int n){
	int last = 0;
	int pre = 1;
	int result = 0;
	if(n < 2)return n;
	for(int i = 2; i <= n; ++i){
		result = last + pre;
		last = pre;
		pre = result;
	}
	return result;
}
int main(){
	cout << fib(6) << endl;
	return 0;
}