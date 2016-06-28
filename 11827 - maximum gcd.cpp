#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std ;

int gcd(int a , int b)
{
    int c ;
    while(b>0)
    {
        c = a%b ;
        a = b ;
        b = c ;
    }

    return a ;
}
int main()
{
    int tcase , num[500] , i , j , k  , mam , l , gd ;
    char s [10000];

    scanf("%d",&tcase);
    getchar();
    while(tcase--)
    {
        gets(s);
        {
            l = strlen(s);

            memset(num , 0 , sizeof(num));
            j = 0 ;

            for(i=0 ; i<l ; i++)
            {
                if(isdigit(s[i]))
                {
                    num[j] = num[j]*10 + (s[i] - '0');
                }

                else
                {
                    if(isdigit(s[i+1]) && i!= l-1)
                        j++;
                }
            }
            mam = 0 ;

            for(i=0 ; i<j ; i++)
            {
                for(l=i+1 ; l<=j ; l++)
                {
                    gd = gcd(num[i],num[l]);

                    if(gd>mam)
                        mam = gd ;
                }
            }
            printf("%d\n",mam);
        }
    }
    return 0 ;
}
