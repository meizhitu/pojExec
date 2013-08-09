/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

	A region is captured by flipping all 'O's into 'X's in that surrounded region .

		For example,

X X X X
	X O O X
		X X O X
			X O X X
				After running your function, the board should be:

X X X X
	X X X X
		X X X X
			X O X X
				*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//
//ooox
//xxxx

void solve(vector<vector<char> > &board) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int N = board.size();
	if (N == 0) return;
	int M = board[0].size();
	if (M == 0) return;
	vector<vector<bool> > mark(N, vector<bool>(M, false));
       
	int dx[4] = {-1, 1, 0, 0};//上下左右四个方向
	int dy[4] = {0, 0, -1, 1};
       
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
	{
		
		if (!mark[i][j] && board[i][j] == 'O')
		{
			vector<int> queX, queY;//遍历路径
			queX.push_back(i);
			queY.push_back(j);
			
			int head = 0;
			bool result = !(i == 0 || j == 0 || i == N - 1 || j == M - 1) ;//是否在边界以内
            mark[i][j] = true;
			while (head < queX.size())
			{
				int nx = queX[head];
				int ny = queY[head];
				head++;
				
				for (int i = 0; i < 4; i++)
				{
					int nextX = nx + dx[i];
					int nextY = ny + dy[i];
					if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
					{
						if (!mark[nextX][nextY] && board[nextX][nextY] == 'O')
						{
							queX.push_back(nextX);
							queY.push_back(nextY);
							mark[nextX][nextY] = true;
							if (nextX == 0 || nextY == 0 || nextX == N - 1 || nextY == M - 1) //遍历到了边界
								result = false;
						}
					}
				}
			}
			if (result)
			{
				for (int i = 0; i < queX.size(); i++)
					board[queX[i]][queY[i]] = 'X';
			}
		}
	}
}
int main(){
	//freopen("a.txt","r",stdin);
	vector<vector<char> > board;
	for(int i = 0 ; i< 4;i++)
	{
		vector<char> inner;
		for(int j = 0 ;j<4;j++){
			char c;
			scanf("%c",&c);
			inner.push_back(c);
		}
		board.push_back(inner);
	}
	for(int i = 0 ;i<board.size();i++){
		for(int j = 0;j<board[0].size();j++)
			cout<<board[i][j];
		cout<<endl;
	}
	solve(board);
	cout<<endl;
	for(int i = 0 ;i<board.size();i++){
		for(int j = 0;j<board[0].size();j++)
			cout<<board[i][j];
		cout<<endl;
	}
	
}