//一道poj的dp
//dp[i][j]:s1的前i个字符和s2的前j个字符是否能组成s3
#include <iostream>
#include <string>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
	if(s1.size()+s2.size()!=s3.size()) return false;
	bool dp[s1.size()+1][s2.size()+1];
	memset(dp,false,sizeof(dp));
	dp[0][0] = true;
	for(int i = 0;i<s1.size();i++)
		if(s1[i]==s3[i])
			dp[i+1][0] = dp[i][0];
	for(int i = 0; i<s2.size();i++)
		if(s2[i] == s3[i])
			dp[0][i+1] = dp[0][i];
	for(int i = 1;i <= s1.size();i++)
		for(int j =1 ; j<= s2.size();j++)
	{
		if(s1[i-1] == s3[i+j-1])
			dp[i][j] = dp[i-1][j]||dp[i][j];
		if(s2[j-1] == s3[i+j-1])
			dp[i][j] = dp[i][j-1]||dp[i][j];		
	}
	
	return dp[s1.size()][s2.size()];
}
int main(){
	string s1 = "ab";
	string s2 = "bc";
	cout << isInterleave(s1,s2,"babc")<<endl;

}