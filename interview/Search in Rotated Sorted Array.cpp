/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become  5 6 7 0 1 2 4).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/
#include <iostream>
	using namespace std;
int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int l = 0; 
	int h = n-1;
	while(l<=h){
		int mid = (l+h)>>1;
		if(A[mid]==target) return mid;
		if(A[mid]<A[l])
		{
			if(A[mid]< target && target<A[l])
				l = mid+1;
			else
				h=mid-1;
		}
		else{
			if(A[mid] >target && target>=A[l])
				h=mid-1;
			else
				l = mid+1;
		
		}
	}
	return -1;
}
int main(){
	int A[] = {1,3,5};
	int n = 3;
	cout << search(A,n,1)<<endl;
}