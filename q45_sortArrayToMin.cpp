#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

bool comp(string i, string j){
	//cout <<"comp : " << i << '\t' << j << endl;
	size_t i_len = i.size(), j_len = j.size();
	if(i_len == 0 || j_len == 0)return false;
	if(i[0] < j[0])return true;
	if(i[0] > j[0])return false; 

	size_t k = 0;
	while(k < j_len || k < i_len){
		char ci = k < i_len ? i[k] : i[i_len-1];
		char cj = k < j_len ? j[k] : j[j_len-1];
		if(ci < cj) return true;
		else if(ci > cj) return false;
		++k;
	}
	char ci = (k == i_len) ? i[0] : i[i_len-1];
	char cj = (k == j_len) ? j[0] : j[j_len-1];
	return cj <= ci;
}



string getMin(vector<int> nums){
	vector<string> strNums;
	for(int a : nums){
		stringstream ss;
		ss << a;
		strNums.push_back(ss.str());
	}
	string ans;
	sort(strNums.begin(),strNums.end(),comp);
	for(string st : strNums){
		//cout << st << '\t';
		ans += st;
	}
	//cout << endl;
	return ans;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int length, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    if(expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    cout << getMin(numbers);

    printf("\n");
}

void Test1()
{
    vector<int> numbers = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
}

void Test2()
{
    vector<int> numbers = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}

void Test3()
{
    vector<int> numbers = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
}

void Test4()
{
    vector<int> numbers = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    vector<int> numbers = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
}

void Test6()
{
	vector<int> numbers;
    Test("Test6", numbers, 0, "Don't print anything.");
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