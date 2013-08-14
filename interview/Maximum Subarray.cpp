/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

	For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
	More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
	*/
int maxSubArray(int A[], int n) {
	if(n==0) return 0;
	int dp[n+1];
	dp[0] = 0;
	int ret = INT_MIN;
	for(int i = 1;i<=n;i++){
		if(dp[i-1]>0)
			dp[i] = dp[i-1]+A[i-1];
		else
			dp[i] = A[i-1];
		if(ret < dp[i])
			ret = dp[i];
	}
	return ret;
}