#include <iostream>
#include <vector>
//dfs
/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
**/
	using namespace std;

vector<vector<int> > ret;
void compute(vector<int> &cands,int target,int idx,int sum,vector<int> p){
	if(sum > target) return;
	if(sum == target){
		ret.push_back(p);
		return;
	}
	//和1的区别在于，每个数最多选择一次。
	for(int i = idx;i<cands.size();i++){
		if(cands[i]<=target){
			p.push_back(cands[i]);
			compute(cands,target,i+1,sum+cands[i],p);
			p.pop_back();
			//如果下一个数和当前数字相同，则不需要再次计算。
			while(i+1<cands.size() && cands[i+1]==cands[i])
				i++;
		}
		
	
	}
}
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	ret.clear();
	if(candidates.size()==0) return ret;
	sort(candidates.begin(),candidates.end());
	compute(candidates,target,0,0,vector<int>());
	return ret;
}
int main(){
	vector<int> cands;
	cands.push_back(10);
	cands.push_back(1);
	cands.push_back(2);
	cands.push_back(7);
	cands.push_back(6);
	cands.push_back(1);
	cands.push_back(5);
	
	vector<vector<int> > ret = combinationSum(cands,8);
	for(int i =  0; i< ret.size();i++){
		vector<int > inn = ret[i];
		for(int j = 0 ; j< inn.size();j++)
			cout << inn[j]<<" ";
		cout <<endl;
	}
}