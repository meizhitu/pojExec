#include <iostream>
//1 3 3 4
// 2 6
using namespace std;
void merge(int A[], int m, int B[], int n) {
	int i=m-1,j=n-1;
	int last = m+n;
	while(j>=0 && i >=0){
		if(B[j] > A[i]){
			A[i+j+1] = B[j];
			j--;
		}
		else{
			A[i+j+1] = A[i]; 
			i--;
		}
	}
	while(j>=0){
		A[i+j+1] = B[j];
		j--;
	}
}
int main()
{
	int A[9];
	A[0]=1;
	A[1]=4;
	A[2]=7;
	A[3]=9;
	A[4]=10;
	A[5]=12;
	int B[] = {6,8,18};
	merge(A,6,B,3);
	for(int i = 0 ; i<9;i++)
		cout <<A[i]<<endl;
}