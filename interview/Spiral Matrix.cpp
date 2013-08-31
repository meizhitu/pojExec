#include <iostream>
#include <vector>
using namespace std;
void compute(vector<vector<int> > matrix,vector<int> & ret,int idxI,int idxJ,int lastI,int lastJ){

	int m =matrix.size();
	int n = matrix[0].size();
	if(idxI>lastI ||idxJ > lastJ)
		return ;
	//单独处理最后一行
	if(idxI==lastI){
		for(int i =idxJ;i<=lastJ;i++)
			ret.push_back(matrix[idxI][i]);
		return ;
	}
	if(idxJ==lastJ){
		for(int i = idxI;i<=lastI;i++)
			ret.push_back(matrix[i][lastJ]);
		return ;
	}
	int i = idxI ,j = idxJ;
	while(j<=lastJ){
		ret.push_back(matrix[i][j]);
		j++;
	}
	i++;
	j--;
	while(i<=lastI){
		ret.push_back(matrix[i][j]);
		i++;
	}
	j--;
	i--;
	while(j>=idxJ)
	{
		ret.push_back(matrix[i][j]);
		j--;
	}
	j++;
	i--;
	while(i>idxI){
		ret.push_back(matrix[i][j]);
		i--;
	}
	compute(matrix,ret,idxI+1,idxJ+1,lastI-1,lastJ-1);
}
vector<int> spiralOrder(vector<vector<int> > &matrix) {
	int m =matrix.size();
	if(m==0) return vector<int>();
	int n =matrix[0].size();
	
	vector<int> ret;
	compute(matrix,ret,0,0,m-1,n-1);
	return ret;
}
int main(){
	int len = 4;
	int n[3][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
	};
	vector<vector<int> > matrix;
	for(int i = 0; i < 3;i++){
		vector<int> inn;
		for(int j = 0 ;j<4;j++)
			inn.push_back(n[i][j]);
		matrix.push_back(inn);
	}
	vector<int> ret = spiralOrder(matrix);
	for(int i = 0 ; i< ret.size();i++)
		cout <<ret[i]<<" ";
	cout << endl;
}