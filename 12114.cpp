/*
12114 - Bachelor Arithmetic
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll b,s,k=0;
    while(cin>>b>>s)
    {
        if(b==0 && s==0)break;
        else if(b==0 || b==1)
        {
            cout<<"Case "<<++k<<": :-\\"<<endl;
        }
        else if(b<=s)
        {
            cout<<"Case "<<++k<<": :-|"<<endl;
        }
        else if(b>s)
        {
            cout<<"Case "<<++k<<": :-("<<endl;
        }

    }
    return 0;
}

/*
Sample Input
10 10
2 3
3 2
0 0

Sample Output
Case 1: :-|
Case 2: :-|
Case 3: :-(
*/

