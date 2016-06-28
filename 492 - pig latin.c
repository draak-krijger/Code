#include <stdio.h>
#include <string.h>
int vowel(char c)
{
    int b=0;
    if(c == 'A' || c == 'a' ||
            c == 'E' || c == 'e' ||
            c == 'I' || c == 'i' ||
            c == 'O' || c == 'o' ||
            c == 'U' || c == 'u' )
        b=1 ;
    return b;
}
int main()
{
    int a , i , j ,len ;
    char s[1000000];
    while(gets(s))
    {
        len = strlen(s);
        for(i=0 ; i <len ; i++)
        {
            if(isalpha(s[i]))
            {
                if(vowel(s[i]) == 1)
                {
                    for(j=i ;; j++)
                    {
                        if(s[j] == ' ' || isalpha(s[j]) == 0)
                        {
                            printf("ay");
                            i = j-1;
                             if(j>=len){
                                i = j;
                                printf("\n");
                             }
                            break;
                        }
                        printf("%c",s[j]);
                    }
                    if( i != len-1)
                    continue;
                }
                else
                {
                    a = i ;
                    for(j=i+1 ;; j++)
                    {
                        if(s[j] == ' ' || isalpha(s[j]) == 0)
                        {
                            printf("%cay",s[a]);
                            i = j-1;
                            if(j>=len){
                                i = j;
                                printf("\n");
                            }
                            break;
                        }
                        printf("%c",s[j]);
                    }
                     if( i != len-1)
                    continue;
                }
            }
            if(i >= len)
                break;
            printf("%c",s[i]);
            if( i == len-1)
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}

