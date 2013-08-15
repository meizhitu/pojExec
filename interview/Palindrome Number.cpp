#include <iostream>
using namespace std;
bool isPalindrome(int x) {
	long long  num = x;
	long long base = 1;
	//负数不认为是回文串。
	if(num<0) return false;
	if(num==1) return true;
	while(base<num){
		base =base *10;
	}
	base /= 10;
	int ret = 0;
	while(num){
		int h = num/base;
		int l = num%10;
		if(h!=l) return false;
		num = num%base/10;
		base /=100;
	}
	return true;
}
int main(){
	cout << isPalindrome(-1)<<endl;

}