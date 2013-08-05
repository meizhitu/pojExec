/*
百度的一道面试题，注意题目的意思：是s1和s2进行混合而得到s3。
所以s3的长度不会超过strlen(s1)+strlen(s2)
ok[i][j]为真时表示str1的前i个字符可以和str2的前j个字符 
			组成str3的前i+j个字符。为假时 表示不能。 
				***********************/ 
#include <stdio.h>  
#include <string.h>  
  
int main()  
{  
	int  i, j, k, t;  
	int  L1, L2, ok[202][202];  
	char str1[201], str2[201], str3[402];  
	 
	scanf("%d", &t);  
	for (i=1; i<=t; i++)  
	{  
		scanf("%s %s %s", str1, str2, str3);  
		memset(ok, 0, sizeof(ok));  
		L1 = strlen(str1);  
		L2 = strlen(str2);  
  
		ok[0][0] = 1;  
		for (j=1; j<=L1; j++)  
		{  
			if (ok[j-1][0] == 1 && str1[j-1] == str3[j-1])  
				ok[j][0] = 1;  
			else  
				break;  
		}  
		for (j=1; j<=L2; j++)  
		{  
			if (ok[0][j-1] == 1 && str2[j-1] == str3[j-1])  
				ok[0][j] = 1;  
			else  
				break;  
		}  
		for (j=1; j<=L1; j++)  
		{  
			for (k=1; k<=L2; k++)  
			{  
				if (ok[j-1][k]==1 && str1[j-1]==str3[j+k-1] || ok[j][k-1]==1 && str2[k-1]==str3[j+k-1])  
					ok[j][k] = 1;  
			}  
		}  
		if (ok[L1][L2] == 1)  
			printf("Data set %d: yes\n", i);  
		else  
			printf("Data set %d: no\n", i);  
	}  
}  