//罗马数字转换成整数：如果前一个数字比当前数字大，则相加；如果前一个数字比
#include <iostream>
#include <string>
#include <map>

using namespace std;
int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  	if(s.size()==0) return 0;
	map<char,int> ms;
	ms['I']=1;
	ms['V'] = 5;
	ms['X'] = 10;
	ms['L'] = 50;
	ms['C'] = 100;
	ms['D'] = 500;
	ms['M'] = 1000;
	int ret = 0 ;
	for(int i = 0; i<s.size();i++){
		if(i>=1 && ms[s[i]] > ms[s[i-1]] )
			ret += ms[s[i]] - ms[s[i-1]]*2; //注意这里需要减去之前加上的那个值
		else
			ret += ms[s[i]];//直接添加上当前的值
	}
	return ret;
}
int main(){}