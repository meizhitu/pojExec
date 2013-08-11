//01011
//10111
//10110
//01
//10
//11,11
//21232
#include <iostream>
#include <vector>
using namespace std;
int largestRectangleArea(vector<int> &height);
int maximalRectangle(vector<vector<char> > &matrix) {
	if(matrix.size() ==0)return 0;
	int m = matrix.size();
	int n = matrix[0].size();
	int a[2][n];
	memset(a,0,sizeof(a));
	vector<int> height;
	int area = 0;
	//思路。借鉴了直方图最大面积的思路，计算每一层往上的直方图面积大小，如果matrix[i][j]为0的话，无论其上方是否有1，其高度均为0；而matrix[i][j]==1,则
	//其对应的高度为a[i-1][j]+1。
	for(int i = 0;i<m;i++){
		height.clear();
		for(int j = 0 ; j< n;j++){
			if(matrix[i][j]=='1')
				a[i%2][j] = a[(i-1+2)%2][j]+1;
			else  
				a[i%2][j] = 0 ;
			height.push_back(a[i%2][j]);
		}
		area = max(area,largestRectangleArea(height));
	}
	
	return area;
}
int largestRectangleArea(vector<int> &height) {
	height.push_back(-1);
	int len = height.size();
	int hts[len+1];
	int width[len+1];
	hts[0] = 0;
	width[0] = 0 ;
	int top = 0 ;
	int area = 0;
	for(int i = 0 ; i<height.size();i++){
		if(height[i]>=hts[top]){
			top ++;
			hts[top] = height[i];
			width[top] = 1;
		}
		else{
			int minV = INT_MAX;
			int wid = 0 ;
			while(height[i]<hts[top] &&top>=0){
				minV = min(minV,hts[top]);
				wid += width[top];
				area = max(area,minV*wid);				
				top --;
			}
			top ++;
			hts[top] = height[i];
			width[top] = wid+1;
		}
	}
	return area;
}
int main(){
	vector<vector<char> > chars;
	vector<char> charR;
	charR.push_back('0');
	charR.push_back('1');
	chars.push_back(charR);
	vector<char> charR1;
	charR1.push_back('1');
	charR1.push_back('0');
	chars.push_back(charR1);
	
		cout <<maximalRectangle(chars)<<endl;

}