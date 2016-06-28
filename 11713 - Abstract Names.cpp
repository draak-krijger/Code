#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;
bool check ;

int isvowel(char a)
{
    int b ;
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='0')
        b = 1 ;

    else
        b = 0 ;

    return b ;
}
int main()
{
    int tcase , i, length1 , length2 ;
    char s1[50],s2[50] ;

    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        scanf("%s %s",s1,s2);

        length1 = strlen(s1);
        length2 = strlen(s2);

        if(length1 == length2)
        {
            check = true ;
            for(i=0 ; i<length1 ; i++)
            {
                if(s1[i] != s2[i])
                {
                    if(isvowel(s1[i]))
                    {
                        if(isvowel(s1[i]) != isvowel(s2[i]))
                        {
                            printf("No\n");
                            check = false ;
                            break ;
                        }
                    }

                    else
                    {
                        printf("No\n");
                        check = false ;
                        break ;
                    }
                }
            }

            if(check == true)
                printf("Yes\n");
        }

        else
            printf("No\n");
    }
    return 0 ;
}
