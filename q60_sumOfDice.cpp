#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


int g_maxValue = 6;
void printProbility(int num){
	if(num == 0)return;
	int size = num * g_maxValue  + 1;
	vector<vector<int>> probility(2,vector<int>(size,0));
	int flag = 0;
	for(int i = 1; i <= g_maxValue; ++i){
		probility[1][i] = 1;
	}
	int up = g_maxValue,low = 1;
	for(int i = 2; i <= num; ++i){
		flag = i % 2;
		for(int j = low; j <= up; ++j)
			probility[flag][j] = 0;
		for(int a = 1; a <= g_maxValue; ++a){
			for(int j = low; j <= up; ++j){
				probility[flag][j+a] += probility[1-flag][j];
			}
		}
		up += g_maxValue;
		++low;
	}
	flag = num % 2;
	double total = pow(g_maxValue,num);
	for(int i = num; i < size; ++i){
		//cout << probility[flag][i] << '\t';
		cout << double(probility[flag][i])/total << '\t';
	}
}
// ====================方法二====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) 
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) 
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j) 
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }
 
        flag = 1 - flag;
    }
 
    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        cout << ratio << '\t';
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}
// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    printProbility(n);
    cout << endl;
    printf("Test for solution2\n");
    PrintProbability_Solution2(n);
    cout << endl;

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}