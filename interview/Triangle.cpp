/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*/
	  //dp
#include <iostream>
#include <vector>
using namespace std;  
int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	int dp[n+1][n+1];
	for(int i = 0;i<=n;i++)
		for(int j = 0; j <= n;j++)
			dp[i][j] = 100000000 ;
	//dp[1][1] = triangle
	dp[0][0] = 0;
	for(int i=1;i<=n;i++)
		for(int j = 1;j<=i;j++){
			dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i-1][j-1];
		}
		
	int min = 1000000;
	for(int j = 1;j<=n;j++)
		if(min > dp[n][j])
			min = dp[n][j];
	return min;
}
int main(){
	vector<vector<int> > tri;
	vector<int> inner;
	inner.push_back(2);
	vector<int> inner1;
	inner1.push_back(3);
	inner1.push_back(4);
	vector<int> inner2;
	inner2.push_back(6);
	inner2.push_back(5);
	inner2.push_back(7);
	vector<int> inner3;
	inner3.push_back(4);
	inner3.push_back(1);
	inner3.push_back(8);
	inner3.push_back(3);
	tri.push_back(inner);
	tri.push_back(inner1);
	
	tri.push_back(inner2);
	tri.push_back(inner3);
	
	cout <<minimumTotal(tri)<<endl;
	
}