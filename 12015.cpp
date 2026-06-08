/*
12015 - Google is Feeling Lucky
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1[1500];
    int ar[1000];

    memset(ar,0,sizeof(ar));
    int test;
    cin>>test;
    for(int k=1; k<=test; k++)
    {


        for(int j=1; j<=10; j++)
        {
            cin>>s1[j]>>ar[j];
        }

        int max = ar[0];
        for(int i=0; i<11; i++)
        {
            if(max<ar[i])
            {
                max = ar[i];
            }
        }
        printf("Case #%d:\n",k);
        for(int i=1; i<=10; i++)
        {
            if(max == ar[i])
                cout<<s1[i]<<endl;
        }

    }
    return 0;
}
/*
Sample Input
2
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 10
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
www.university.edu.cn 9
acm.university.edu.cn 10
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 11
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
acm.university.edu.cn 9
acm.university.edu.cn 10

Sample Output
Case #1:
www.alibaba.com
www.bad.com
acm.university.edu.cn
Case #2:
www.alibaba.com
*/
