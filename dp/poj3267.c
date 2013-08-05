#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int  c[600][50][302];
int map(char word[],char *chars,int start,int len){
	int word_len = strlen(word);
	if(word[0] != chars[start]) return len+1;
	int j = start,i = 0;
	while(i<word_len && j < len){
		if(chars[j] == word[i]){
			i++;j++;
		}
		else
			j++;
	}
	if(i == word_len && j <=len) return j;
	return len+1;
}
int main(){
	int w,l;
	while(scanf("%d%d",&w,&l)!=EOF){
		char chars[l];
		int i,j;
		char words[600][100];
		memset(c,0,sizeof(c));
		int path[600][2];
		char garbage;
		int c_brief[600];
		memset(path,0,sizeof(path));
		scanf("%c",&garbage);
		for(i = 0 ;i < l ;i++)
			scanf("%c",&chars[i]);
		for(i = 0; i < w;i++)
			scanf("%s",words[i]);
		int m = 0;
		int dp[l+1];
		dp[l] =0;
		for(i = l-1;i>=0;i--)
		{
			dp[i] = dp[i+1] +1;
			for(m = 0 ; m<w;m++)
			{ 
				int loc = map(words[m],chars,i,l);
				if(loc <= l)
				{
					int mapped = dp[loc]+loc-i-strlen(words[m]);
					dp[i] = dp[i]<mapped?dp[i]:mapped;
				}
			}

		}
		printf("%d\n",dp[0]);
	}
	return 0;
}
