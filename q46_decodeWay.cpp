#include <iostream>
#include <string>
#include <vector>


using namespace std;

int decodeWay(string &s){
	int len = s.size();
	if(len <= 1)return len;
	vector<int> dp(len+1,1);
	for(int i = len - 2;i >= 0; --i){
		if(s[i] == '0' || s[i] > '2' || (s[i] == '2' && s[i+1] > '5')){
			dp[i] = dp[i+1];
		}else{
			dp[i] = dp[1+i] + dp[i+2];
		}
	}
	return dp[0];
}

// ====================测试代码====================
void Test(const string& testName, string number, int expected)
{
    if(decodeWay(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    string number = "0";
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    string number = "10";
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    string number = "125";
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    string number = "126";
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    string number = "426";
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    string number = "100";
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    string number = "101";
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    string number = "12258";
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    string number = "100";
    int expected = 2;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}