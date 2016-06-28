#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std ;
char a[100000];
int main()
{
    int z , l , i , j , m , b=0 , k;

    while(scanf("%d %d %d %d",&z,&i,&m,&l) != EOF)
    {
        if( !z && !i && !m && !l)
            return 0 ;

        k = 0 ;
        memset(a , '0' , sizeof a);
        b++;

        do
        {
            l = ((z%m)*(l%m) +i)%m ;

            if(a[l] == '1')
                break;

            a[l] = '1';
            k++;
        }
        while(a[l] == '1');

        printf("Case %d: %d\n",b,k);
    }
    return 0 ;
}
