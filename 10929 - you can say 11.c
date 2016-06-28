#include <stdio.h>
#include <string.h>
int main()
{
    int  b ,l,i,a=0;
    char s[10000];
    while(scanf("%s",s) != EOF)
    {
        a = 0 ;
        if(strcmp(s,"0") == 0)
            break;
        l=strlen(s);
        for(i=0; i<l; i++)
        {
            a=a*10+(s[i] -'0');
            a=a%11;
        }
        if(a==0)
            printf("%s is a multiple of 11.\n",s);
        else
            printf("%s is not a multiple of 11.\n",s);
    }
    return 0 ;
}

