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
//一个DFS
void solve(vector<vector<char> > &board) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int N = board.size();
	if (N == 0) return;
	int M = board[0].size();
	if (M == 0) return;
	vector<vector<bool> > visited(N, vector<bool>(M, false));
       
	int dx[4] = {-1, 1, 0, 0};//上下左右四个方向
	int dy[4] = {0, 0, -1, 1};
       
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
	{
		//以(i,j)为起点进行BFS
		if (!visited[i][j] && board[i][j] == 'O')
		{
			vector<int> queX, queY;//遍历路径
			queX.push_back(i);
			queY.push_back(j);
			
			int head = 0;
			//是否在边界以内:如果在边界上，则不需要visitedX
			bool needMarkX = !(i == 0 || j == 0 || i == N - 1 || j == M - 1) ;
            visited[i][j] = true;
			//即使出发点在边界上，也需要进行BFS，找出所有不需要markX的节点。
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
						if (!visited[nextX][nextY] && board[nextX][nextY] == 'O')
						{
							//(i,j)可以到达的坐标，如果存在一个点在边界上，
							//则修改needMarkX为false，表示queX,queY中所有坐标均不需要mark
							queX.push_back(nextX);
							queY.push_back(nextY);
							visited[nextX][nextY] = true;
							if (nextX == 0 || nextY == 0 || nextX == N - 1 || nextY == M - 1) //遍历到了边界
								needMarkX = false;
						}
					}
				}
			}
			if (needMarkX)
			{
				//将所能到达的路径均mark X
				for (int i = 0; i < queX.size(); i++)
					board[queX[i]][queY[i]] = 'X';
			}
		}
	}
}
int main(){
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