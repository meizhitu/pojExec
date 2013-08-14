//题目的意思应该这样理解的，数组长度为n，存储的数据从1到n，但是是乱序排的，需要找到第一个错误的数据，如[2,1,0],缺少的数据就是3.
#include <iostream>
using namespace std;
void swap(int *A,int a,int b){
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}
int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	for(int i = 0; i < n;i++)
	{
		while(A[i]!=i+1){
		//	cout <<i<<" "<<A[i]-1<<endl;
			if(A[i]<=0 || A[i]>n||A[i] == A[A[i]-1]) break;
			swap(A,A[i]-1,i);
		}
	}
	int i;
	for( i = 0; i< n;i++){
		if(A[i]!=i+1)
			return i+1;
	}
	return n+1;
}
int main(){
	int A[] = {2,1};
	cout << firstMissingPositive(A,2)<<endl;

}