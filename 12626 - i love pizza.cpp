#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , m , a , r , g , i , t , j , len ;
    char str[10000];

    scanf("%d",&tcase) ;

    while(tcase--)
    {
        m = a = r = g = i = t = 0 ;

        scanf("%s",str);

        len = strlen(str);

        for(j=0 ; j<len ; j++)
        {
            if(str[j] == 'M')
                m++;

            else if(str[j] == 'A')
                a++;

            else if(str[j] == 'R')
                r++;

            else if(str[j] == 'G')
                g++;

            else if(str[j] == 'I')
                i++;

            else if(str[j] == 'T')
                t++;
        }

        len = 0 ;

        while(1)
        {
            if(r>1 && a>2 && t>0 && i>0 && m>0 && g>0)
            {
                len++ ;
                 r -= 2 ;
                 a -= 3 ;
                 t -- ;
                 i-- ;
                 m-- ;
                 g-- ;
            }

            else
                break ;
        }

        printf("%d\n",len);
    }
    return 0 ;
}
