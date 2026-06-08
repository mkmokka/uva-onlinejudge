/*
12582 - Wedding of Sultan
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        vector<vector<int>>ans(26);
        string s;
        stack<char>st;
        cin>>s;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                int u = st.top()-'A';
                int v = s[i]-'A';
                ans[u].push_back(v);
                ans[v].push_back(u);
                st.push(s[i]);
            }
        }
        cout<<"Case "<<(tc++)<<endl;
        for(int i=0; i<26; i++)
        {
            if(ans[i].size()>0)
            {
                printf("%c = %d\n",(i+65),ans[i].size());
            }
        }
    }
    return 0;
}

/*
Sample Input
2
AEFFGGEBDDCCBA
ZAABBZ

Sample Output
Case 1
A = 2
B = 3
C = 1
D = 1
E = 3
F = 1
G = 1
Case 2
A = 1
B = 1
Z = 2
*/
