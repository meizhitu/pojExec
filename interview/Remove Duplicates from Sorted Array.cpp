int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int start = 0;
	int prev = INT_MIN;
	for(int i = 0;i<n;i++){
		if(prev!=A[i]){
			A[start++] = A[i];
			prev = A[i];
		}
	}
	return start;
 }