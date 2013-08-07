//map搜素，map底层是红黑树,坑爹的蛋碎
//11937026	momoliu	2418	Accepted	776K	1797MS	C++	961B	2013-08-07 13:53:06
#include <iostream>
#include <stdio.h>

#include <map>
#include <string>
#include <algorithm>
#include <iomanip>      // std::setprecision


using namespace std;
map<string,int> m;
map<string,int >::iterator it;

typedef struct Node{
	string s;
	double count;
}Node;
int total = 0 ;
Node nodes[10010];
bool cmp(Node a,Node b){
	if(a.s.compare(b.s)<=0)
		return true;
	return false;
}
void compute(){
 	for(it = m.begin();it!=m.end();it++)
		cout<<it->first<<" "<<fixed<<setprecision(4)<<it->second*100.0/total<<endl;
}
void addToMap(string s){
 	it = m.find(s);
	if(it==m.end()){
 		m.insert(pair<string,int>(string(s),1));
	}
	else{		
 		(it->second)++;
 	}	
	total ++;
 }
int main(){
	string s;
	char c[50];
	s.clear();
	memset(c,0,sizeof(c));
	freopen("2418.txt","r",stdin);
	while(gets(c))
	{
		s = c;
		addToMap(s);
		s.clear();
		memset(c,0,sizeof(c));
		
	}
	compute();
	return 0;
}