#include <iostream>
#include <vector>
using namespace std;
//dp[i] 前i个数字可以解码的方式
//dp[i] = dp[i-1]+dp[i-2](如果a[i-1]a[i]可以形成一个不大于26的数字)
int compute(string s){
	int dp[s.size()+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	//dp[1] = 1;
	for(int i = 1;i<=s.size();i++)
	{
		if(s[i-1]>'0' && s[i-1]<='9')
			dp[i]+= dp[i-1];
		//需要注意的细节
		if(i>=2 && s[i-2]!='0')
		{
			int num = (s[i-2]-'0')*10+s[i-1]-'0';
		//	cout <<num<<endl;
			if(num <= 26 && num > 0)
				dp[i] += dp[i-2];
		}
	}
	for(int i = 1;i<=s.size();i++)
		if(dp[i]==0) return 0;
	return dp[s.size()];
}
int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if(s.size()==0) return 0;
	return compute(s);
}
int main(){
	string s = "101";
	cout << numDecodings(s)<<endl;
}