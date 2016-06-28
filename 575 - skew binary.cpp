#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std ;

long long int decl ;
char number[1000000];

void skew()
{
    int l , i , b ;
    l = strlen(number);
    decl = 0 ;
    i = 1 ;

    while(l>0)
    {
         b = number[l-1] - '0' ;
         decl += (pow(2,i) - 1)*b ;
         l-- ;
         i++ ;
    }
}

int main()
{
    while(scanf("%s",number))
    {
        if(strcmp(number,"0") == 0)
            return 0;

        skew();
        printf("%lld\n",decl);
    }
    return 0 ;
}
