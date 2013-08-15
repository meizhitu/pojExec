#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	vector<int> ret ;
	if(numbers.size()==0) return ret;
	map<int,vector<int> > loc;
	for(int i = 0;i<numbers.size();i++)
		loc[numbers[i]].push_back(i);
	sort(numbers.begin(),numbers.end());
	int i = 0 ;
	int j = numbers.size()-1;
	while(i<j){
	//	cout <<i<<" "<<j<<endl;
		if(numbers[i]+numbers[j]==target){
			int loc1,loc2;
			if(numbers[i]!=numbers[j]){
				 loc1 = loc[numbers[i]][0];
				 loc2 = loc[numbers[j]][0];
				
			}
			else{
			 loc1 = loc[numbers[i]][0];
			 loc2 = loc[numbers[j]][1];
			
			}
			int minL = min(loc1,loc2);
			int maxL = max(loc1,loc2);
			ret.push_back(minL+1);
			ret.push_back(maxL+1);
			return ret;
		}
		else if(numbers[i]+numbers[j] < target)
			i++;
		else j--;
	}
	return ret;
}
int main(){
	vector<int> ns;
	ns.push_back(1);
	ns.push_back(3);
	ns.push_back(5);
	twoSum(ns,4);
	
}