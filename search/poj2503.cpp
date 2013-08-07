#include <cstdio>
#include <cstring>
/*
之前写的树总是wa，网上找了用数组实现的trie，真无语。
*/
struct Node
{
    int next[26];
    char str[12];
} dic[200000];

int indexI = 0;

void insert(char* s,char* t)
{
    int len=strlen(s);
    int now=0;
    for(int i=0;i<len;i++)
    {
        int idx=s[i]-'a';
        if(dic[now].next[idx]==0)
            dic[now].next[idx]=++indexI;
        now=dic[now].next[idx];
    }
    memcpy(dic[now].str,t,strlen(t));
}

void query(char* s)
{
    int len=strlen(s);
    int now=0;
    for(int i=0;i<len;i++)
    {
        int idx=s[i]-'a';
        if(dic[now].next[idx]==0)
        {
            printf("eh\n");
            return;
        }
        now=dic[now].next[idx];
    }
    printf("%s\n",dic[now].str);
}

int main()
{
 //   freopen("in.txt","r",stdin);
    char str[30];
    while(gets(str),str[0])
    {
        int pos=0;
        while(str[pos++]!=' ');
        str[pos-1]=0;
        insert(str+pos,str);
    }
    while(gets(str))
        query(str);
}
