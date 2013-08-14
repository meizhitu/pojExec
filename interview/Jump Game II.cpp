/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include <iostream>
#include <queue>
using namespace std;
//dp[i] = min(dp[i-1]+1,dp[i-2]+1,dp[i-3]+1,dp[i-k]+1); 如果可以跳的话
//dp是O(n^2)复杂度，在大数据的时候会超时。
int jump1(int A[], int n) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(n <=1) return 0;
	int dp[n];
	for(int i = 0 ; i<n;i++)
		dp[i] = INT_MAX;
	dp[0] = 0 ;
	int minV = INT_MAX;
	for(int i =0;i<n;i++)
	{
		for(int j = 1;j<=A[i];j++)
		{
			int k = i+j;
			if(k>=n-1)
				k = n -1; 
			dp[k] = min(dp[i]+1,dp[k]);
		}
	}
	return dp[n-1];
}
//贪心,检测每个位置所能到的最大idx
int jump(int A[], int n) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(n <=1) return 0;
	int minS = 0;
	int low = 0 ;
	int high = 0 ;
	while(low<=high){
		minS ++;
		int last = high;
		int maxL = INT_MIN;
		for(int i = low;i<=last;i++){
			maxL = max(maxL,i+A[i]);
			if(maxL >=n-1) return minS;
			high = max(maxL,high);
		}
		low = last+1;
	}
	return 0 ;
}
int main(){
	int A[] ={2,3,1,1,4};
	cout <<jump(A,5)<<endl;
}