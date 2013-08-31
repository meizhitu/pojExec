#include <stdio.h>
#include <math.h>
int n; 
int sum = 0;   
int pos[15];//pos的下标为行号，值为列号 
int judge(int x)   
{   
	int i;   
	for(i = 1; i < x; i++)//判断是否在同一斜线或同列
		if(fabs(x - i) == fabs(pos[x] - pos[i]) || pos[x] == pos[i])
			return 0;
	return 1;   
}   
int place(int x)   
{   
	if(x > n && n > 0) //当放置的皇后超过n时，可行解个数加1，此时n必须大于0   
		sum++;   
	else
		for(int i = 1; i <= n; i++)//遍历列数 
	{   
		pos[x] = i; //标明第x个皇后放在第x行第i列  
		if(judge(x)) //judge函数判断第x个皇后放在x行i列是否可行 
			place(x + 1);//若可行则将第x+1个皇后在第x+1行
	}   
	return sum;   
}   
int main()   
{   
	int ans;   
	scanf("%d", &n);   
	ans = place(1);   
	if(n == 0)
		ans = 0;
	printf("%d\n", ans);   
	return 0;   
} 