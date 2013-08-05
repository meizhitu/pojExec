#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,k;
    string s;
    while(1)//cin遇到空格结束 
    {
        getline(cin,s);
        if(s=="END")
            break;
        priority_queue <int , vector <int>,greater<int> > q;
        sort(s.begin(),s.end());
        /*
        为什么要排序？
        因为下面用到的字符分类统计是和下一个比较，
        不相同就立马入队，若是相同的字符中间还有其他字符
        会被认作是不同字符，因为q.size()表示的是字符种类
        */
        int cnt=0;
        char ch = s[0];
        for(i=0;i<s.length();i++)//字符分类统计 
        if(s[i]==ch)
            cnt++;
        else
        {
            q.push(cnt);
            cnt=1;//因为执行到头了，i该自增了 
            ch=s[i];
        }
        q.push(cnt);//这句原来忘了
        int old_len = s.length()*8;
        int new_len = 0;
        //if(s.length()==1)
           // new_len = 1;
        if(q.size()==1)//上面的语句输入AAA时，只有一种字符，此时new_len=0 ，除数为0，竟然报wa，没报ＲＥ 
            new_len = q.top();      
        while(q.size()>1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a+b);
            new_len += a+b;
        }
        q.pop();
        cout<<old_len<<" "<<new_len<<" "<<fixed<<setprecision(1)<<(double)old_len/new_len<<endl;
        //printf("%d %d %.1f\n",old_len,new_len,old_len*1.0/new_len);
    }
     return 0;
}
