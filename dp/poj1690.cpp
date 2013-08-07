/*括号的操作。和dp没有啥关系，复习了逆波兰式*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
using namespace std;
#define MAXN 300
stack<char> s1;
stack<string> s2;
char str[MAXN];
char ori[MAXN];
char str2[MAXN];
bool cmp(char a,char b){
	if(a=='(' && (b =='+'||b=='-'||b=='(')) return true;
	if(a=='-' && (b=='(')) return true;
	if(a=='+' && (b=='-'||b=='(')) return true;
	
	return false;
}
void pushIntoS2(){
	
	int len = strlen(str2);
 	
	for(int i = 0;i<len;i++){
		string con;
		con += str2[i];
		if(str2[i]<='Z' && str2[i]>='A')
			s2.push(con);
		else
		{
			string a = s2.top();
			s2.pop();
			//-(a+a)
			if(s2.empty()){
				if(con=="-"){
					if(a.size()>1)
						a = '('+a+')';
				}
				s2.push(con+a);
			}
			else{
				//a-b
				string b = s2.top();
				s2.pop();
				if(str2[i]=='-'){
					if(a.size()>1)
						a = '('+a+')';
				}
				s2.push(b+con+a);
			}
		}
	}
	string ret;
	if(len>0){
		ret = s2.top();
		s2.pop();
	}
	cout<<ret<<endl;
}
//将表达式转换成逆波兰式
void pushIntoS1(){
	int len = strlen(str);
	int k = 0;
	memset(str2,0,sizeof(str2));
	for(int i = 0;i<len;i++)
	{
		if(str[i]==' ')continue;
		if(str[i]<='Z' && str[i]>='A')
			str2[k++] = str[i];
		else{
			if(s1.empty()){
				s1.push(str[i]);
			}
			else
			{
				if(str[i]==')'){
					while(s1.top()!='('){
						str2[k++] = s1.top();
						s1.pop();
					}
					s1.pop();						
				}
				else{
					//如果str[i]的优先级低于top的优先级，则弹出,有点绕
					if(!cmp(s1.top(),str[i]))
					{
						str2[k++] = s1.top();
						s1.pop();
					}
					s1.push(str[i]);
				}
			}
		}
	}
}
int main(){
	int n;
	freopen("1690.txt","r",stdin);
	scanf("%d",&n);
	
	gets(str);
	while(n--){
		gets(ori);
		//在原字符串首尾加上(),方便统一处理
		str[0]='(';
		strcpy(str+1,ori);
		str[strlen(ori)+1]=')';
	
		pushIntoS1();	
		pushIntoS2();
		memset(str,0,sizeof(str));
		memset(str2,0,sizeof(str2));
		memset(ori,0,sizeof(ori));
		
	}
}
