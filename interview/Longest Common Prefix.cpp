#include <iostream>
#include <vector>
//Trie树计算多个string的最长公共前缀
using namespace std;
typedef struct Node{
	Node * next[1000];
	int nextNums;
	char c;
	int idx;
	bool end;
	Node() : nextNums(0) ,end(false) {}
}Node;
void build(string s,Node * root){
	Node * p = root;
	for(int i = 0; i < s.size();i++){
		int id = s[i];
		if(!p->next[id]){
			p->next[id] = new Node;
			p->nextNums ++;
		//	p->c = s[i];
			p->idx = id;
		}
		p = p->next[id];
		p->c = s[i];
		
	}
	p->end = true;
}
string ret ;
string longestCommonPrefix(vector<string> &strs) {
	Node * root = new Node;
	vector<string>::iterator it = strs.begin();
	for(it=strs.begin();it!=strs.end();it++)
		if((*it).size()==0) return "";
	for(it=strs.begin();it!=strs.end();it++)
		build(*it,root);
	Node * p = root;
	ret.clear();
	while(p&&p->nextNums==1&&!p->end){
		p = p->next[p->idx];
		ret += p->c;
	}
	return ret;
}
int main(){
	vector<string> strs;
	strs.push_back("a");
	strs.push_back("b");
//	strs.push_back("abadl");
	
	cout <<longestCommonPrefix(strs)<<endl;

}