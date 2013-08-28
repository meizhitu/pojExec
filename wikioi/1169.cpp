/*
小渊和小轩是好朋友也是同班同学，他们在一起总有谈不完的话题。一次素质拓展活动中，班上同学安排做成一个m行n列的矩阵，而小渊和小轩被安排在矩阵对角线的两端，因此，他们就无法直接交谈了。幸运的是，他们可以通过传纸条来进行交流。纸条要经由许多同学传到对方手里，小渊坐在矩阵的左上角，坐标(1,1)，小轩坐在矩阵的右下角，坐标(m,n)。从小渊传到小轩的纸条只可以向下或者向右传递，从小轩传给小渊的纸条只可以向上或者向左传递。
在活动进行中，小渊希望给小轩传递一张纸条，同时希望小轩给他回复。班里每个同学都可以帮他们传递，但只会帮他们一次，也就是说如果此人在小渊递给小轩纸条的时候帮忙，那么在小轩递给小渊的时候就不会再帮忙。反之亦然。
还有一件事情需要注意，全班每个同学愿意帮忙的好感度有高有低（注意：小渊和小轩的好心程度没有定义，输入时用0表示），可以用一个0-100的自然数来表示，数越大表示越好心。小渊和小轩希望尽可能找好心程度高的同学来帮忙传纸条，即找到来回两条传递路径，使得这两条路径上同学的好心程度只和最大。现在，请你帮助小渊和小轩找到这样的两条路径。
*/
//将来回的两条路转换成同事
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int m,n,i,j,k,s[101][101],dp[101][101][101],ans;
int main()
{
     while (~scanf("%d%d",&m,&n))
     {
           for (i=1;i<=m;i++)
              for (j=1;j<=n;j++) 
				  scanf("%d",&s[i][j]);      
           memset(dp,0,sizeof(dp)); 
           dp[3][1][2]=s[2][1]+s[1][2];
           for (k=4;k<m+n;k++)
           { 
                 for (i=1;i<k;i++)  
                 if (k-i<=m)
                 { 
                       for (j=i+1;j<k;j++)
                       if (k-j<=m)
                       {      
                              if (i!=1) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j-1]);
                              if (i!=1 && j!=k-1) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i-1][j]);
                              if (j-i!=1) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j-1]);
                              if (j!=k-1) dp[k][i][j]=max(dp[k][i][j],dp[k-1][i][j]); 
                              dp[k][i][j]+=s[k-i][i]+s[k-j][j];
                       }
                 }
           }
           if (m==1 || n==1) ans=0;
           else ans=dp[m+n-1][n-1][n];
           printf("%d\n",ans); 
     } 
     return 0;   
}