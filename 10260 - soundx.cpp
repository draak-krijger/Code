#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    char word[100] ,  b[100];
    int i , j , length , a ;

    while(gets(word))
    {
        length = strlen(word);
        a=j=0 ;

        for(i=0 ; i<length ; i++)
        {
            if(word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'H' || word[i] == 'W' || word[i] == 'Y' )
            {
                a = 0 ;
                continue ;
            }

            else if(word[i] == 'B' || word[i] == 'F' || word[i] == 'P' || word[i] == 'V' )
            {
                if(a != 1)
                {
                    a = 1 ;
                    b[j] = 1 ;
                    j++ ;
                }
            }

            else if(word[i] == 'C' || word[i] == 'G' || word[i] == 'J' || word[i] == 'K' || word[i] == 'Q' || word[i] == 'S' || word[i] == 'X' || word[i] == 'Z')
            {
                if(a != 2)
                {
                    a = 2 ;
                    b[j] = 2 ;
                    j++ ;
                }
            }

            else if(word[i] == 'D' || word[i] == 'T')
            {
                 if(a != 3)
                {
                    a = 3 ;
                    b[j] = 3 ;
                    j++ ;
                }
            }

            else if(word[i] == 'L')
            {
                 if(a != 4)
                {
                    a = 4 ;
                    b[j] = 4 ;
                    j++ ;
                }
            }

            else if(word[i] == 'M' || word[i] == 'N')
            {
                if(a != 5)
                {
                    a = 5 ;
                    b[j] = 5 ;
                    j++ ;
                }
            }

            else if(word[i] == 'R')
            {
                 if(a != 6)
                {
                    a = 6 ;
                    b[j] = 6 ;
                    j++ ;
                }
            }
        }

        for(i=0 ; i<j ; i++)
            printf("%d",b[i]) ;

        printf("\n");

    }
    return 0 ;
}

