#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100000
 
typedef struct{
        int weight;
        int parent, lc, rc;
}HTNode;
HTNode ht[N];
char str[N];
int sum1,sum, n, num[27], i,j, min, tmp1,tmp2;
double sum2;
void sum_weight(HTNode hn, int i)
{
   if(hn.lc == 0 && hn.rc == 0)
      sum += hn.weight*i;
   else
   {
       sum_weight(ht[hn.lc], i+1);
       sum_weight(ht[hn.rc], i+1);
   }
}
main()
{
   scanf("%s", str);
   while(strcmp(str, "END") != 0)
   {
      n = strlen(str);
      sum1 = n*8;
      for(i=0;i<=26;i++)
         num[i] = 0;
      for(i=0;i<n;i++)
      {
         if(str[i] == '_')
            num[26]++;
         else
            num[str[i]-'A']++;
      }
      j=0;
      for(i=0;i<27;i++)
      {
         if(num[i]!=0)
         {
            ht[j].weight = num[i];
            ht[j].parent = 0;
            ht[j].lc = 0;
            ht[j].rc = 0;
            j++;
         }
      }
      n = j; 
      //create hurff tree
      for(i=n; i<2*n-1; i++)
      {
         //select less two nodes
         min = 10000;
         for(j=0;j<i;j++)
         {
            if(ht[j].parent == 0 && ht[j].weight < min)
            {
               tmp1 = j;
               min = ht[j].weight;
            }
         }
         min = 10000;
         for(j=0;j<i;j++)
         {
            if(ht[j].parent == 0 && ht[j].weight < min && j!= tmp1)
            {
               tmp2 = j;
               min = ht[j].weight;
            }
         }
         //更改节点信息:
         ht[tmp1].parent = i;
         ht[tmp2].parent = i;
         ht[i].lc = tmp1;
         ht[i].rc = tmp2;
         ht[i].weight = ht[tmp1].weight + ht[tmp2].weight;
         ht[i].parent = 0;
      }
      sum = 0;
      //calculate the sum of weight, root  is in 2*n-2
      if(n == 1)
         sum = strlen(str);
      else
         sum_weight(ht[2*n-2],0);
      sum2 = (double)((double)sum1/(double)sum);
      printf("%d %d %.1f\n",sum1, sum,sum2);
     
      scanf("%s", str);
   }
   //system("pause");
   return 0;
}
