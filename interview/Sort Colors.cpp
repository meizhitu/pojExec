#include <iostream>
using namespace std;
void swap(int A[],int i ,int t){
	cout <<"swap "<<i<<" "<<t<<endl;
	int tmp = A[i];
	A[i] = A[t];
	A[t] = tmp;
}
void sortColors(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(n==0) return ;
	int i = 0 ; 
	int rIdx = 0;
	int bIdx = n-1;
	for(;i<=bIdx;){
		if(A[i]==1) {
			i++;
		}
		else {
			if(A[i]==0) {
				swap(A,i,rIdx);
				rIdx ++;
				i++;
			}
			else if(A[i]==2){
				swap(A,i,bIdx); //因为A[i]和bIdx交换后，A[i]的值可能变成0，则需要再次判断A[i]
				bIdx --;
			}
		
		}
	}
}
int main(){
	int A[]={2,0};
	sortColors(A,2);
	for(int i = 0;i<2;i++)
		cout <<A[i]<<" ";
}