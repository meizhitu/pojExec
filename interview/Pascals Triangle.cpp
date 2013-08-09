#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > ret;
vector<int> rowS;	 
 /*
 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]
 */
	  ;
  vector<vector<int> > generate(int numRows) {
	  // Start typing your C/C++ solution below
	  // DO NOT write int main() function
	  numRows++;
	  ret.clear();
	  if(numRows == 0) return ret;
	  vector<int> row1;
	  row1.push_back(1);
	  ret.push_back(row1);
	  for(int i = 2;i<=numRows;i++){
		  vector<int> row;
		  for(int j = 1;j<=i;j++)
		  {
			  if(j==1) row.push_back(1);
			  else if(j == i) row.push_back(1);
			  else
				  row.push_back(ret[i-2][j-1]+ret[i-2][j-2]);
		  }
		  ret.push_back(row);
	  }
	  return ret;
  }
 /*
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 
 */
 vector<int> getRow(int rowIndex) {
	 if(rowIndex==0) return vector<int>();
	 int dp[2][rowIndex+1];
	 rowS.clear();
	// memset(dp,0,sizeof(dp));
	 dp[1][1] = 1;
	 for(int i=1;i<=rowIndex;i++)
		 for(int j = 1;j<=i;j++)
	 {
		 if(j==1) dp[i%2][j]=1;
		 else if(j==i)dp[i%2][j] =1;
		 else
		 	dp[i%2][j]=dp[(i-1)%2][j]+dp[(i-1)%2][j-1];
	 }
	 
	 for(int i=1;i<=rowIndex;i++)
	 {
		 rowS.push_back(dp[rowIndex%2][i]);
	 }
	 return rowS;
}
int main(){
	vector<vector<int> > n = generate(4);
	for(vector<vector<int> >::iterator it = n.begin();it!=n.end();it++)
	{
		for(vector<int>::iterator in = (*it).begin();in!=(*it).end();in++)
			cout <<*in<<" ";
		cout <<endl;
	}
	vector<int> v = getRow(5);
	for(int i = 0 ;i<v.size();i++)
		cout << v[i]<< " ";
	cout << endl;

}