//给出一个n, 请输出n的所有全排列

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<string> rets;
void compute(vector<bool> &used,char* p,int n){
	if(strlen(p)==n){
		printf("%c",p[0]);
		
		for(int i = 1;i<strlen(p);i++)
		printf(" %c",p[i]);
		printf("\n");
		return;
	} 
	for(int i = 1;i<=n;i++){	
		if(!used[i]){
			used[i] = true;
			char tmp[15];
			strcpy(tmp,p);
			int len = strlen(tmp);
			if(i==10){
				tmp[len]='1';
				tmp[len+1] = '0';
				tmp[len+2]=0;
			}
			else
			{
				tmp[len]=i+'0';
				tmp[len+1] = 0;
			//	tmp[len+2]=0;
			}
			compute(used,tmp,n);
		//	p.resize(p.size()-1);
			used[i] =false;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	vector<bool> used(n,false);
	char p[15];
	memset(p,0,sizeof(p));
	compute(used,p,n);
	
}