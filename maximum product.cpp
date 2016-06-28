#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    long long  tcase , n[100] , i , j = 0  , produc , b , finalproduc , l ;
    bool check , num , zero ;

    while(scanf("%lld",&tcase) == 1)
    {
        j++;
        produc = b = 1 ;
        finalproduc = 0 ;
        num = check = true ;
        zero = true ;

        for(i=0 ; i<tcase ; i++)
        {
            scanf("%lld",&n[i]);

            if(n[i] == 0)
            {
                if(b<0)
                    b = b/l ;

                if(b>finalproduc)
                    finalproduc = b ;

                if(produc >finalproduc)
                    finalproduc = produc ;

                produc = b = 1 ;
                check = true ;
                zero = true ;
                continue;
            }

            if(n[i]>0 && check)
            {
                produc = produc*b*n[i] ;
                zero = true ;
                num = false ;
                b=1;
            }

            else
            {
                b = b*n[i] ;
                check = false ;

                if(zero)
                {
                    l = n[i] ;
                    zero = false ;
                }

                if(b>0)
                {
                    check = zero = true ;
                    produc = produc*b;
                    num = false;
                    b = 1 ;
                }
            }
        }

        if(!zero)
        {
            b = b/l ;

            if(b>finalproduc)
                finalproduc = b ;

        }

        if(produc>finalproduc)
            finalproduc = produc;

        if(num)
            finalproduc = 0 ;

        printf("Case #%lld: The maximum product is %lld.\n\n",j,finalproduc);
    }
    return 0 ;
}
