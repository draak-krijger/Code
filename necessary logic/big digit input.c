#include <stdio.h>
#include <string.h>
int main()
{
    int  b ,l,i,a=0;
    char s[1000];
    scanf("%s",s);
    l=strlen(s);
    for(i=0; i<l; i++)
    {
        a=a*10+(s[i]-'0');
        a=a%11;
    }
    printf("%d",a);
    return 0 ;
}

