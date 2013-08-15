#include <iostream>
#include <vector>
//设置首尾指针，如果首指针较小，则start++,因为容器的宽度会逐渐减小，只有不断提高容器的高度来增加面积。
using namespace std;
int maxArea(vector<int> &height) {
	if(height.size()==0) return 0;
	int start = 0 ;
	int end = height.size()-1;
	int maxV = INT_MIN;
	while(start<end){
		maxV = max(maxV,min(height[start],height[end])*(end-start));
		if(height[start] < height[end])
			start++;
		else 
			end --;
	}
	return maxV;
}
int main(){

}