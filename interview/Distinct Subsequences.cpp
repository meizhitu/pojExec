/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
#include <iostream>
#include <string>
	using namespace std;
int numDistinct1(string S, string T){
	//动态规划 dp[i][j]:T中前i个字符出现在S前j个字符的次数
	int t = T.size();
	int s = S.size();
	if(t>s) return 0;
	int dp[t+1][s+1];
	memset(dp,0,sizeof(dp));
	//t中0个字符出现在s的前j个字符的次数为1
	for(int j = 0;j<=s;j++)
		dp[0][j] = 1;
	for(int i = 1;i<=t;i++)
		for(int j = 1;j<=s;j++)
	{
		//若第i个字符和第j个字符相等，则
		//dp[i][j] = dp[i][j-1] 前i个字符出现在前j-1个的情况如 "ab" "abb"
		//			+dp[i-1][j-1]; 前i-1个字符出现在前j-1个字符的情况
		if(T[i-1] == S[j-1])
		{
			dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
			
		}
		else
			dp[i][j] = dp[i][j-1];
	}
	return dp[t][s];
}
//01背包的处理策略
int numDistinct(string S, string T) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int match[200];  
	if(S.size() < T.size()) return 0;  
	match[0] = 1;  
	for(int i=1; i <= T.size(); i++)  
		match[i] = 0;  
	for(int i=1; i<= S.size(); i ++)  
		for(int j =T.size(); j>=1; j--)  
			if(S[i-1] == T[j-1])  
				match[j]+= match[j-1];  
	return match[T.size()];  
}
   int main(){
	   string s = "ccc";
	   string t = "c";
	   cout <<numDistinct1(s,t)<<endl;
   
   }