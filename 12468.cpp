/*
12468 - Zapping
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,first,second,ans;
    while(cin>>a>>b)
    {
        if(a==-1 && b==-1)break;
        first = abs(a-b);
        second = 100-first;
        ans = min(first,second);
        cout<<ans<<endl;
    }
    return 0;
}
/*
Sample Input
3 9
0 99
12 27
-1 -1

Sample Output
6
1
15
*/
