#include <iostream>
#include <vector>
#include <stack>
/*
我们可以用一个单调栈 (类似单调队列) 由低到高来存储它的高度，并用数组对每个高度记录一下它前面（包括它自己）一共有多少个比它高的，可以看做它的左宽。
按顺序考虑每个高度h，如果h大于栈顶元素，则入栈，此时它大于左面全部的元素（下文会提到为什么可以这样认为），并且将它的宽度初始为1。
否则，将栈内元素出栈，直到满足上面的条件。出栈时，我们要将出栈元素对之后问题的影响全部考虑进行处理，才能保证做法的正确性。
*/
using namespace std;
int largestRectangleArea(vector<int> &height) {
	if(height.size()==0) return 0;
	int area = INT_MIN;
	for(int i = 0;i<height.size();i++)
	{
		int minV = height[i];
		for(int j =i;j>=0;j--){
			minV = min(minV,height[j]);
			area = area>minV*(i-j+1)?area:minV*(i-j+1);
		}
	}
	return area;
}
int largestRectangleArea1(vector<int> &height) {
	if(height.size()==0) return 0;
	int top = 0 ;
	int hts[height.size()+1];
	int width[height.size()+1];
	hts[0]=0;
	width[0] = 0;
	int area = INT_MIN;
	int nHeight ;
	for(int i =  0 ; i<= height.size();i++){
		if(i<height.size()) 
			nHeight = height[i];
		else 
			nHeight = -1;
		if(nHeight>hts[top]){
			top ++;
			hts[top]=height[i];
			width[top] = 1;
		}
		else{
			int wid = 0 ;
			int minV = INT_MAX;
			while(hts[top]>nHeight){
 				minV = min(minV,hts[top]);
				wid += width[top];
				area = max(area,minV*wid);
				top --;
			}
			top++;
			hts[top] = nHeight;
			width[top] = wid+1;
		}
		
	}
	return area;
}

int main(){
	vector<int> height ;
	height.push_back(999);
	
	height.push_back(999);
	//height.push_back(5);
	height.push_back(999);
	cout <<largestRectangleArea1(height)<<endl;
	

}