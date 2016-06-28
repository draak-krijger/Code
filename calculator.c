#include<stdio.h>
int main()
{
    int a,b,d,s;
    char c;
    scanf("%d",&a);
    scanf("%c",&c);
    scanf("%d",&b);
    printf("=");
    scanf("%d",&s);
    printf("\n\n");
    if(c=='+')
        d=a+b;
    else if(c=='-')
        d=a-b;
    else if(c=='*')
        d=a*b;
    else if(c=='/')
        d=a/b;
        if(d==s)
    printf("%d%c%d=%d",a,c,b,d);
    else
        printf("wrong!!!!");
    return 0;
}
