#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int maxSubStr(const string& str){
	int len = str.size();
	if(len <= 1) return len;
	string ans;
	vector<int> last(26,-1);
	last[str[0] - 'a'] = 0; 
	vector<int> dp(len,1);
	int maxlen = 1;
	for(int i = 1; i < len; ++i){
		int pre = last[str[i]-'a'];
		int dist = i - pre;
		last[str[i]-'a'] = i;
		if(dist > dp[i-1]){
			dp[i] = dp[i-1]+1;
		}else{
			dp[i] = dist;
		}
		maxlen = max(maxlen,dp[i]);
	}
	return maxlen;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = maxSubStr(input);
    //cout << output << endl;
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}


void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
