/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

*/
	//仅仅判断字符串中的字母和数字是否能构成回文串。
#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	string a;
	if(s=="") return true;
	for(int i = 0 ; i<s.size();i++){
		if((s[i]>='a' && s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
			a += s[i];
		}
		if(s[i]>='A'&&s[i]<='Z'){
			a+= s[i]-('Z'-'z');
		}
	}
	int i= 0 ;
	int j = a.size()-1;
	int mid = j>>1;
	while(i<=mid&& j>=mid){
		if(a[i]!=a[j])
			return false;
		i++;j--;
	}
	return true;
}
int main(){
	cout << isPalindrome("1a2")<<endl;
}