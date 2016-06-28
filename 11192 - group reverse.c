#include <stdio.h>
#include<string.h>
int main()
{
    int a ,b,c,i,j,k;
    char st[150];
    while(1){
    scanf("%d ",&a) == 1;
    if(a==0)
        break;
    scanf("%s",st) == 1;
    b =strlen(st);
    c = b/a;
    k=0;
    b=0;
    for(i=0;i<a;i++)
    {
        b=b+c;
        for(j=b-1;j>=k;j--)
        {
            printf("%c",st[j]);
        }
        k= k+c;
    }
    printf("\n");
    }
    return 0;
}

