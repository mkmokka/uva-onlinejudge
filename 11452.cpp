/*
11452 - Dancing the Cheeky-Cheeky
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[2001],str1[1000],str2[1000];
    int i,j,k,len,x,m,t,p,y,check,w,n;
    scanf("%d",&t);
    getchar();
    while(t--){
    gets(str);
    len=strlen(str);
    x=len/2;
    do{
    m=0,n=0;
    for(i=0;i<x;i++){
        str1[m++]=str[i];
        str2[n++]=str[i+x];
    }
        str1[m]=str2[n]='\0';

    x--;
    }   while(strcmp(str1,str2)!=0);
    y=strlen(str1);
    w=len-2*y;
    check=0;
    while(check!=9){
    for(i=0+w;i<y;i++){
            check++;
            if(check==9) break;
        printf("%c",str1[i]);
    }
    w=0;
    }
    printf("...\n");
    }
}


/*
Sample Input
6
123123
1231231
12312312
123124123124
12312412312412
12312412312412312

Sample Output
12312312...
23123123...
31231231...
12312412...
31241231...
41231241...
*/
