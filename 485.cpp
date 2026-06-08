/*
485 - Pascal's Triangle of Death
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d ",1);
        }
        printf("\n");
    }
}
/*
Sample Input
There is no input for this problem.So enter the value of n for triangle

Sample Output
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
