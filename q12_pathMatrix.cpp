#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool helper(vector<string> &mat,string &str,int raw,int col,int p,vector<vector<bool>> &visited){
	if(p == (int)str.size())return true;
	bool ans = false;
	if(raw >= 0 && raw < (int)mat.size() && col >= 0 && col < (int)mat[raw].size() && mat[raw][col] == str[p] && !visited[raw][col]){
		visited[raw][col] = true;
		ans = helper(mat,str,raw-1,col,p+1,visited) 
		|| helper(mat,str,raw,col-1,p+1,visited) 
		||helper(mat,str,raw+1,col,p+1,visited) 
		||helper(mat,str,raw,col+1,p+1,visited) ;
		if(!ans){
			visited[raw][col] = false;
		}
	}
	return ans;
}
bool hasWord(vector<string> &mat,string &str){
	int raw = mat.size();
	if(raw == 0)return false;
	
	int col = mat[0].size();
	if(col == 0)return false;

	vector<vector<bool>> visited(raw,vector<bool>(col,false));
	for(int i = 0; i < raw; ++i){
		for(int j = 0; j < col; ++j){
			if(helper(mat,str,i,j,0,visited)){
				return true;
			}
		}
	}
	return false;
}

void test(){
	vector<string> mat = {{"AAAAAAAAA"},{"AAAABAAAA"},{"AAAAAAAAA"}};
	string str = "AAAAAABAAAABAAAAAAAAAAAAAAA";
	string str1 = "AAAAAAAAA";
	cout << hasWord(mat,str) <<endl;
	cout << hasWord(mat,str1) <<endl;
}
int main(){
	test();
	return 0;
}