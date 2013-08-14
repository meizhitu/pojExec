//1.先从右往左，第一个违反增序的数字，称为分割数字 2 1 3 4 则其中第一个符合要求的数字是3
//2.从右往左，第一个大于分割数字的数字，上述的4符合，称为变换数字，swap分割数字和变换数字
//3.从分割数字的idx开始，reverse其后的数字。
#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &a,int i,int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
void nextPermutation(vector<int> &num) {
	if(num.size()<2) return ;
	int i ;
	for( i = num.size()-2;i>=0;i--)
		if(num[i]<num[i+1])
			break;
	int partionIdx = i;
	cout <<i<<" "<<num[i]<<endl;
	if(i==-1){
		reverse(num.begin(),num.end());
		return;
	}
	for( i = num.size()-1;i>=0;i--)
		if(num[i]>num[partionIdx]){
			swap(num,i,partionIdx);
			break;
		}
	vector<int>::iterator it = num.begin();
	for(int i = 0 ; i<=partionIdx;i++)
		it++;
	reverse(it,num.end());
}
int main(){

	vector<int> num;
	num.push_back(1);
	num.push_back(4);
	num.push_back(3);
	num.push_back(2);
	//reverse(num.begin(),num.end());
	nextPermutation(num);
	for(int i = 0 ;i<num.size();i++)
		cout << num[i]<<" ";
	cout <<endl;	
}