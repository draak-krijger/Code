#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std ;

int main()
{
    int a , b , c , cnt=0 , l , i ;
    bool check1 , check2 ;
    char s[100] , sign ;

    while(scanf("%s",&s) != EOF)
    {
        l = strlen(s);
        i = 0 ;
        check1 = check2 = true;
        a = b = c = 0 ;
        while(i<l)
        {
            if(isdigit(s[i]) && check1 && check2)
            {
                a = a*10 + (s[i] - '0');
            }

            if(!isdigit(s[i]))
            {
                if(!check1)
                    check2 = false ;

                if(check1){ sign = s[i];
                    check1 = false;
                }

            }

            if(isdigit(s[i]) && !check1 && check2)
            {
                b = b*10 + (s[i] - '0');
            }

            if(isdigit(s[i]) && !check1 && !check2)
            {
                c = c*10 + (s[i] - '0');
            }
            i++;
        }

        if(sign == '+')
        {
            if(a+b == c)
                cnt++;

        }

        else if(sign == '-')
        {
            if(a-b == c)
                cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0 ;
}
