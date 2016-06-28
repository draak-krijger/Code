#include<stdio.h>
int main()
{
    int a,i,j,b=1,k,m,n,l;
    scanf("%d",&m);
    int line[m];
    for(n=0;n<m;n++){
    scanf("%d", &line[n]);
    }
    char s=' ',c='*';
    for(n=0;n<=m;n++){
    l=line[n];
    a=l;
    b=1;
    for(k=0;k<l;k++){
        if(n==m)
            break;
    for(i=0;i<a;i++){
        printf("%c",s);
        }
        for(j=0;j<b;j++){
            printf("%c",c);
        }
        printf("\n");
        a--;
        b=b+2;
        i=0;
    }
    }
    return 0;
}
