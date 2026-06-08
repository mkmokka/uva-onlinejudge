/*
11559 - Event Planning
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long frnd,bud,hotel,week,amount,cost=15000000,b,p,visit,i,j,room;
    while(scanf("%ld%ld%ld%ld",&frnd,&bud,&hotel,&week)==4)
    {
        for(i=0;i<hotel;i++)
        {
            scanf("%ld",&amount);
            for(j=0;j<week;j++)
            {
                scanf("%ld",&room);
                p=0;
                if(room>=frnd)
                {
                    p=amount*frnd;
                    if(cost>p)
                    cost=p;
                }
            }
        }
            if(cost>bud)
            printf("stay home\n");
            else
            printf("%ld\n",cost);
            cost=15000000;
        }
    return 0;
}

/*
Sample Input
3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13

Sample Output
900
stay home
*/
