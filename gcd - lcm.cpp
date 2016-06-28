#include <iostream>
#include <cstdio>

using namespace std ;

int gcd(int a , int b)
{
    int c ;

    while(b != 0)
    {
        c = a%b ;
        a = b ;
        b = c ;
    }
    return a ;
}

int main()
{
    int a , b , gcdf , lcm ;

    while(scanf("%d %d",&a,&b) != EOF)
    {
        gcdf = gcd(a,b) ;
        lcm = (a*b)/gcdf ;

        printf("GCD : %d  LCM : %d \n",gcdf,lcm);
    }
    return 0 ;
}

