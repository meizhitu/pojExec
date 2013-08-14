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