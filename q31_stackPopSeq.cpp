#include <iostream> 
#include <vector>
#include <stack>
#include <cstdio>


using namespace std;

bool isPopSeq(vector<int> &in,vector<int> &out){
	if(in.size() != out.size())
		return false;
	
	stack<int> stk;
	auto ot = out.begin();
    auto it = in.begin();
	for(; it != in.end() && ot != out.end(); ++it){
		stk.push(*it);
		while(!stk.empty() && stk.top() == *ot){
			stk.pop();
			++ot;
		}
	}
	
	if(stk.empty() && it == in.end() && ot == out.end())
		return true;
	else 
		return false;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> &pPush, vector<int> & pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isPopSeq(pPush, pPop) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    vector<int> push = {1, 2, 3, 4, 5};
    vector<int> pop = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    vector<int> push = {1};
    vector<int> pop = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    vector<int> push = {1};
    vector<int> pop = {1};

    Test("Test6", push, pop, nLength, true);
}
 
int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}