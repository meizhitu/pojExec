/*
Given a collection of intervals, merge all overlapping intervals.

	For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
	*/
#include <iostream>
#include <vector>
	using namespace std;
typedef struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
}Interval;

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<Interval> ret ; 
	ret.push_back(newInterval);
	for(int i = 0 ; i< intervals.size();i++){
		Interval newI = ret.back();
		ret.pop_back();
		if(intervals[i].end < newI.start){
			ret.push_back(intervals[i]);
			ret.push_back(newI);
		}
		else if(intervals[i].start > newI.end){
			ret.push_back(newI);
			ret.push_back(intervals[i]);
		}
		else{
			int s = min(newI.start,intervals[i].start);
			int e = max(newI.end,intervals[i].end);
			newI.start = s;
			newI.end = e;
			ret.push_back(newI);
		}
	}
	return ret;
}
vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> ret ; 
	for(int i = 0 ; i< intervals.size();i++){
		ret = insert(ret,intervals[i]);
	}
	return ret;
}
int main(){
	vector<Interval> intervals;
	Interval *i1 = new Interval(1,4);
	Interval *i2 = new Interval(1,5);
	intervals.push_back(*i1);
	intervals.push_back(*i2);
	
	vector<Interval> inns = merge(intervals);
	for(int i = 0;i<inns.size();i++)
		cout <<inns[i].start<<" "<<inns[i].end<<endl;
}