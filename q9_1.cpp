#include <iostream>
#include <queue>

using namespace std;
class MyStack {
public:
    queue<int> que1,que2;
    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(!que1.empty()){
            que1.push(x);
        }else{
            que2.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int last = 0;
        if(!que1.empty()){
            do{
                last = que1.front();
                que1.pop();
                if(!que1.empty()){
                    que2.push(last);
                }
            }while(!que1.empty());
        }else{
            do{
                last = que2.front();
                que2.pop();
                if(!que2.empty()){
                    que1.push(last);
                }
            }while(!que2.empty());
        }
        return last;
    }
    
    /** Get the top element. */
    int top() {
        int last = 0;
        if(!que1.empty()){
            do{
                last = que1.front();
                que1.pop();
                que2.push(last);
            }while(!que1.empty());
        }else{
            do{
                last = que2.front();
                que2.pop();
                que1.push(last);
            }while(!que2.empty());
        }
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty() && que2.empty();
    }
};

