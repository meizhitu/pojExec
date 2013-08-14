#include <iostream>
#include <string>
using namespace std;
string minWindow(string S, string T) {
	if(T.size() == 0) return T;
	int inT[256];
	int inS[256];
	
	memset(inT,0,sizeof(inT));
	memset(inS,0,sizeof(inS));
	
	for(int i =  0 ;i < T.size();i++)
		inT[T[i]]++;
	int minLen = INT_MAX;
	int endPointer = 0;
	int beginPointer = 0 ;
	int countr = 0 ;//记录S中出现的T的字符个数
	string ret ;
	for(;endPointer < S.size();endPointer++){
		if(inT[S[endPointer]]==0) continue; //如果S中出现的字符在T中没有
		inS[S[endPointer]] ++;
		if(inS[S[endPointer]] <= inT[S[endPointer]])
			countr ++;
 		
		if(countr == T.size()){
			while(inT[S[beginPointer]] == 0 ||inS[S[beginPointer]] > inT[S[beginPointer]]){
				inS[S[beginPointer]]--;
				beginPointer ++;
			}
			int len = endPointer-beginPointer + 1;
			if(minLen > len){
				minLen = len;
				ret = S.substr(beginPointer,len);
			}
		}
	}
	return ret;
}
int main(){
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout <<minWindow(s,t)<<endl;
}