/*

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    while(scanf("%d %d",&n,&m)==2)
    {
        int cnt=0;
        for(i=0; i<n; i++)
        {
            bool gm=false;
            int val=0;
            for(j=0; j<m; j++)
            {
                cin>>val;
                if(!val)
                {
                    gm=true;
                }
            }
            if(!gm)
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}




/*
Sample Input
5 3
0 0 0
1 0 5
0 0 0
0 1 2
1 1 0
12 5
4 4 2 3 7
0 0 0 1 0
7 4 7 0 6
1 2 3 3 2
0 0 0 0 0
4 0 9 10 10
0 1 0 0 0
1 2 0 2 3
10 10 10 1 0
0 3 3 3 4
10 10 0 10 10
1 1 2 0 9

Sample Output
0
2
*/

