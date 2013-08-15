//匹配?和其他字符相同，而匹配*的时候，记录下*的位置，然后忽略掉*继续匹配，如果发现匹配出错，则退回*,把待匹配字符的指针往后移动。
#include <iostream>
using namespace std;
bool isMatch(const char *s, const char *p) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(s==""&&p=="") return true;
	if(s==""||p=="") return false;
	const char * str = s;
	const char * ptr = p;
	bool hasStar = false;
	for(;*str;str++,ptr++){
		cout<<*str<<" "<<*ptr<<endl;
		switch(*ptr){
			case '?':break;//直接跳过
			case '*':
				hasStar = true;
				p = ptr;
				while(*p=='*')
					p++;
				if(!(*p))return true;
				s = str;
				str = s-1;
				ptr = p-1;
				break;
			default:
			if((*str) != (*ptr))
			{
				cout <<"not equal"<<endl;
				if(!hasStar) return false;
				s++;
				str = s-1;
				ptr = p-1;
			}
			break;
		}
	}
	
	while(*ptr=='*')
		*ptr ++;
	return *ptr=='\0';
}
int main(){
	cout<<isMatch("aab","c*a*b")<<endl;

}