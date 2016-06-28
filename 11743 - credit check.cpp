#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , a , i , j , sum1 , sum2 ;
    char s[50];

    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        gets(s);

        i = j = sum1 = 0 ;

        while(i<18)
        {
            j++ ;
            a = s[i] - '0';
            a = a*2 ;

            while(a != 0)
            {
                sum1 += a%10 ;
                a = a/10 ;
            }

            if(j==2)
            {
                i = i+3 ;
                j = 0 ;
                continue ;
            }

            i = i+2 ;
        }

        sum2 = s[1] + s[3] + s[6] + s[8] + s[11] + s[13] + s[16] + s[18] - 8*('0');

        sum1 = sum1 + sum2 ;

        if(sum1 % 10 == 0)
            printf("Valid\n");

        else
            printf("Invalid\n");
    }
    return 0 ;
}
