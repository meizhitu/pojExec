/*
已知有两个字串 A$, B$ 及一组字串变换的规则（至多6个规则）:
　　　　　A1$ -> B1$
　　　　　A2$ -> B2$
　　规则的含义为：在 A＄中的子串 A1$ 可以变换为 B1$、A2$ 可以变换为 B2$ …。
　　　　例如：A$＝'abcd'　B$＝'xyz'
　　变换规则为：
　　　　‘abc’->‘xu’　‘ud’->‘y’　‘y’->‘yz’

　　则此时，A$ 可以经过一系列的变换变为 B$，其变换的过程为：
　　　‘abcd’->‘xud’->‘xy’->‘xyz’

　　共进行了三次变换，使得 A$ 变换为B$。
	若在 10 步（包含 10步）以内能将 A$ 变换为 B$ ，则输出最少的变换步数；否则输出"NO ANSWER!"

*/
#include <stdio.h>
#include <string.h>
		struct node
{
	char s[30];
	int dep;  //变换次数 
} list1[5010], list2[5010];
char a[7][30], b[7][30];
int n;
void BFS()
{
	int head1, tail1, head2, tail2, k;
	head1 = tail1 = head2 = tail2 = 1;
	while(head1 <= tail1 && head2 <= tail2)
	{
		if(list1[head1].dep + list2[head2].dep > 10) 
		{
			printf("NO ANSWER!\n");
			return ;
		}
		for(int i = 0;i < strlen(list1[head1].s); i++)
		for(int j = 1; j <= n; j++){
			if(strncmp(list1[head1].s + i, a[j], strlen(a[j])) == 0)//如果有匹配的规则 
			{
				tail1++; //移动尾指针，存储变换后的字符串，以下三个for循环为变换过程 
				for(k = 0; k < i; k++) 
					list1[tail1].s[k] = list1[head1].s[k];
				for(int l = 0; l < strlen(b[j]); l++, k++) 
					list1[tail1].s[k] = b[j][l];
				for(int l = i + strlen(a[j]); l <= strlen(list1[head1].s); l++, k++)
					list1[tail1].s[k] = list1[head1].s[l];
				list1[tail1].s[k] = '\0'; //为变换结束后的字符串加结束符 
				list1[tail1].dep = list1[head1].dep+1;
				for (k = 1; k <= tail1; k++)
				{
					if (strcmp(list1[tail1].s, list2[k].s) == 0)//判断当前状态是否与逆向搜索交汇 
					{
						printf("%d\n", list1[tail1].dep + list2[k].dep);
						return ;
					}
				}
			}
		}
				
		for (int i = 0; i < strlen(list2[head2].s); i++) //逆向搜索同上 
		for (int j = 1; j <= n; j++){
			if(strncmp(list2[head2].s + i, b[j], strlen(b[j])) == 0)
			{
				tail2++;
				for(k = 0; k < i; k++) 
					list2[tail2].s[k] = list2[head2].s[k];
				for(int l = 0; l < strlen(a[j]); l++, k++) 
					list2[tail2].s[k] = a[j][l];
				for(int l = i + strlen(b[j]); l <= strlen(list2[head2].s); l++, k++)
					list2[tail2].s[k] = list2[head2].s[l];
				list2[tail2].s[k] = '\0';
				list2[tail2].dep = list2[head2].dep + 1;
				for (k = 1;k <= tail1; k++){
					if (strcmp(list1[k].s, list2[tail2].s) == 0)
					{
						printf("%d\n",list1[k].dep + list2[tail2].dep);
						return ;
					}
				}
					
			}
		}
				
		head1++; 
		head2++;
	}
	printf("NO ANSWER!\n");
}
int main()
{
	scanf("%s%s",list1[1].s, list2[1].s);
	n = 1;
	while (scanf("%s%s",a[n],b[n]) != EOF) 
		n++;
	n--;
	list1[1].dep = list2[1].dep = 0;
	BFS();
	return 0;
} 