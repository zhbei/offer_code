#include <stack>
#include <deque>
#include <cstdio>

using namespace std;

template<typename T> 
class MaxQue{
private:
	deque<T> valQ;
	deque<T> maxQ;
public:
	void push_back(T val){
		if(maxQ.empty())
		{
			maxQ.push_back(val);
			valQ.push_back(val);
			return;
		}
		if(val > maxQ.front()){
			maxQ.clear();
			maxQ.push_back(val);
		}else{
			while(val > maxQ.back()){
				maxQ.pop_back();
			}
			maxQ.push_back(val);
		}
		valQ.push_back(val);
	}
	void pop_front(){
		if(valQ.empty())return;
		if(maxQ.front() == valQ.front()){
			maxQ.pop_front();
		}
		valQ.pop_front();
	}
	T max() const{
		return maxQ.front();
	}
};
// ====================测试代码====================
void Test(const char* testName, const MaxQue<int>& queue, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    MaxQue<int> queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}

