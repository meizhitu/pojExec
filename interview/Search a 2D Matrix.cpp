#include <iostream>
#include <vector>
using namespace std;
//比较经典的面试题
bool searchMatrix(vector<vector<int> > &matrix, int target) {
	if(matrix.size()==0) return false;
	int m = matrix.size();
	int n = matrix[0].size();
	int j = 0,i=n-1;
	while(i>=0 && j<m){
		if(matrix[j][i]==target) return true;
		if(matrix[j][i]>target) i--;
		else if(matrix[j][i]<target) j++;
	}
	return false;
}
int main(){
	cout <<searchMatrix(vector<vector<int> >(),3)<<endl;
}
