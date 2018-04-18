#include <iostream>
#include <vector>

using namespace std;

bool haveNum(vector<vector<int>> matrix,int target){
	size_t raw = matrix.size();
	if(raw == 0)return false;
	size_t col = matrix[0].size();
	if(col == 0)return false;
	size_t i = 0, j = col - 1;
	while(i < raw && j >= 0){
		if(matrix[i][j] == target){
			return true;
		}else if(matrix[i][j] > target){
			--j;
		}else{
			++i;
		}
	}
	return false;
}


int main(){
	vector<vector<int>> m = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	if(haveNum(m,15)){
		cout << "Have!!!" << endl;
	}else{
		cout << "DO NOT Have!!!" << endl;
	}
}