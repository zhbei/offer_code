#include <iostream>
#include <vector>

using namespace std;

int maxGift(vector<vector<int>> matrix){
	int row = matrix.size();
	if(row == 0)return 0;
	int col = matrix[0].size();
	if(col == 0)return 0;

	vector<int> dp(col+1,0);
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			dp[j+1] = max(dp[j],dp[j+1]) + matrix[i][j];
		}
	}
	return dp[col];
}

// ====================测试代码====================
void test(const char* testName, vector<vector<int>> values, int rows, int cols, int expected)
{
    if(maxGift(values) == expected)
        std::cout << testName << ": solution1 passed." << std::endl;
    else
        std::cout << testName << ": solution1 FAILED." << std::endl;

 }

void test1()
{
    // 三行三列
    vector<vector<int>> values = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1",  values, 3, 3, expected);
}

void test2()
{
    //四行四列
    vector<vector<int>> values = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2",  values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    vector<vector<int>> values = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3",  values, 1, 4, expected);
}

void test4()
{
    vector<vector<int>> values = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    vector<vector<int>> values = {
        { 3 }
    };
    int expected = 3;
    test("test5",values, 1, 1, expected);
}


int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
