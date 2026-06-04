#include <stdio.h>
char v[]="abcdefgh",o[10]="a",s[10][30]={"","  ","    ","      ","        ","          "};
void m(int d,int n){
    if(d==n){
        printf("%swriteln(%c",s[d],o[n-1]);
        for(int i=n-2;i>=0;i--) printf(",%c",o[i]);
        puts(")"); return;
    }
    for(int i=d;i>0;i--) o[i]=o[i-1];
    for(int i=0;i<d;i++){
        printf("%sif %c < %c then\n",s[d],o[i+1],v[d]);
        o[i]=v[d]; m(d+1,n); o[i]=o[i+1];
        printf("%selse ",s[d]);
    }
    puts(""); o[d]=v[d]; m(d+1,n);
}
int main(){
    int t,n,i; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("program sort(input,output);\nvar\na");
        for(i=1;i<n;i++) printf(",%c",v[i]);
        puts(" : integer;\nbegin\n readln(a");
        for(i=1;i<n;i++) printf(",%c",v[i]);
        puts(");"); m(1,n); puts("end.");
        if(t) puts("");
    }
    return 0;
}
