#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std ;

int num[10000] , last[10] , l ;
long long b ;

void smallnum()
{
    int i , carry ;
    l = l - 1 ;

    while(l>9)
    {
        b = num[l];
        b = b*5 ;
        last[0] = b%10 ;
        b = b/10;
        last[1] = b%10 ;
        l-- ;
        i = carry = 0 ;

        while(i<=1)
        {
            if(num[l-i] >= (last[i] + carry))
            {
                num[l-i] = num[l-i] - last[i] - carry ;
                carry = 0 ;
            }

            else
            {
                num[l-i] = (num[l-i]+10) - last[i] - carry;
                carry = 1 ;

                if(i==1)
                {
                    num[l-i-1] = num[l-i-1] - carry;
                }
            }
            i++;
        }

    }

    b = 0 ;
    i = 0 ;

    while(i<=l)
    {
        b = b*10 + num[i];
        i++;
    }
}

int main()
{
    int i , j ;
    char c[10000] ;

    while(gets(c))
    {
        if(strcmp(c,"0") == 0)
            return 0 ;

        for(l=0 ; l<strlen(c) ; l++)
        {
            num[l] = c[l] - '0';
        }

        smallnum();

        if(b%17 == 0)
            printf("1\n");

        else
            printf("0\n");
    }
    return  0;
}
