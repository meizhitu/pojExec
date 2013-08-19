#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
//题目的意思是乱序的一个数组，求出连续子序列的最大长度
//将出现的所有数字存入hash中，然后从一个点开始，分别向上向下寻找最大的长度。
int countConse(map<int,int> &m,int num,bool asc){
	int count = 0 ;
	while(m.count(num)>0){
		m.erase(num);//免得重复计算
		count ++;		
		if(asc) num --;
		else num ++;
	}
	return count;
}
int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	map<int,int> m;
	for(int i = 0 ;i<num.size();i++)
	{
		m[num[i]] = 1;
	}
	int maxCount  = 0;
	for(int i = 0;i<num.size();i++)
	{		
		if(m.count(num[i])>0)
		{
			int v = countConse(m,num[i],true)+countConse(m,num[i]+1,false);
			maxCount = maxCount>v?maxCount:v;
		}
	}
	return maxCount;
}
int main(){
	vector<int> num;
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(2);
	num.push_back(1);
	num.push_back(3);
	cout<<longestConsecutive(num) <<endl;
	
	
}