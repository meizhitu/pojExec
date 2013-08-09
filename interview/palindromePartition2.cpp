//Palindrome Partitioning II
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
		for (int j = 0; j <= i; j++)
		{
			if (pal[j][i])
			{
				if (j == 0)
				{
					min_tmp = 0;
					break;
				}
				if (cuts[j-1] + 1 < min_tmp)
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
