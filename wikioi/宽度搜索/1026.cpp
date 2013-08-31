/*
年轻的拉尔夫开玩笑地从一个小镇上偷走了一辆车，但他没想到的是那辆车属于警察局，并且车上装有用于发射车子移动路线的装置。
那个装置太旧了，以至于只能发射关于那辆车的移动路线的方向信息。
编写程序，通过使用一张小镇的地图帮助警察局找到那辆车。程序必须能表示出该车最终所有可能的位置。
小镇的地图是矩形的，上面的符号用来标明哪儿可以行车哪儿不行。“.”表示小镇上那块地方是可以行车的，而符号“X”表示此处不能行车。拉尔夫所开小车的初始位置用字符的“*”表示，且汽车能从初始位置通过。
汽车能向四个方向移动：向北(向上)，向南(向下)，向西(向左)，向东(向右)。
拉尔夫所开小车的行动路线是通过一组给定的方向来描述的。在每个给定的方向，拉尔夫驾驶小车通过小镇上一个或更多的可行车地点。

*/
//逃跑的拉尔夫 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
char map[60][60],c[60];
int visited[60][60];
typedef struct 
{
	int x,y;
}NODE;
queue <NODE> q;
void build(int x,int y)
{
	int i,j;
	for (i=0;i<=x+1;i++) map[i][0]=map[i][y+1]='X'; //外围全部表示不可达。
	for (i=0;i<=y+1;i++) map[0][i]=map[x+1][i]='X';
	for (i=1;i<=x;i++)
	{
		memset(c,0,sizeof(c));
		gets(c);
		for (j=1;j<=y;j++)
			map[i][j]=c[j-1];
	}
}
void print(int x,int y)
{
	int i,j;
	for (i=1;i<=x;i++)
	{
		for (j=1;j<=y;j++) printf("%c",map[i][j]);
		printf("\n");
	}
	return;
}
void op(int x,int y)
{
	int n,i,j,k,go[4][2]={-1,0,1,0,0,-1,0,1},a,b,dr;
	char name[10],sign[4][10]={"NORTH","SOUTH","WEST","EAST"};
	NODE tmp;
	scanf("%d",&n);
	b=1;
	for (j=1;j<=x;j++)
		for (k=1;k<=y;k++)
			if (map[j][k]=='*'){
				map[j][k]='.';
				tmp.x=j;
				tmp.y=k;
				break; //获取起始位置
			} 
	q.push(tmp);
	
	for (i=0;i<n;i++)
	{
		scanf("%s",name);
		a=b;
		b=0;
		for (j=0;j<3;j++)
			if (strcmp(name,sign[j])==0) break;
		dr=j;
		memset(visited,0,sizeof(visited)); //每次换一个方向的时候，均清空visited
		for (j=0;j<a;j++)
		{
			tmp=q.front();
			q.pop();
			printf("poped x,y=%d,%d\n",tmp.x,tmp.y);
			
			tmp.x+=go[dr][0];
			tmp.y+=go[dr][1];
			while (map[tmp.x][tmp.y]=='.'&&visited[tmp.x][tmp.y]==0)
			{
				q.push(tmp);
				printf("\tpushed x,y=%d,%d\n",tmp.x,tmp.y);
				visited[tmp.x][tmp.y]=1;
				tmp.x+=go[dr][0];
				tmp.y+=go[dr][1];
				++b;
			}
		}
	}
	while (!q.empty())
	{
		map[q.front().x][q.front().y]='*';
		q.pop();
	}
}
int main()
{
	int x,y;
	scanf("%d%d\n",&x,&y);
	build(x,y);
	op(x,y);
	print(x,y);
	return 0;
}