/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/
#include <iostream>
	using namespace std;
bool canJump(int A[], int n) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
   	bool visited[n];
	memset(visited,false,sizeof(visited));
	int i = 0;
	while(i<n-1){
		i = A[i]+i;
		if(visited[i]) break;
		visited[i] = true;
	}
	if(i>=n-1)return true;
	return false;
}
int main(){
	int A[] ={0,1};
	cout <<canJump(A,2)<<endl;
}