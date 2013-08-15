//对内存空间要求高。
int removeElement(int A[], int n, int elem) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	int start = 0;
	int i = 0 ;
	for(;i<n;i++)
		if(elem != A[i])
			A[start++] = A[i];
    return start;
}