#include <iostream>
#include <stack>
using namespace std;
string simplifyPath(string path) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	stack<string> s;
	string element;
	element.clear();
	for(int i = 0 ;i <path.size();i++){
		if(path[i]=='/'){	
			if(element==".."){
				if(!s.empty())
					s.pop();
			}	
			else {
				if(element!="." && element.size()!=0)
					s.push(element);
			}	
			element.clear();			
		}
		else
			element += path[i];
	}
	//path的最后一个字符不一定是/	
	if(element == ".."){
		if(!s.empty())
			s.pop();
	}
	else if(element != "." && element.size()>0)
		s.push(element);
	string ret = "";
	while(!s.empty())
	{
		ret = s.top()+"/"+ret;
		s.pop();
	}
	if(ret.size()>1)
		ret.resize(ret.size()-1);
	return "/"+ret;
}
int main(){
	cout <<simplifyPath("/")<<endl;

}