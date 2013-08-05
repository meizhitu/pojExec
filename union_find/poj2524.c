#include <stdio.h>
#include <stdlib.h>
#define MAXSTUDENT 50000
#define MAXPAIRS 50000*50000/2

int find(int x,int * f){
    if(x==f[x]) return x;
    int t = find(f[x],f);
    f[x] = t;
    return t;
}
int main(){
    int n,m;
    int cases = 1;
    while(scanf("%d%d",&n,&m) && !(n==0 && m ==0))
    {
	int a[m],b[m],i,f[n+1];
	for(i= 0 ;i< m;i++)
	    scanf("%d%d",&a[i],&b[i]);
	for(i = 1;i<=n;i++)
	    f[i] = i;
	for(i = 0 ;i<m;i++){
	    int roota = find(a[i],f);
	    int rootb = find(b[i],f);
	    if(roota == rootb)continue;
	    f[roota] = rootb;
	}
	int rootnodes = 0;
	for(i=1;i<=n;i++)
	    if(f[i] == i)
		rootnodes++;
	printf("Case %d: %d\n",cases++,rootnodes);
    }

    return 0;
}

