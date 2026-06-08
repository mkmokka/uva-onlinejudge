/*
824 - Coast Tracker
*/

#include<bits/stdc++.h>
using namespace std;

bool found(int new_direction, char pos[][3])
{
    switch(new_direction)
    {
    case 0:
        return pos[0][1]=='1';
    case 1:
        return pos[0][0]=='1';
    case 2:
        return pos[1][0]=='1';
    case 3:
        return pos[2][0]=='1';
    case 4:
        return pos[2][1]=='1';
    case 5:
        return pos[2][2]=='1';
    case 6:
        return pos[1][2]=='1';
    case 7:
        return pos[0][2]=='1';
    }
}


int main()
{
    int x,y,a,b,d,new_direction;
    char pos[3][3],c;
    while(cin>>y)
    {
        if(y==(-1))
            break;
        cin>>x>>d;
        pos[1][1]='1';
        for(int i=0; i<8; i++)
        {
            cin>>b>>a>>c;
            pos[1-(a-x)][1+b-y]=c;
        }
        for(int i=0; i<8; i++)
        {
            new_direction = (d+i+5)%8;
            if(found(new_direction,pos))
            {
                cout<<new_direction<<endl;
                break;
            }
        }
    }
    return 0;
}
/*
Sample Input
22 25 2
22 26 0
21 26 1
21 25 1
21 24 1
22 24 1
23 24 1
23 25 1
23 26 0
21 26 1
21 27 1
20 27 1
20 26 1
20 25 0
21 25 1
22 25 1
22 26 0
22 27 0
21 27 0
21 28 0
20 28 1
20 27 1
20 26 1
21 26 1
22 26 0
22 27 0
22 28 0
-1

Sample Output
1
0
1
*/
