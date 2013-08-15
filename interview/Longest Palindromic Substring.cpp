#include <iostream>
#include <string>
using namespace std;
//O(N)
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
 
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
 
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
 
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
//O(N^2)
string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if(s.size()==0) return "";
	int n = s.size();
	bool dp[n+1][n+1];
	memset(dp,false,sizeof(dp));
	int k,e;
	int maxV = INT_MIN;
	int interval = 0;
	for(;interval <n;interval ++)
		for(int i = 0;i<n && i+interval<n;i++)
	{
		if(interval <=0) dp[i][i+interval] = true;
		else{
			if(s[i]==s[i+interval] && (interval==1||dp[i+1][i+interval-1]))
				dp[i][i+interval] = true;
		}
		if(dp[i][i+interval] && maxV < interval+1)
			{
				maxV = interval+1;
				k = i;
			}
		 
	}
	return s.substr(k,maxV);
}
int main(){
	string s= "abaccabe";
	cout << longestPalindrome(s)<<endl;
}
