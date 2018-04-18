#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>


using namespace std;

void reverseWord(string &str,int start,int end){
	--end;
	while(start < end){
		swap(str[start],str[end]);
		++start;
		--end;
	}
}

void reverse(string &str){
	int len = str.size();
	int start = 0, end = 0;
	for(int i = 0; i < len; ++i){
		start = end = i;
		while(end < len && str[end] != ' '){
			++end;
		}
		reverseWord(str,start,end);
		i = end;
	}
	reverseWord(str,0,len);
}

// ====================测试代码====================
void Test(const char* testName, string input, string expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    reverse(input);

    if(input == expectedResult)
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    string input = "I am a student.";
    string expected = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    string input = "Wonderful";
    string expected = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", "", "");
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
void Test5()
{
    string input = "   ";
    string expected = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}