/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num) {
	vector<vector<int> > ret;
	if(num.size()==0)return ret;
	sort(num.begin(),num.end());
	int len = num.size();
	for(int i = 0 ; i<len-2;i++ ){
		while(i-1>=0 && num[i]==num[i-1]) i++;
		int sum = 0 - num[i];
		int m = i+1;
		int n = len-1;
		while(m<n){
			if(num[m]+num[n] == sum){
				vector<int> p;
				p.push_back(num[i]);
				p.push_back(num[m]);
				p.push_back(num[n]);
				ret.push_back(p);
				m++;
				while(m<len && num[m]==num[m-1])m++;
			}
			else if(num[m]+num[n] > sum){
				n--;
			}
			else m++;
		}
	}
	return ret;
      }