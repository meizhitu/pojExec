#include <iostream>
using namespace std;
//大数据超时，需要使用KMP算法
/*
char *strStr(char *haystack, char *needle) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(*haystack=='\0'&& *needle=='\0') return haystack;
	if(*haystack=='\0') return NULL;
	char * p = haystack;
	for(;*p;p++){
		char * cur = p;
		cout <<"cur "<<*cur<<endl;
		char * n = needle;
		for(;*cur && *n;cur++,n++)
			if(*cur != *n)
				break;
		if(*n=='\0') return p;
	}
}
*/
//生成next数组
//next[1] = 0;
//next[j] = max{k|a1...ak-1=aj-k+1...aj-1} （当集合不空的时候)
//其他情况为1
void generateNext(char * str,int next[]){
	next[0] = 0 ;
	next[1] = 0;
	int len = strlen(str);
	int i = 1;
	int j = 0 ;
	while(i<=len){
		if(j==0 || str[i-1]==str[j-1]){
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
char *strStr(char *haystack, char *needle) {
	if(*haystack=='\0'&& *needle=='\0') return haystack;
	if(*haystack=='\0') return NULL;
	int l1 = strlen(haystack);
	int l2 = strlen(needle);
	int i = 1;
	int j = 1;
	int next[100000];
	generateNext(needle,next);
	while(i<=l1 && j<=l2){
		if(j==0 ||haystack[i-1]==needle[j-1]){//如果字符相等，则i,j均向后移动。
			i++;
			j++;
		}
		else{
			j = next[j];//i不需要移动，j移动到next[j]的位置
		}
	}
	if(j>=l2+1) return &haystack[i-l2-1];
	return NULL;
}

int main(){
	int n[5];
	char * t = "aaaaab";
	char * s ="caaaaab";
	generateNext(t,n);
	for(int i = 0 ;i<5;i++)
		cout <<n[i]<<endl;
	char * p = strStr(s,t);
	cout<<(p-s)<<endl;
}