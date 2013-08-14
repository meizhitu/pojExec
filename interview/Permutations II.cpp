#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >  ret ;
void compute(vector<int> &num,vector<bool> &used,vector<int> p){
	if(p.size()==num.size()){
		ret.push_back(p);
		return;
	}
	int prev = INT_MIN; //测试用例中存在-1=。=
	for(int i = 0;i<num.size();i++){
		if(prev == num[i])//如果当前值已经试探过了就不要再试探了。
			continue;
		if(!used[i]){
			used[i] = true;
			p.push_back(num[i]);
			compute(num,used,p);
			p.pop_back();
			used[i] = false;
			prev = num[i];
		}
	
	}
}
vector<vector<int> > permuteUnique(vector<int> &num) {
	ret.clear();
	if(num.size()==0) return ret;
	sort(num.begin(),num.end());
	vector<bool> used(num.size(),false);
	compute(num,used,vector<int>());
	return ret;
}
int main(){
	
}
