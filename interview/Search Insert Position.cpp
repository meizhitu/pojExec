/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <iostream>
using namespace std;
int searchInsert(int A[], int n, int target) {
	int l = 0;
	int h = n-1;
	int mid;
	while(l<=h){
		 mid = (l+h)>>1;
		if(target==A[mid])
		{
			return mid;
		}
		else if(target > A[mid])
			l = mid+1;
		else if(target < A[mid])
			h = mid-1;
	}
	if(A[mid] > target)
			return mid;
		else 
			return mid+1;
}
int main(){
	int A[] = {1};
	cout << searchInsert(A,1,1)<<endl;

}