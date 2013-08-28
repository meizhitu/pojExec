#include <iostream>
#include <string>
#include <map>

using namespace std;
string intToRoman(int num) {
	if(num == 0) return "";
	int base = 1000;
	string ret ; 
	char chars[] = {'I','V','X','L','C','D','M'};
	for(int i = 6;i>=0;i-=2){//注意此处
		int digit = num/base;
		num = num%base;
		base /= 10;
		if(digit==0){
			continue;
		}
		//cout <<digit<<endl;
		if(digit==1)
		{
			ret.append(1,chars[i]);
		}
		else if(digit<=3){
			ret.append(digit,chars[i]);
		}
		else if(digit==4){
			ret.append(1,chars[i]);
			ret.append(1,chars[i+1]);
		}
		else if(digit==5)
		{
			ret.append(1,chars[i+1]);
		}
		else if(digit <=8){
			ret.append(1,chars[i+1]);
			ret.append(digit-5,chars[i]);
		}
		else if(digit == 9){
			ret.append(1,chars[i]);
			ret.append(1,chars[i+2]);
		}
	}
	return ret;
}
int main(){
	
	cout <<intToRoman(1)<<endl;
}