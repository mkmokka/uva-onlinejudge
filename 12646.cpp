/*

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c) == 3)
    {
        if(a == b && b == c)
            cout<<"*"<<endl;
        else if(a != b && b == c)
            cout<<"A"<<endl;
        else if(a != b && a == c)
            cout<<"B"<<endl;
        else if(a == b && a != c)
            cout<<"C"<<endl;
    }
    return 0;
}

/*
Sample Input
1 1 0
0 0 0
1 0 0

Sample Output
C
*
A
*/
