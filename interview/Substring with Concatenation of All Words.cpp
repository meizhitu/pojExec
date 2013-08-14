//找出s中包含L所有单词（且每个单词只包含一次）的子串的起始位置，子串完全由L中的单词构成，不含有其他的单词。
//顺次从s的各个位置开始，判断L中的单词是否出现。
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int n = L.size();
	vector<int> ret;
	if(n==0) return ret;
	int m = L[0].size();
	map<string,int> words;//记录L中的单词出现次数
	
	for(int i = 0 ; i< n;i++)
        words[L[i]]++;
	int len = S.size();
	for(int i = 0 ; i<= len-n*m;i++)
	{
		int j = 0 ;
		map<string,int> inS;//记录S中的单词出现次数
		for(;j<n;j++){
			string tmp = S.substr(i+j*m,m);
			if(words.find(tmp) == words.end())
				break;
			inS[tmp]++;
			if(inS[tmp] > words[tmp])break;//如果子串中某个单词出现的次数过多
		}
		if(j==n)
			ret.push_back(i);
	}
	return ret;
}
int main(){
	string s = "barfoothefoobarman";
	vector<string> words;
	words.push_back("bar");
	words.push_back("foo");
	vector<int> ret = findSubstring(s,words);
	for(int i = 0; i< ret.size();i++)
		cout <<ret[i]<<endl;

}