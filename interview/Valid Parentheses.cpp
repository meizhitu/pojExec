#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(s=="") return false;
	stack<char> st;
	for(int i = 0 ; i<s.size();i++){
		if(s[i]=='('||s[i]=='{'||s[i]=='['){
			st.push(s[i]);
		}
		else{
			if(s[i]==')')
			{
				if(st.empty()) return false;
				if(st.top()!='(') return false;
				st.pop();
			}
			if(s[i]==']'){
				if(st.empty()) return false;
				if(st.top()!='[') return false;
				st.pop();
			}
			if(s[i]=='}'){
				if(st.empty()) return false;
				if(st.top()!='{') return false;
				st.pop();
			}
		}
	}
	if(st.empty()) return true;
	return false;
}
int main(){
	string s="{[]}";
	cout << isValid(s)<<endl;
}