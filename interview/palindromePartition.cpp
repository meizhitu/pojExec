/*
Given a string s, partition s such that every substring of the partition is a palindrome.

	Return all possible palindrome partitioning of s.

		For example, given s = "aab",
Return

	[
		["aa","b"],
["a","a","b"]
	]

*/
#include <stdio.h>
#include <iostream>
#include <vector>
		;
using namespace std;
bool palin[1500][1500];
vector<vector<string> > retVString ; 
void dfs (string& s, int start, vector<string> palinStr)
{
	if(start == s.size())
	{
		retVString.push_back(palinStr);
	}
	for(int i = start; i < s.size(); i++)
	{
		if(palin[start][i])
		{
			palinStr.push_back(s.substr(start, i - start + 1));
			dfs(s, i+1, palinStr);
			palinStr.pop_back();
		}
	}
}
vector<vector<string> > partition(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(s.size() == 0)
		return vector<vector<string> >();
	int leng = s.size();
	for(int i = 0; i < leng; i++)
		for(int j = 0; j < leng; j++)
			palin[i][j] = false;
	for(int interval=0;interval<leng;interval++)
	{
		for(int i = 0;i<leng&&(i+interval)<leng;i++)
		{
			if(interval ==0) palin[i][i+interval] = true;
			else if(s[i]==s[i+interval]&&(interval==1 || palin[i+1][i+interval-1]))
				palin[i][i+interval] = true;
		}
	}
       
	retVString.clear();
	dfs(s, 0, vector<string>());
	return retVString; 
}
	
int main(){
	string s = "cdd";
	partition(s);
	vector<vector<string> >::iterator it;
	for(it=retVString.begin();it!=retVString.end();it++)
	{
		vector<string>::iterator inner = (*it).begin();	
		for(;inner!=(*it).end();inner++)
			cout<<*inner<<" ";
		cout<<endl;
	}
	return 0;
}