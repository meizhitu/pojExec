/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> ret;
void compute(string s,int startIdx,int partNum,string aIp){
	//cout <<startIdx<<" "<<partNum<<endl;
	if(s.size()==0) return;
	if(startIdx>s.size()) return;
	//最大长度为12
	if(s.size()>12) return;
	//计算到了最后
	if(startIdx == s.size()&&partNum == 4){
		aIp.resize(aIp.size()-1);
		ret.push_back(aIp);
		return;
	}
	int num = 0;
	for(int i = startIdx;i<startIdx+3;i++){
		num = num*10+s[i]-'0';
		aIp += s[i];
		if(num<256)
			compute(s,i+1,partNum+1,aIp+".");
		//如果num为0，则其后的01不必再计算
		if(num == 0)	
			break;
	}
}
vector<string> restoreIpAddresses(string s) {
	if(s.size()==0) return vector<string>();
	ret.clear();
	string aIp="";
    compute(s,0,0,aIp);
	return ret;
}
int main(){
	string s = "010010";
	vector<string> ips = restoreIpAddresses(s);
	return 0;
}
