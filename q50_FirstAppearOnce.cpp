#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


using namespace std;

char firstApperOnce(string &str){
	int len = str.size();
	if(len == 0)return '\0';
	vector<int> record(256,0);
	for(char a : str){
		++record[a];
	}
	for(char a : str){
		if(record[a] == 1)
			return a;
	}
	return '\0';
}

// ====================测试代码====================
void Test(string pString, char expected)
{
    if(firstApperOnce(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test("", '\0');

    return 0;
}