#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;

double b ;

void num_digit(int a)
{
    int i ;
    b=0;
    while(a>0)
    {
        b += log10(a);
        a--;
    }
}

int main()
{
    int tcase , a ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&a);
        num_digit(a);
        b = floor(b) + 1;
        printf("%.0lf\n",b);
    }
    return 0 ;
}
