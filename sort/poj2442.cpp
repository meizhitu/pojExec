//优先队列底层使用的是堆，这道题wa出翔来了，把别人的heap改成了堆a了。真无语。

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
bool cmp(int a,int b)
{
	return a < b;
}
int main()
{
	int T,m,n,i,j,k,temp,ans=0;
	vector<int>data1,data2;
	priority_queue <int,vector<int>,less<int> > dataQ;
	cin>>T;
	while(T--)
	{
		data1.clear();
		cin>>m>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			data1.push_back(temp);
		}
		for(i=1;i<m;i++)
		{
			sort(data1.begin(),data1.end(),cmp);
			data2.clear();
			for(j=0;j<n;j++)
			{
				cin>>temp;
				data2.push_back(temp);
			}
			sort(data2.begin(),data2.end(),cmp);
			for(j=0;j<n;j++)
				dataQ.push(data1[j]+data2[0]);
			for(j=1;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					temp=data1[k]+data2[j];
					if(temp>=dataQ.top())
						break;
					dataQ.pop();
					dataQ.push(data1[k]+data2[j]);
				}    
			}
			data1.clear();
			while(!dataQ.empty()){
				data1.push_back(dataQ.top());
				dataQ.pop();
			}				
		}
		sort(data1.begin(),data1.end(),cmp);
		for(i=0;i<n-1;i++)
			printf("%d ",data1[i]);
		printf("%d\n",data1[n-1]);
	}return 0;
}
