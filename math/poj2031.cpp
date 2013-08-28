//Memory Time 
//316K   16MS 
/*
大致题意：
就是给出三维坐标系上的一些球的球心坐标和其半径，搭建通路，使得他们能够相互连通。如果两个球有重叠的部分则算为已连通，无需再搭桥。求搭建通路的最小费用（费用就是边权，就是两个球面之间的距离）。
 
解题思路：
不要被三维吓到了，其实就是图论的最小生成树问题
球心坐标和半径是用来求 两点之间的边权 的，求出边权后，把球看做点，用邻接矩阵存储这个无向图，再求最小生成树，非常简单的水题。
 
把球A和球B看做无向图图的两个结点，那么
边权 = AB球面距离 = A球心到B球心的距离 –  A球半径 – B球半径
 
边权直接用上面的公式求，接下来再用Prim就能完美AC了
注意若边权<=0，说明两球接触，即已连通，此时边权为0
*/
#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
	
using namespace std;

const double inf=1000.0;
const double eps=1e-10;

typedef class
{
public:
	double x,y,z;
	double r;
}point;

/*Discuss Precision*/
double w[101][101];
int EPS(double k)
{
	if(fabs(k)<eps)
		return 0;
	return k>0?1:-1;
}
double prime(int m)
{
	int cur = 1;
	bool visit[101]={false};
    int index;
    double sum = 0;
	double dist[m+1];
	for(int i = 0;i<m;i++)
		dist[i] = inf;
    memset(visit, false, sizeof(visit));
    visit[cur] = true;
    for(int i = 1; i <= m; i ++)
        dist[i] = w[cur][i];    
    
    for(int i = 2; i <= m; i ++){
        double mincost = inf;
        for(int j = 1; j <= m; j ++){
            if(!visit[j] && dist[j] < mincost){
                mincost = dist[j];
                index = j;    
            }    
        }        
        visit[index] = true;
        sum += mincost;
        
        for(int j = 1; j <= m; j ++){
            if(!visit[j] && dist[j] > w[index][j]){
                dist[j] = w[index][j];
            }    
        }    
    } 
    return sum;    
}
/*AB之间的距离（权值）*/

double dist(point A,point B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z))-A.r-B.r;
}                        //AB距离是以球面为基准，而不是球心，因此要减去A球和B球的半径

int main(int i,int j)
{
	int n;
	freopen("2031.txt","r",stdin);
	while(cin>>n)
	{
		if(n<=0)
			break;

		/*Initial*/

		point* node=new point[n+1];

		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(i!=j)
					w[i][j]=inf;
				else
					w[i][j]=0;
			}

		/*Input*/

		for(i=1;i<=n;i++)
			cin>>node[i].x>>node[i].y>>node[i].z>>node[i].r;

		for(i=1;i<=n-1;i++)
			for(j=i+1;j<=n;j++)
		{
			double temp=dist(node[i],node[j]);
			if(EPS(temp)<=0)
				w[i][j]=w[j][i]=0;  //两个球接触(相交)，则距离(权值)为0
			else
				w[i][j]=w[j][i]=temp;
		}

		/*Prim Algorithm*/
		double sum_w = prime(n);
		cout<<fixed<<setprecision(3)<<sum_w<<endl;
		delete node;
	}
	return 0;
}
