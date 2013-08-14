#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//dp[i][j]表示word1中前i个字符变成word2中前j个字符所需要的变化次数。
//若word1[i]==word2[j],则dp[i][j] = dp[i-1][j-1]
//如果不等，则可能需要添加一个字符，dp[i][j-1]+1
//可能需要删除一个字符 dp[i-1][j]+1
//需要替换，则dp[i-1][j-1]+1
//dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1,dp[i-1][j-1]+1)(word1[i]==word2[j])
int minDistance(string word1, string word2) {
	int dis =(word1.size()-word2.size());
	if(dis<0)
		dis = -dis;
	int dp[word1.size()+1][word2.size()+1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=word1.size();i++)//word[i]不停的删直到字符串空
		dp[i][0] = i;
	for(int i = 1;i<=word2.size();i++)
		dp[0][i] = i;
	for(int i = 1;i<=word1.size();i++)
	for(int j = 1;j<=word2.size();j++){
		if(word1[i-1]==word2[j-1])
		{
			dp[i][j] = dp[i-1][j-1];
		}
		else
		{
			int minOp = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
			dp[i][j] = minOp+1;
		}
	}
	return dp[word1.size()][word2.size()];
}
int main(){
	cout <<minDistance("","bc")<<endl;

}