#include <iostream>
#include <vector>


using namespace std;

class Tmp{
private:
	static unsigned  i, sum;
public:
	Tmp(){
		++i;
		sum += i;
	}
	static void reset(){
		sum = 0; i = 0;
	}
	static unsigned getSum(){
		return sum;
	}
};

unsigned Tmp::i = 0;
unsigned Tmp::sum = 0;

unsigned sumOfNum(unsigned n){
	vector<Tmp> tmps(n);
	return Tmp::getSum();
}
class A{
public:
	virtual int sum(unsigned n){
		return 0;
	}
};
vector<A*> arr(2);

class B : public A{
public:
	virtual int sum(unsigned n){
		return arr[!!n]->sum(n-1) + n;
	}
};

typedef unsigned (*fun)(unsigned);

unsigned end(unsigned n){
	return 0;
}
unsigned start(unsigned n){
	static fun f[2]  = {end,start};
	return f[!!n](n-1) + n;
}

template<unsigned n>struct sum_t
{
	enum Value{N = sum_t<n - 1>::N + n};
};
template<>struct sum_t<1>
{
	enum Value{N = 1};
};

int main(){
	cout << sumOfNum(100) << endl;
	A a;
	B b;
	arr[0] = &a;
	arr[1] = &b;
	cout << arr[1]->sum(100) << endl;
	cout << start(100) << endl;
	cout << sum_t<100>::N << endl;
	return 0;
}

