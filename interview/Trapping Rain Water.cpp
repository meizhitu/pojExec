//先从左往右计算每个坐标左侧的max，然后从右往左计算，计算每个坐标右边的最大值，然后遍历每个坐标点，min(左边，右边)-A[i]即为每个坐标点的面积，求和。
#include <iostream>
using namespace std;
int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if(n==0) return 0;
	int maxL = A[0];
	int maxLeft[n];
	maxLeft[0] = 0 ;
	for(int i = 1;i<n;i++)
	{
		maxLeft[i] = maxL;
		if(maxL < A[i]) maxL = A[i];
	}
	int maxR = A[n-1];
	int maxRight[n];
	maxRight[n-1] = 0 ;
	int area = 0 ;
	for(int i = n-2;i>=0;i--){
		maxRight[i] = maxR;
		int single = min(maxLeft[i],maxRight[i])-A[i];
		if(single >0)
			area += single;
		if(maxR < A[i]) maxR = A[i];
	
	}
	return area;
}
int main(){
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int n = 12;
	cout << trap(A,n)<<endl;
}