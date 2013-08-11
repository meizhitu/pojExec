#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void compute(int n ,int idx,int num,vector<int> & ret){
	
	for(int i = idx;i>=1;i--)
	{
		num += pow(2,(n-i));
		ret.push_back(num);
		compute(n,i-1,num,ret);
		num -= pow(2,n-i); 
	}
}
vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	vector<int> ret;
	ret.push_back(0);
	
    if(n==0) return ret;
	compute(n,n,0,ret);
	return ret;
}
int main(){
	vector<int> ret = grayCode(2);
	for(int i = 0; i< ret.size();i++)
		cout<< ret[i] <<endl;

}