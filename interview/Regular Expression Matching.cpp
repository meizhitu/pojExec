//匹配?和其他字符相同，而匹配*的时候，记录下*的位置，然后忽略掉*继续匹配，如果发现匹配出错，则退回*,把待匹配字符的指针往后移动。
#include <iostream>
using namespace std;
bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function 
	if (*p == '\0') return *s == '\0';
	if (*(p+1) != '*') {
		if (*p == *s || *p == '.' && (*s) != '\0') return isMatch(s+1, p+1);
		return false;
	}
	else {
		while (*p == *s || *p == '.' && (*s) != '\0') {
			if (isMatch(s, p+2)) return true;
			s++;
		}
		return isMatch(s, p+2);
            
	}
	int main(){
		cout<<isMatch("aab","c*a*b")<<endl;

	}
