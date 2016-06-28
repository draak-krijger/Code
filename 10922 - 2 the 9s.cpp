#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    char a[2000];
    int length , i, sum , cnt , d ;

    while(gets(a))
    {
        length = strlen(a);
        sum = 0 ;
        cnt = 1 ;

        if(a[0] == '0' && length == 1)
            return 0 ;

        for(i=0 ; i<length ; i++)
        {
            sum += a[i] - '0';
        }

        if(sum%9 != 0)
        {
            printf("%s is not a multiple of 9.\n",a);
            continue ;
        }

        else
        {
            while(sum != 9)
            {
                d=0 ;
                cnt ++ ;

                while(sum != 0)
                {
                    d += sum%10 ;
                    sum= sum / 10 ;
                }

                sum = d ;
            }
        }
        printf("%s is a multiple of 9 and has 9-degree %d.\n",a,cnt);
    }
    return 0 ;
}

