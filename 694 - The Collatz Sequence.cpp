#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int b, a , i , j =0 ;
    long long c ;

    while(scanf("%d %d",&a,&b) != EOF)
    {
        if(a<0 && b<0)
            return 0 ;
        j++ ;
        i=0 ;
        c=a ;

        while(c<=b)
        {
            i++ ;

            if(c==1)
                break ;

            if(c & 1)
                c= 3*c +1 ;

            else
                c = c/2 ;

        }

        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",j,a,b,i);
    }
    return 0 ;
}

