#include <iostream>
#include <cstdio>
using  namespace std;

int numOfSeq(int n){
	int start = 1;
	int end = start * 10;
	int bit = 1;
	int pre = 0;
	int num = (end - start)*bit;
	while(num < n){
		bit = 2;
		start = end;
		end *= 10;
		pre = num;
		num += (end - start)*bit;
	} 
	int rest = n - pre;
	int nth = rest / bit;
	int mod =rest % bit;
	if(mod == 0){
		return (start+nth-1)%10;
	}
	cout << mod << endl;
	start += nth - 1;
	while(mod < bit){
		++mod;
		start /= 10;
	}
	return start%10;
}

int main(){
	cout << numOfSeq(13) << endl;
	return 0;
}