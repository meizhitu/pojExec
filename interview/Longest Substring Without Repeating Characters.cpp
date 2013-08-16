#include <iostream>
using namespace std;
//大小数据均过了。需要注意在发现重复数据后，start=map[s[i]-'a'],且 i=start.
int lengthOfLongestSubstring(string s) {
	int end = 0 ;
	int start = -1;
	int map[26];
	if(s.size()==0) return 0;
	memset(map,-1,sizeof(map));
	int maxV = INT_MIN;
	for(int i = 0 ; i<s.size();i++){
	//	cout <<"i "<< i<<endl;
		if(map[s[i]-'a']>=0)//出现重复的字符了
		{
			maxV = max(maxV,i-start-1);			
			start =  map[s[i]-'a'];
			i = start;
			memset(map,-1,sizeof(map));
		}
		else
			map[s[i]-'a'] = i;
	}
	int len = s.size();
	maxV = max(maxV,len-start-1);
	return maxV;
}
int main(){
	cout<<lengthOfLongestSubstring("abcabcbb")<<endl;

}