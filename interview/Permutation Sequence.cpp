#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<char> ret;
//这种DFS搜索超时了
void compute(int n,int k,int idx,int *kth,vector<char> p,vector<bool> &used){
	if((*kth==k+1)) return;
	if(idx==n+1) {
		(*kth) ++;
		if(*kth == k)ret = p;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!used[i]&& (*kth)<k ){
			used[i] = true;
			p.push_back(i+'0');
			compute(n,k,idx+1,kth,p,used);
			p.pop_back();
			used[i] =false;
		}
	}
}
//只能说思路简单，但写法很巧。
//由K/(n-1)!来确定a1
//k=K%(n-1)!,k/(n-2)!来确定a2
string computeByMath(int n,int k){
	int nums[n+1];
	int permus = 1;
	string ret = "";
	//注意临界条件
	for(int i = 0 ; i<n;i++)
	{
		nums[i] = i+1;
		permus *= i+1;
	}
	k--;
	for(int i = 0;i<n;i++){
		permus /= n-i;
		int choosed = k/permus;
		ret += nums[choosed]+'0';
		//这里是比较神奇的。
		for(int j = choosed;j<n-i;j++)
			nums[j] = nums[j+1];
		k = k%permus;
	}

	return ret;
}
string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     if(n==0) return "";   
	 vector<char> p;
	 vector<bool> used(n+1);
	 int kth = 0 ;
	 compute(n,k,1,&kth,p,used);
	 string retS = "";
	for(int i = 0 ;i<ret.size();i++)
		retS += ret[i];
	 return retS;
}
int main(){
	//cout<<getPermutation(9,171669)<<endl;
	cout <<computeByMath(9,171669)<<endl;
}