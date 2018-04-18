#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void printMatrix(vector<vector<int>> matrix){
	int row = matrix.size();
	if(row == 0)return;
	int col = matrix[0].size();
	if(col == 0)return;
	int row_s = 0, row_e = row - 1;
	int col_s = 0, col_e = col - 1;
	int i = 0, j = 0;
	while(row_s <= row_e && col_s <= col_e){
		j = col_s;
		while(j <= col_e){
			cout << matrix[row_s][j++] << ",";
		}
		i = row_s + 1;
		while(i < row_e){
			cout << matrix[i++][col_e] << ",";
		}
		if(col_s != col_e){
			--j;
			while(j > col_s){
				cout << matrix[row_e][j--] << ",";
			}	
		}
		if(row_s != row_e){
			while(i > row_s){
				cout << matrix[i--][col_s] << ",";
			}
		}
		++col_s;
		--col_e;
		++row_s;
		--row_e;
	}
}
// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    vector<vector<int>> numbers(rows,vector<int>(columns));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrix(numbers);
    printf("\n");
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
