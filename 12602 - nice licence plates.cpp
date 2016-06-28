#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    int a , b , i , j , tcase ;
    char s[100];

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s",s);

        a = (s[0] - 'A')*pow(26,2) + (s[1] - 'A')*pow(26,1) + (s[2] - 'A')*pow(26,0);

        b = 0 ;

        for(i=4 ; i<=7 ; i++)
        {
            b = b*10;
            b += s[i] - '0' ;
        }

         if(abs(a-b) <= 100)
            printf("nice\n");

         else
            printf("not nice\n");
    }
    return 0 ;
}
