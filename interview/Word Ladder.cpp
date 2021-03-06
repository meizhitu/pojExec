#include <iostream>
#include <vector>
#include <set>
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/
using namespace std;
int minV;
//bfs，网上找的，懒得搞了
int ladderLength(string start, string end, unordered_set<string> &dict)
{
	if (start.size() != end.size())
		return 0;
	if (start.empty() || end.empty())
		return 1;
	if (dict.size() == 0)
		return 0;
	int distance = 1; //!!!
	queue<string> queToPush, queToPop;
	queToPop.push(start);
	while (dict.size() > 0 && !queToPop.empty())
	{
		//对BFS每一层的每一个string，分别替换各个位的字符。
		while (!queToPop.empty())
		{
			string str(queToPop.front()); //!!!how to initialize the str
			queToPop.pop(); //弹出该层的字符串
			for (int i = 0; i < str.size(); i++)
			{
				for (char j = 'a'; j <= 'z'; j++)
				{
					if (j == str[i])
						continue;
					char temp = str[i];
					str[i] = j;
					if (str == end)
						return distance + 1; //found it
					if (dict.count(str) > 0) //exists in dict
					{
						queToPush.push(str); //find all the element that is one edit away
						dict.erase(str); //delete corresponding element in dict in case of loop
					}
					str[i] = temp; //
				}
			}
		}
		swap(queToPush, queToPop); 
		distance++; //到下一层
	} //end while
	return 0; //all the dict words are used up and we do not find dest word
} //end function
	

//dfs 超时。
void compute(string start,string end, int step,set<string> &dict){
	if(start == end){
		minV = min(minV,step);
		return ;
	}
	for(int i = 0 ; i< start.size();i++){
		string tmp = start;
		for(int j = 0;j<26;j++){
			tmp[i] = 'a'+j;
			if(tmp == end)
				minV = min(minV,step+1);
			else{
				//tmp在dict里
				if(dict.find(tmp)!=dict.end()){
					//cout <<tmp<<endl;
					dict.erase(tmp);
					compute(tmp,end,step+1,dict);
					dict.insert(tmp);
				}
			}
			
		}
	}
}
int ladderLength(string start, string end, set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(start.size()==0) return 0;
	minV = INT_MAX;
	compute(start,end,0,dict);
	if(minV == INT_MAX)return 0;
	return minV+1;
}
int main(){
	string start = "hit";
	string end = "cog";
	set<string>dict ;
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	dict.insert("lot");
	dict.insert("log");
	
	int ret = ladderLength(start,end,dict);
	cout <<ret<<endl;

}