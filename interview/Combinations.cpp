#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ret;
void compute(int n ,int k,int idx, vector<int> combination){
	if(combination.size()==k) 
	{
		ret.push_back(combination);
		return;
	} ;
	for(int i = idx;i<=n;i++){
		//try
		combination.push_back(i);
		compute(n,k,i+1,combination);//每次都把i+1写成了idx+1=.=
		combination.pop_back();
	}

}
vector<vector<int> > combine(int n, int k) {
	ret.clear();
	if(n==0) return ret;
	compute(n,k,1,vector<int>());
	return ret;
}
int main(){
	vector<vector<int> > ret = combine(4,2);
	for(vector<vector<int> >::iterator it=ret.begin();it!=ret.end();it++){
		for(vector<int>::iterator in = (*it).begin();in != (*it).end();in++)
			cout <<*in<<" ";
		cout <<endl;
	}

}