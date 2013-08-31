#include <iostream>
using namespace std;
//跳过前面的空格，数字前面可能存在+,-。如果数字后面有字母，则直接返回前面的数字。
int atoi(const char *str) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(str==0|| *str=='\0') return 0;
	//排序前面的空格
	while(*str && *str==' ') str++;
	int isNeg = 1;
	//判断前面的符号
	if(*str=='+')str++;
	if(*str=='-'){
		isNeg = -1;
		str ++;
	}
	const char * p = str;
	long long ret = 0;
	for(;*p;p++){
		if(!(*p>='0'&&*p<='9')) return isNeg*ret;
		ret = 10*ret +(*p-'0');
		if(isNeg*ret>INT_MAX) return INT_MAX;
		if(isNeg*ret<INT_MIN) return INT_MIN;
	}
	return isNeg*ret;
}
int main(){
	cout <<atoi(" 2147483648")<<endl;
}