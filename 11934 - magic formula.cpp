#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int a , b , c , d , l , cnt , i ;
    long long f ;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l) != EOF)
    {
        if( !a && !b && !c && !d && !l )
            return 0 ;

        cnt = 0 ;

        for(i=0 ; i<=l ; i++)
        {
            f = a*(i*i) + b*i + c ;

            if(f%d == 0)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0 ;
}
