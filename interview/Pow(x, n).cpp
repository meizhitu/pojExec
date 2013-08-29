#include <iostream>
//好吧原来比较正规军的写法是二分。
double power(double x, int n) {
	if(n==0) return 1;
	double v = power(x,n/2);
	if(n%2==0)return v*v;
	else
		return v*v*x;
}
//注意几种情况：x=1,-1,无限接近0
using namespace std;
double pow(double x, int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(n==0) return 1;
	double ret =1;
	if(fabs(x-1)<1e-7) return 1; //x为1
	if(fabs(x+1)<1e-7){  //x为-1
		if(n%2==0)
			return 1;
		else return -1;
	}
	bool isN = false;
	if(n<0){
		isN= true; 
		n = -n;
	} 
	for(int i = 1;i<=n;i++)
	{
		ret *= x;
		if(fabs(ret-0)<1e-7)//如果ret接近为0了，不要再计算了。
			return 0;
	}
	if(isN)
		ret = 1/ret;
	return ret;
}