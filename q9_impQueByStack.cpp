#include <iostream>
#include <stack>

using namespace std;
template<typename T> class queue
{
private:
	stack<T> stk1,stk2;
public:
	queue();
	~queue();
	void push(T val){
		stk1.push(val);
	}
	void pop(){
		if(stk2.empty() == true){
			while(!stk.empty()){
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		if(stk2.empty())
			throw new exceptions("queue is empty");
		stk2.pop();
		
	}
	int front(){
		if(stk2.empty() == true){
			while(!stk.empty()){
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		if(stk2.empty())
			throw new exceptions("queue is empty");
		return stk2.top();
	}
};

