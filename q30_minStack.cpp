#include <iostream>
#include <stack>

using namespace std;

template<typename T> class minStack
{
public:
	minStack(){

	}
	T pop(){
		T ans = st.top();
		st.pop();
		minS.pop();
		return ans;
	}
	void push(T val){
		st.push(val);
		if(minS.empty() || minS.top() > val){
			minS.push(val);
		}else{
			minS.push(minS.top());
		}
	}
	T min(){
		assert(!minS.empty());
		return minS.top();
	}
	~minStack(){

	}
private:
	stack<T> st;
	stack<T> minS;	
};