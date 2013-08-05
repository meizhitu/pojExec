/*POJ1191棋盘分隔，刘汝佳黑书面有解析，大概思路如下：
* 根据方差公式推倒出如果需要方差最小，则需要每个被减数的平方最小，即每块棋盘的总分平方和最小
* 考虑左上角坐标为(x1,y1),右下角坐标为(x2,y2)的棋盘，设它的总和为sum[x1,y1,x2,y2]切割k次以后得到 
* k+1块矩形的总分平方和最小值为d[k,x1,y1,x2,y2]，则它可以沿着横线切，也可以沿着竖线切，然后选一
* 块继续切（递归）。。
* 状态转移方程：
* d[k,x1,y1,x2,y2]=min{
* min{d[k-1,x1,y1,a,y2]+s[a+1,y1,x2,y2]^2,d[k-1,a+1,y1,x2,y2]+s[x1,y1,a,y2]^2},
* min{d[k-1,x1,y1,x2,b]+s[x1,b+1,x2,y2]^2,d[k-1,x1,b+1,x2,y2]+s[x1,y1,x2,b]^2}}
* 其中：(x1<=a * 为便于理解，这里用的是递归的方法，另附网上牛人循环的办法。
*/
#include <iostream> 
#include <cstring> 
#include <iomanip> 
#include <cmath> 
using namespace std; 
int m[9][9]; 
int sum[9][9]; 
int d[15][9][9][9][9]; 
int needsum(int x1,int y1,int x2,int y2) 
	{return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];} 
int min(int a,int b) 
	{ return a>b?b:a; } 
int fun(int k,int x1,int y1,int x2,int y2) 
{ 
	int t,a,b,c,e,MIN=10000000; 
	if(d[k][x1][y1][x2][y2] !=-1) 
		return d[k][x1][y1][x2][y2]; 
	if(k==0) 
	{ 
		t=needsum(x1,y1,x2,y2); 
		d[k][x1][y1][x2][y2]=t*t; 
		return t*t; 
	} 
	for(a=x1;a<x2;a++) 
	{ 
		c=needsum(a+1,y1,x2,y2); 
		e=needsum(x1,y1,a,y2); 
		t=min(fun(k-1,x1,y1,a,y2)+c*c,fun(k-1,a+1,y1,x2,y2)+e*e); 
		if(MIN>t) MIN=t; 
	} 
	for(b=y1;b<y2;b++) 
	{ 
		c=needsum(x1,b+1,x2,y2); 
		e=needsum(x1,y1,x2,b); 
		t=min(fun(k-1,x1,y1,x2,b)+c*c,fun(k-1,x1,b+1,x2,y2)+e*e); 
		if(MIN>t) MIN=t; 
	} 
	d[k][x1][y1][x2][y2]=MIN; 
	return MIN; 
} 
int main() 
{ 
	memset(sum ,0 ,sizeof(sum)); 
	memset(d ,-1 ,sizeof(d)); 
	int n; 
	cin>>n; 
	for (int i=1;i<9;i++) 
		for (int j=1,rowsum=0;j<9;j++) 
	{ 
		cin>>m[i][j]; 
		rowsum +=m[i][j]; 
		sum[i][j] += sum[i-1][j] + rowsum; 
	} 
	double result = n*fun(n-1,1,1,8,8)-sum[8][8]*sum[8][8]; 
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n))<<endl; 
	return 0; 
} 
