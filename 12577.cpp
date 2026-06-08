/*
12577 - Hajj-e-Akbar
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ab[1000];
    int i=1;
    while(scanf("%s",&ab)!=EOF)
    {
        if(ab[0]=='*')break;

        else if(ab[0]=='H')
            printf("Case %d: Hajj-e-Akbar\n",i);
        else if(ab[0]=='U')
            printf("Case %d: Hajj-e-Asghar\n",i);
        i++;
    }

    return 0;
}
/*
Sample Input
Hajj
Umrah
Hajj
Umrah
*

Sample Output
Case 1: Hajj-e-Akbar
Case 2: Hajj-e-Asghar
Case 3: Hajj-e-Akbar
Case 4: Hajj-e-Asghar
*/

