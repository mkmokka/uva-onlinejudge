/*
12503 - Robot Instructions
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    int z,x,ar[110],i,j;
    cin>>test;
    while(test--)
    {
        x = 0;
        cin>>z;
        string name,game;
        int ans;
        for(i=0; i<z; i++)
        {
            cin>>name;
            if(name[0]=='L')
            {
                ar[i]=-1;
                x--;
            }
            else if(name[0]=='R')
            {
                ar[i]=+1;
                x++;
            }
            else
            {
                cin>>game>>ans;
                ar[i]=ar[ans-1];
                x+=ar[i];

            }
        }
        cout<<x<<endl;
        name.erase(name.begin(), name.end());
    }
    return 0;
}
/*
Sample Input
2
3
LEFT
RIGHT
SAME AS 2
5
LEFT
SAME AS 1
SAME AS 2
SAME AS 1
SAME AS 4

Sample Output
1
-5
*/
