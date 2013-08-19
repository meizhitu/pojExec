//Palindrome Partitioning II
/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
	*/
//才意识到这个动态规划
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
//pal[i][j]记录了从i位置开始，到位置j结束的字符串是否为回文串。
void checkPal(string s, vector<vector<bool> >* pal)
{
	int len = s.size(), interval = 0;
	//interval必须在外围循环
	for (; interval < len; interval++)
	{
		for (int i = 0; i < len && (i + interval) < len; i++)
		{
			if (interval <= 0)
			{
				(*pal)[i][i+interval] = true;
			}
			else
			{
				if ((s[i] == s[i+interval]) &&
					(interval == 1 || (*pal)[i+1][i+interval-1]))
						(*pal)[i][i+interval] = true;
			}
		}
	}
}
 
int minCut(string s)
{
	int len = s.size();
	// special case for short strings
	if (len <= 1) return 0;
 
	vector<vector<bool> > pal;
	for (int i = 0; i < len; i++)
	{
		//pal中放入长度为len的false。
		pal.push_back(vector<bool>(len, false));
	}
	checkPal(s, &pal);
 
	int cuts[len];//cuts[i]表示前i个字符串中，需要的min剪切次数
	cuts[0] = 0;
 
	int min_tmp = INT_MAX; // temporary min
	for (int i = 1; i < len; i++)
	{
		min_tmp = INT_MAX;
		//循环判断i-1之前的回文串需要的切割次数。
		for (int j = 0; j <= i; j++)
		{
			if (pal[j][i])
			{
				if (j == 0)
				{
					min_tmp = 0; //从j到i是回文，则不需要切
					break;
				}
				if (cuts[j-1] + 1 < min_tmp) //一个回文串是前j个字符，第j到i构成回文，从j-1到j中切一刀。
				{
					min_tmp = cuts[j-1] + 1;
				}
			}
		}
		cuts[i] = min_tmp;
	}
	return cuts[len-1];
}
int main(){
	string s="ababbbabbaba";
	
	printf("%d\n",minCut(s));
}
