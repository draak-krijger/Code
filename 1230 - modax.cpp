#include <iostream>
#include <cstdio>

using namespace std ;

int modax(int base , int pow , int mod)
{
    int result = 1 ;

    while(pow > 0)
    {
        if(pow & 1)
        {
            result = (result*base)%mod ;
        }

        base =(base*base)%mod;
        pow = pow/2;
    }
    return result ;
}

int main()
{
    int x , y , n , tcase ;

    while(scanf("%d",&tcase) != EOF)
    {
        if(tcase == 0)
            return 0 ;

        while(tcase--)
        {
            scanf("%d %d %d",&x,&y,&n);
            printf("%d\n",modax(x,y,n));
        }
    }
    return 0 ;
}
