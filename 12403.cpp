/*
12403 - Save Setu
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ab[10];
    int test,i,get=0,money=0;
    scanf("%d",&test);
    for(i=0; i<test; i++)
    {
        scanf("%s",ab);
        if(ab[0]=='d')
        {
            scanf("%d",&get);
                    money=money+get;
        }
        else if(ab[0]=='r')printf("%d\n",money);
    }
    return 0;
}
/*
Sample Input
4
donate 1000
report
donate 500
report

Sample Output
1000
1500
*/

