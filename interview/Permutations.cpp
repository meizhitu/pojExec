#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >  ret ;
void compute(vector<int> &num,vector<bool> &used,vector<int> p){
	if(p.size()==num.size()){
		ret.push_back(p);
		return;
	}
	for(int i = 0;i<num.size();i++){
		if(!used[i]){
			used[i] = true;
			p.push_back(num[i]);
			compute(num,used,p);
			p.pop_back();
			used[i] = false;
		}
	
	}
}
vector<vector<int> > permute(vector<int> &num) {
	ret.clear();
	if(num.size()==0) return ret;
	vector<bool> used(num.size(),false);
	compute(num,used,vector<int>());
	return ret;
}
int main(){
}