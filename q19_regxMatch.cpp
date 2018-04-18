#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string str, string pattern) {
    /*
    1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
    2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
    3, If p.charAt(j) == '*': 
    here are two sub conditions:
           1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
           2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
                          dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                       or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                       or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
    */
	if(pattern.size() == 0 && str.size() == 0)
		return true;
	if(pattern.size() == 0 && str.size() != 0)
		return false;
	vector<vector<bool>> dp(str.size()+1,vector<bool>(pattern.size()+1,false));
	dp[0][0] = true;
	for(size_t j = 1; j <= pattern.size(); ++j){
		if(pattern[j-1] == '*')dp[0][j] = dp[0][j-2];
	}

	for(int i = 1; i <= str.size(); ++i){
		for(int j = 1; j <= pattern.size(); ++j){
			if(pattern[j-1] == '.' || pattern[j-1] == str[i-1]){
				dp[i][j] = dp[i-1][j-1];
			}else if(pattern[j-1] == '*'){
				if(pattern[j-2] != '.' && pattern[j-2] != str[i-1]){
					dp[i][j] = dp[i][j-2];
				}else{
					dp[i][j] = (dp[i-1][j] || dp[i][j-1] ||dp[i][j-2]);
				}
			}
		}
	}
	return dp[str.size()][pattern.size()];
}