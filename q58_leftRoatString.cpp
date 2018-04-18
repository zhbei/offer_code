#include <cstdio>
#include <string>

using namespace std;

void reverseWord(string &str,int start,int end){
	--end;
	while(start < end){
		swap(str[start],str[end]);
		++start;
		--end;
	}
}
void reverse(string &str,int k){
	int len = str.size();
	if(k >= len){
		return;
	}
	reverseWord(str,0,k);
	reverseWord(str,k,str.size());
	reverseWord(str,0,str.size());
}

// ====================测试代码====================
void Test(const char* testName, string input, int num, string expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    reverse(input, num);

    if(input == expectedResult)
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
    string input = "abcdefg";
    string expected = "cdefgab";

    Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
    string input = "abcdefg";
    string expected = "bcdefga";

    Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
    string input = "abcdefg";
    string expected = "gabcdef";

    Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
    Test("Test4", "", 6, "");
}

// 鲁棒性测试
void Test5()
{
    string input = "abcdefg";
    string expected = "abcdefg";

    Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
    string input = "abcdefg";
    string expected = "abcdefg";

    Test("Test6", input, 7, expected);
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