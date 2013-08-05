#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stdio.h>
#include <string.h>
#define MAXLEN 100000
using namespace std;
char S[MAXLEN];
int freqs[30];
int huffman(){

	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 0; S[i];i++)
	{
		if(S[i]=='_') freqs[29]++;
		else
			freqs[(S[i]-'A')]++;
	}
	for(int i = 0 ;i<=29;i++){
		if(freqs[i] !=0)
			q.push(freqs[i]);
	}
	int codeLen = 0 ;
	while(!q.empty()){
		int a = q.top();
		q.pop();
		codeLen +=a;
		if(q.empty()) break;
		int b = q.top();
		q.pop();		
		codeLen += b;
		if(q.empty()) break;
		q.push(a+b);
	}
	return codeLen;
}
bool quit(){
	return strcmp("END",S);

}
int main()
{
	memset(S,0,sizeof(S));
	memset(freqs,0,sizeof(freqs));
	freopen("1521.txt","r",stdin);
	while(scanf("%s",S)&& quit()!=0){
		
		int codeLen = huffman();
		int len = strlen(S);
		printf("%d %d %0.1f\n",len*8, codeLen,len*8.0/codeLen);
		memset(S,0,sizeof(S));
		memset(freqs,0,sizeof(freqs));
	}
	
}