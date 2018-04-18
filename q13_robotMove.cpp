#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int count(int i){
	int ans = 0;
	while(i > 0){
		ans += i % 10;
		i /= 10;
	}
	return ans;
}
int helper(int row,int col,int i,int j,int k,vector<bool> &v){
	int ans = 0;
	if(i >= 0 && i < row && j >= 0 && j < col && !v[i*col+j] && count(i) + count(j) <= k ){
		v[i*col+j] = true;
		ans = 1 + helper(row,col,i-1,j,k,v)
			+helper(row,col,i+1,j,k,v)
			+helper(row,col,i,j-1,k,v)
			+helper(row,col,i,j+1,k,v);
	}
	return ans;
}
int canMoveNum(int k,int row,int col){
	if(k < 0 || row <= 0 || col <= 0)return 0;

	vector<bool> v(row*col,false);

	return helper(row,col,0,0,k,v);
}

// ====================测试代码====================
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(canMoveNum(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
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

    return 0;
}
