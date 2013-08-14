#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<string> anagrams(vector<string> &strs) {
	//if(strs.size()==0) return vector<string>();
	map<string,int> ms;
	vector<string> ret;
	ret.clear();
	for(int i = 0 ; i<strs.size();i++){
		string s = strs[i];
		sort(s.begin(),s.end());
		if(ms.find(s)==ms.end())
			ms[s] = i;
		else{
		//	cout << ms[s]<<endl;
			if(ms[s]>=0){
				ret.push_back(strs[ms[s]]);
				ms[s] = -1;
			}
			ret.push_back(strs[i]);
		}
	}
	return ret;
}
int main(){
	vector<string> strs;
	strs.push_back("");
	strs.push_back("");
	strs.push_back("aaa");
	
	vector<string> ret = anagrams(strs);
	cout <<ret.size()<<endl;
	for(int i = 0 ; i < ret.size();i++)
		cout <<ret[i]<<endl;
}