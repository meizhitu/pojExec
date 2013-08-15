#include <iostream>
using namespace std;
int reverse(int x) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(x==0) return 0;
	int isN = 1;
	if(x < 0){
		isN = -1;
		x = -x;
	} 
	int ret =  0;
	while(x){
		int digit = x%10;
		ret = 10*ret + digit;
		x = x/10;
	}
	return ret*isN;
}
int main(){
	cout <<reverse(-123)<<endl;

}