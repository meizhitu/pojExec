#include <stdio.h>
#include <stdlib.h>
int ceiling(int a,int b){
    if(a%b == 0)return a/b;
    return a/b+1;
}
int main(){
    int n[6];
    while(scanf("%d%d%d%d%d%d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5])){
	int i,sum;
	int exist = 0;
	for(i = 0 ;i<6;i++) 
	    if(n[0]==0) exist ++;
	
	if(exist == 6){
	    break;
	};
	int result = 0,need,remain ;
	result += n[5];
	    if(n[4]>0){
		result +=n[4];
		n[0] -=n[4]*11;
		if(n[0] < 0) n[0] =0;
	    }
	    if(n[3]>0){
		
		result +=n[3]; 
		if(n[1] >= n[3]*5) n[1] -=n[3]*5; 
		else{
		    n[0] -=(n[3]*5-n[1])*4;
		    if(n[0]<0) n[0] = 0;
		    n[1] = 0;
		}
	    }
	    if(n[2]>0)
	    {
		need = ceiling(n[2],4);
		result += need;
		remain = 4*need-n[2];
		int avaiable = 0,avaiable2;
		switch(remain){
		    case 0:avaiable =0;break;
		    case 1:
			    avaiable =1;avaiable2=5;
			    break;
		    case 2:avaiable =3;avaiable2 = 6;break;
		    case 3:avaiable = 5;avaiable2 = 7;break;
		}
		if(avaiable > 0){
		if(n[1]>=avaiable) {
		    n[1] -= avaiable;
		    n[0] -= avaiable2;
		}
		    else{
			n[0] = n[0]-((avaiable-n[1])*4+avaiable2);
			n[1] = 0; 
		}
		   if(n[0]<0) n[0] =0;
		    if(n[1]<0) n[1]=0;
		}
	    }
	    if(n[1]>0)
	    {
		need = ceiling(n[1],9);
		result += need;
		remain = 9*need -n[1];
		if(n[0]>0) n[0]-= remain*4;
		if(n[0] <0) n[0] =0;	
		
	    }
	    if(n[0]>0)
		result += ceiling(n[0],36);
	printf("%d\n",result); 
    }
    return 0;
}
