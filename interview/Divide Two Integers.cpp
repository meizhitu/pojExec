//利用移位操作进行处理,在leetcode上过不了，精度问题不管了。
#include <iostream>
using namespace std;
int divide(int dividend, int divisor) {
	// Start typing your Java solution below
	// DO NOT write main() function
	if(divisor==0||dividend ==0) return 0;
	int sig = 0;
	if(dividend < 0){
		dividend = -dividend;
		sig ++;
	} 
	if(divisor < 0){
		divisor = -divisor;
		sig ++;
	}
	long dvd = dividend;
	long  divd = divisor;
	if(divd==1)
	{
		if(sig%2==0)
			return dividend;
		else
			return -dividend;
	}
		 
	int shifts = 0;
	 long tmp = divd; 
	//cout <<tmp<<endl;
	while(tmp<dvd){
		tmp = tmp << 1;
		shifts ++;
	//	cout <<tmp<<endl;
	}
	shifts --;
	int ret = 0 ;
	for(int i = shifts;i>=0 && dvd!=0;i--){
		ret += 1<<i;
		dvd -= divd<<i;
	}
	if(sig%2==1)
		return -ret;
	else 
		return ret;
}
int main(){
	cout <<divide(-2147483647,2)<<endl;
}