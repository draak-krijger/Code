#include <stdio.h>
#include <string.h>
int main()
{
    int a , b ,i , j , count ;
    char st[1000];
    while(gets(st))
    {
        count = 0;
        b = strlen(st);
        for(i=0 ; i<b ; i++)
        {
            if(isalpha(st[i]))
            {
                for(;; i++)
                {
                    if(isalpha(st[i]) == 0)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0 ;
}

