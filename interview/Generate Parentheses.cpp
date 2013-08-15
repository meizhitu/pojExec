//典型的递归。一步步构造字符串。当左括号出现次数<n时，
//就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号。
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> ret; 
void compute(int n ,string &p,int idx,int left,int right){
	if(idx == 2*n){
		ret.push_back(p);
		return;
	}
	if(left<n){
		p+= "(";
		compute(n,p,idx+1,left+1,right);
		p.resize(p.size()-1);
	}
	if(right<left)
	{
		p += ")";
		compute(n,p,idx+1,left,right+1);
		p.resize(p.size()-1);
	}

}
vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	ret.clear();
	if(0==n) return ret;
	string p ;
	compute(n,p,0,0,0);
	return ret;
}
int main(){
	vector<string> ret = generateParenthesis(3);
	for(int i = 0 ;i<ret.size();i++)
		cout << ret[i]<<" ";
	cout<<endl;

}