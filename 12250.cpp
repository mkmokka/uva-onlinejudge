/*
12250 - Language Detection
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    char input[100];
    int i=1;
    while(scanf("%s",&input)!=EOF)
    {
        if(strcmp(input,"#")==0)break;
        else if(strcmp(input,"HELLO")==0)printf("Case %d: ENGLISH\n",i);
        else if(strcmp(input,"HOLA")==0)printf("Case %d: SPANISH\n",i);
        else if(strcmp(input,"HALLO")==0)printf("Case %d: GERMAN\n",i);
        else if(strcmp(input,"BONJOUR")==0)printf("Case %d: FRENCH\n",i);
        else if(strcmp(input,"CIAO")==0)printf("Case %d: ITALIAN\n",i);
        else if(strcmp(input,"ZDRAVSTVUJTE")==0)printf("Case %d: RUSSIAN\n",i);
        else printf("Case %d: UNKNOWN\n",i);
        i++;

    }
    return 0;
}
/*
Sample Input
HELLO
HOLA
HALLO
BONJOUR
CIAO
ZDRAVSTVUJTE
#

Sample Output
Case 1: ENGLISH
Case 2: SPANISH
Case 3: GERMAN
Case 4: FRENCH
Case 5: ITALIAN
Case 6: RUSSIAN
*/



