/*
总感觉不是dp，是个递归，不过是个好题。解题报告http://fghtech.blogbus.com/logs/57892020.html
*/
#pragma warning(disable: 4786)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string DFS(string str)
{
	if(str == "01")
		return str;
	else
	{
		cout<<"str"<<str<<endl;
		
		str = str.substr(1, str.length()-2);
	//	cout<<"after strip:str"<<str<<endl;
		int i, cnt = 0, start, len = str.length();
		vector< string > sv;
		for(start=i=0; i<len; i++)
		{
			cnt += str[i] == '0' ? 1 : -1;
			if(!cnt)
			{
				string tmp =DFS(str.substr(start, i-start+1));
				sv.push_back(tmp);
				start = i + 1;
			}
		}
		sort(sv.begin(), sv.end());

		string str = "0";
		len = sv.size();
		for(i=0; i<len; i++)
		{
			str += sv[i];
		}
		return str + "1";
	}
}

void Compute()
{
	char str[3001];
	string mintree[2];
	gets(str);
	mintree[0] = "0" + string(str) + "1";
	mintree[0] = DFS(mintree[0]);
	cout<<mintree[0]<<endl;
	gets(str);
	mintree[1] = "0" + string(str) + "1";
	mintree[1] = DFS(mintree[1]);
	if(mintree[0] == mintree[1])
		printf("same\n");
	else
		printf("different\n");
}

int main()
{
	int cases;
	freopen("1635.txt","r",stdin);
	scanf("%d\n", &cases);
	while(cases--)
	{
		Compute();
	}
	return 0;
}