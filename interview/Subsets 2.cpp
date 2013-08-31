//给定一个数组S，其中包含重复的元素，算出S所含有的所有子集。
/*
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >  ret ;
void compute(vector<int> &S,int idx,vector<int> aSet){
	if(idx >= S.size()) return;
	for(int i = idx;i<S.size();i++)
	{
		aSet.push_back(S[i]);
		ret.push_back(aSet);
		compute(S,i+1,aSet);
		aSet.pop_back();
		//[1,1]计算完前面的1后，后面的1直接跳过
		while(i+1<S.size() && S[i]==S[i+1])
			i++;	
	}
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function
	ret.clear();
	//子集可以为空
	ret.push_back(vector<int>());
	if(S.size() ==0)return ret;
	sort(S.begin(),S.end());
	compute(S,0,vector<int>());
	return ret;
}
int main()
{
	vector<int> S;
		S.push_back(1);
	S.push_back(1);
//	S.push_back(3);
	vector<vector<int> > ret = subsetsWithDup(S);
	for(vector<vector<int> >::iterator it=ret.begin();it!=ret.end();it++){
		for(vector<int>::iterator inn = (*it).begin();inn!=(*it).end();inn++)
			cout <<*inn<<" ";
		cout<<endl;
	}
}