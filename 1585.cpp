/*
1585 - Score
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ans=0;
        int prev=0;
        if(s[0]=='O')
        {
            prev=1;
            ans=1;
        }
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]=='O' && prev>0)
            {
                prev++;
                ans+=prev;
            }
            else if(s[i]=='O' && prev==0)
            {
                prev=1;
                ans++;

            }
            else if(s[i]=='X')
            {
                prev=0;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

/*
Sample Input
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

Sample Output
10
9
7
55
30
*/
