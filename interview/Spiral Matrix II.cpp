#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > retV;
void compute(int start,int idxI,int idxJ,int lastI,int lastJ){
	if(idxI>lastI ||idxJ > lastJ)
		return ;
	if(idxI==lastI){
		for(int i =idxJ;i<=lastJ;i++)
			retV[idxI][i] = start++;
		return ;
	}
	if(idxJ==lastJ){
		for(int i = idxI;i<=lastI;i++)
			retV[i][lastJ] = start++;
		return ;
	}
	int i = idxI ,j = idxJ;
	while(j<=lastJ){
	//	ret.push_back(matrix[i][j]);
		retV[i][j] = start++;
		j++;
	}
	i++;
	j--;
	while(i<=lastI){
		retV[i][j] = start++;
		i++;
	}
	j--;
	i--;
	while(j>=idxJ)
	{
		retV[i][j] = start++;
		j--;
	}
	j++;
	i--;
	while(i>idxI){
		retV[i][j] = start++;
		i--;
	}
	compute(start,idxI+1,idxJ+1,lastI-1,lastJ-1);
}
vector<vector<int> > generateMatrix(int n){
	retV.clear();
	if(n==0) return retV;
	for(int i = 0;i<n;i++)
		retV.push_back(vector<int>(n,0));
	compute(1,0,0,n-1,n-1);
	return retV;
}
int main(){
	int len = 3;
	vector<vector<int> > ret =generateMatrix(len);
	
	for(int i = 0 ;i<len;i++){
		for(int j = 0; j<len;j++)
			cout <<ret[i][j]<<" ";
	cout << endl;
	}
		
}