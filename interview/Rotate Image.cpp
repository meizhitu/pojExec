//首先沿逆对角线翻转一次，然后按x轴中线翻转一次。
//矩阵旋转0度。
void rotate(vector<vector<int> > &matrix) {  
	// Start typing your C/C++ solution below  
	// DO NOT write int main() function  
	int len = matrix[0].size();  
	for(int i =0; i<len-1; i++)  
	{  
		for(int j=0;j<len-i;j++)  
		{  
			swap(matrix[i][j], matrix[len-1-j][len-1-i]);  
		}  
	}  
	for(int i =0; i<len/2; i++)  
	{  
		for(int j=0;j<len;j++)  
		{  
			swap(matrix[i][j], matrix[len-i-1][j]);  
		}  
	}  
}  
void swap(int& a1, int&a2)  
{  
	int temp = a1;  
	a1=a2;  
	a2=temp;  
}  
