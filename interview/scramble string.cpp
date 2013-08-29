//递归判断两个字符串是否符合scramble的定义。
#include <iostream>
#include <string>
using namespace std;
bool compute(string s1,string s2){
	if(s1.size()!= s2.size()) return false;
	int A[26];
	memset(A,0,sizeof(A));
	//判断两个字符串是否相等
	for(int i = 0 ;  i< s1.size();i++)
		A[s1[i]-'a'] ++;
	for(int i = 0 ;  i< s2.size();i++)
		A[s2[i]-'a']--;
	for(int i = 0; i < 26;i++)
		if(A[i]>0) return false;
	//判断两个字符串是否相等
	
	int len = s1.size();
	if(len==1) return true;
	bool ret =false;
	for(int i = 1 ;i<len;i++)
	{
		ret = compute(s1.substr(0,i),s2.substr(0,i))
			&& compute(s1.substr(i,len-i),s2.substr(i,len-i));
		if(ret) return true;
		ret = ret ||(compute(s1.substr(0,i),s2.substr(len-i,i))&&compute(s1.substr(i,len-i),s2.substr(0,len-i)));
		if(ret) return true;
	}
	return false;

}
bool isScramble(string s1, string s2) {   
	if(s1.size() != s2.size()) return false;
	return compute(s1,s2);
}
int main(){
	string s = "abc";
	string s1 = "bca";
	cout <<isScramble(s,s1)<<endl;
}
