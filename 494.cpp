/*
494 - Kindergarten Counting Game
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
    char name[1000];
    int len,i,p;
    while(gets(name))
    {
        p=0;
        len=strlen(name);
        for(i=0; i<len; i++)
            if(
                ((name[i]>='a'&& name[i]<='z')||
                 (name[i]>='A' && name[i]<='Z'))
                &&
                (name[i+1]<'a' || name[i+1]>'z') &&
                (name[i+1]<'A' || name[i+1]>'Z')
            )
                p++;
                printf("%d\n",p);
    }
    return 0;
}

/*
Sample Input
Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

Sample Output
2
7
10
9
*/
