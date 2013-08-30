/*
给出一个长度不超过200的由小写英文字母组成的字母串(约定;该字串以每行20个字母的方式输入，且保证每行一定为20个)。要求将此字母串分成k份(1<k<=40)，且每份中包含的单词个数加起来总数最大(每份中包含的单词可以部分重叠。当选用一个单词之后，其第一个字母不能再用。例如字符串this中可包含this和is，选用this之后就不能包含th)（管理员注：这里的不能再用指的是位置，不是字母本身。比如thisis可以算做包含2个is）。
单词在给出的一个不超过6个单词的字典中。
要求输出最大的个数。
*/
#include <stdio.h>
#include <string.h>

int word[201][201], dp[201][201][41];
char c[21], w[6][10], c0[201], c1[201];
int d, p, k, s, max, le[6], len;

int main()
{
	int i, j, l, m, yes, x, st;
	freopen("1040.txt","r",stdin);
 	scanf("%d", &d);
 	while(d--) //case数
	{
		scanf("%d%d", &p, &k);
  		for(j = 0; j < p; j++)
		{
   			scanf("%s", c);
   			if(j == 0)	strcpy(c0, c);
   			else		strcat(c0, c);
  		}
  		len = strlen(c0);
		printf("ori=%s\n",c0);
  		scanf("%d", &s); //字典的单词个数
  		for(j = 0; j < s; j++)
		{
   			scanf("%s", w[j]);
   			le[j] = strlen(w[j]);
  		}
  		for(i = 0; i < len; i++)
   			for(j = 0; j < len; j++)
    			word[i][j] = 0; 
//************************************************************************
/*算出第j个:c0[j-1]到第i个:c0[i-1]不分时最多有单词word[j][i]个*/
  		for(i = len-1; i >= 0; i--) 
   			for(j = i; j >= 0; j--)
			{
    			for(l = 0; l < s; l++)
				{
     				yes = 0;
     				if(c0[j] == w[l][0] && le[l] <= i-j+1)
					{
      					yes = 1; 
      					for(m = 0; m < le[l]; m++)
       						if(c0[j+m] != w[l][m])
       						{
						   		yes = 0; 
						   		break; 
							}
     				}
     				if(yes == 1)	break;
    			}
    			if(yes == 1)	word[j][i] = word[j+1][i]+1; 
    			else			word[j][i] = word[j+1][i];
   			}
			
//dp[i][j][k]表示从i到j位置进行k份所获得单词数。dp[i][j][k] = max(dp[i][l][k-1]+word[l+1][j]);
//*************************************************************************
/*算出 第i个: c0[i-1] 到 第j个:c0[j-1] 分st等份最多有单词dp[i][j][st]个*/
			for(st = 1; st <= k; st++)
				for(i = 0; i < len-st+1; i++)
					for(j = i+st-1; j < len; j++)
					{
						if(st == 1)
						{
							dp[i][j][st] = word[i][j]; 
							continue; 
						}
						for(max = 0, l = i+st-2; l < j; l++) 
						{
							x = dp[i][l][st-1]+word[l+1][j];
							if(x > max)	max = x;
						}
						dp[i][j][st] = max;
					}
//************************************************************************
  		printf("%d\n", dp[0][len-1][k]);
 	}
 	return 0;
}