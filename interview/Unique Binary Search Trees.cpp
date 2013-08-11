#include <iostream>   
    
    /**
    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    For example,
    Given n = 3, there are a total of 5 unique BST's.
        3     3      2      1
        \       /     /      / \      \
    2     1      1   3      2
        /     /       \                 \
    1         2                 3
    dp[0] = 1; dp[1] = 1;
    
    dp[n] =  1) n作为根结点，之前的二叉树就是left.child 这种情况： dp[n-1]*dp[0]
             2) n-1 是根结点，那么 n只有一种情况 ： dp[n-2] * dp[1]
             3) n-2 是根节点，right tree: dp[2] * left child : dp[n -3]
             ...
             4) 1 是根结点：dp[0] * dp[n-1]
    dp[n] = sigma{i = 0..n-1} dp[i]*dp[n-1-i]
    
    其实就是说白了考虑左右子tree的大小就ok，因为大小暗含了这个时候根结点的情况，所以和枚举根结点从1...n是一样的
    */
	int numTrees(int n){
		int *dp = new int[n + 1];
		memset(dp,0,sizeof(int)*(n + 1));
		dp[0] = dp[1] = 1;
		for(int i = 2; i <= n; i++){
			for(int j = 0; j < i; j++){
				dp[i] += dp[j]*dp[i-1-j];
			}
		}
		int ans = dp[n];
 		delete dp;
		return ans;
	}

using namespace std;
int main(int argc, char *argv[]) {
    int a = 4;
     cout << "solution: " << numTrees(a) << endl;
}