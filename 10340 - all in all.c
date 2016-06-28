#include <stdio.h>
#include <string.h>
int main()
{
    int a , b , c , i , j , k ;
    char s[1000000],ss[1000000] ;
    while(scanf("%s %s",s,ss) == 2)
    {
        a = strlen(s);
        b = strlen(ss);
        c = 0 ;
         j = 0 ;
        for(i=0 ; i<b ; i++)
        {
            if(ss[i] == s[j])
            {
                j++;
            }
            if(j == a)
            {
                c=1;
                break;
            }
        }
        if(c==1)
            printf("Yes\n");
        else if(c==0)
            printf("No\n");
    }
    return 0 ;
}

