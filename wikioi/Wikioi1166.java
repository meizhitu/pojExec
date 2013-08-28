package wikioi;

import java.math.BigInteger;
import java.util.Scanner;
/*
 * 【问题描述】
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n*m 的矩阵，矩阵中的每个元素aij均
为非负整数。游戏规则如下：
1. 每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有元素；
2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
3. 每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分= 被取走的元素值*2i，
其中i 表示第i 次取数（从1 开始编号）；
4. 游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。
动态规划：dp[i][j]表示从i到j按照上述规则所获得的最大得分总数。
dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j])*2;
 * 
 * */
public class Wikioi1166 {
	static int a[][];
	//每行独立，计算dp[l][r]
	private static BigInteger solve(int i,int l,int r){
		BigInteger ret;
		if(l==r) 
		{
			return BigInteger.valueOf(a[i][l]*2);

		}
		ret = solve(i,l+1,r).add(BigInteger.valueOf(a[i][l]));
		ret = ret.max(solve(i,l,r-1).add(BigInteger.valueOf(a[i][r])));
		return ret.multiply(BigInteger.valueOf(2));
	}
	
	public static void main(String args[]){
		int n,m;
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		m = scanner.nextInt();
		 a = new int[n+1][m+1];
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				a[i][j] = scanner.nextInt();
		BigInteger sum = BigInteger.valueOf(0);
		for(int i = 1;i<=n;i++){
			sum = sum.add(solve(i,1,m));
		}
		System.out.println(sum);
	}
}
