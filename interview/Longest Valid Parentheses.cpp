/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4

*/
#include <iostream>
#include <vector>
#include <stack>
	using namespace std;
int longestValidParentheses(string s) {
	const char* str = s.c_str();  
	const char * p = str;
	stack<char*> q;
	int len = 0 ;
    for(;*p;p++){
		if(*p=='(')
			q.push((char*)p);
		else{
			if(!q.empty() && *(q.top())=='(')
			{
				q.pop();
				if(!q.empty())
					len = len>(p-q.top())?len:p-q.top();
				else
					len = len>(p-str+1)?len:p-str+1;
			}
			else{
				q.push((char*)p);
			}
		}
	//	cout <<len<<endl;
	}
	return len;
}
int main(){
	string s = ")()())";
	cout << longestValidParentheses(s)<<endl;
}