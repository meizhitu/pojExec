#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ret;
//时间复杂度为O(n^4),大数据超时。
void compute1(vector<int> &num,int target,int partN,int idx,int sum,vector<int> &p){
	if(sum == target && partN == 4){
		ret.push_back(p);
		return;
	}
	
	for(int i = idx;i<num.size();i++){
		sum += num[i];
		p.push_back(num[i]);
		compute1(num,target,partN+1,i+1,sum,p);
		p.pop_back();
		sum -= num[i];
		while(i+1<num.size() && num[i+1] == num[i])
			i++;
	}

}
//2-sum的一个变形，先确定两个元素，然后求剩下的数组里，sum为sum-a[i]-a[k]的两个数字
void compute(vector<int> &num, int target){
	int len = num.size();
	for(int i = 0 ;i<len-3;i++){
		//去重   
		while(i-1>=0 && num[i]==num[i-1])i++;
		for(int k = len-1;k>=3;k--){
			//去重   
			while(k+1<len &&num[k+1]==num[k])k--;
			int sum = target - num[i]-num[k];
			
			int m = i+1;
			int n = k-1;
			while(m<n){
				if(num[m]+num[n]==sum)
				{
					vector<int> p ;
					p.push_back(num[i]);
					p.push_back(num[m]);
					p.push_back(num[n]);
					p.push_back(num[k]);
					ret.push_back(p);
					m++;//去重
					while(m<k && num[m]==num[m-1]){
						m++;
					}
				}
				else if(num[m]+num[n]<sum)
					m++;
				else n--;
			}
		}
    	
	}
        
}
vector<vector<int> > fourSum(vector<int> &num, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ret.clear();
	if(num.size()==0) return ret;
	sort(num.begin(),num.end());
	//vector<int> p;
	compute(num,target);
	return ret;
}
int main(){
	vector<int> num;//5,5,3,5,1,-5,1,-2
	num.push_back(5);//-5 -2 1 1 3 5 5 5
	num.push_back(5);
	num.push_back(3);
	num.push_back(5);
	num.push_back(1);
	num.push_back(-5);
	
	num.push_back(1);
	num.push_back(-2);
	
	vector<vector<int> > ret = fourSum(num,4);
	for(int i = 0 ; i < ret.size();i++){
		vector<int> inn = ret[i];
		for(int j = 0 ;j<inn.size();j++)
			cout <<inn[j]<<" ";
		cout <<endl;
	}

}