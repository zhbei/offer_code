#include <string>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void stringPermutation(string &str,vector<string> &result){
	size_t len = str.size();
	if(len == 0)
		return;
	result.push_back(str);
	if(len == 1)
		return;
	vector<string> tmp;
	for(size_t i = 0; i < len - 1; ++i){
		for(string s : result){
			for(size_t j = i+1; j < len; ++j){
				string t(s);
				swap(t[i],t[j]);
				tmp.push_back(t);
			}
		}
		result.insert(result.end(),tmp.begin(),tmp.end());
		tmp.clear();
	}
}

int main(){
	string str("abcd");
	vector<string> ans;
	stringPermutation(str,ans);
	for(string s : ans){
		cout << s << endl;
	}
	return 0;
}