#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int a , b , c , i , j , k ;
    char s[100];
    while(gets(s))
    {
        if(strcmp(s,"DONE") == 0)
            break;
        c = 0 ;
        j = 0 ;
        a = strlen(s);
        for(i=0 ; i<a ; i++)
        {
            if(isalpha(s[i]))
            {
                s[j] = s[i];
                j++ ;
            }
        }
        for(i=0 , k=j-1 ; i < k ; i++ , k--)
        {
            if(s[i] != s[k])
            {
                if(islower(s[i]))
                {
                    if(s[i] == tolower(s[k]))
                        continue;
                    else
                    {
                        c = 1 ;
                        break;
                    }
                }
                else if(isupper(s[i]))
                {
                    if(s[i] == toupper(s[k]))
                        continue;
                    else
                    {
                        c = 1 ;
                        break ;
                    }
                }
            }
        }
        if(c == 0)
            printf("You won't be eaten!\n");
        else if(c == 1)
            printf("Uh oh..\n");
    }
    return 0 ;
}

