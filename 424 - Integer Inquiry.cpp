#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

char ara[100][100] ;
int sum[100] ;

int main()
{
    int i , j , k , length = 0 , carry , loop ;
    long long sum1 ;

    i=0 ;

    while(scanf("%s",ara[i]))
    {
        if(strcmp(ara[i],"0") == 0)
            break ;

        sum1 = strlen(ara[i]) ;

        if(sum1 > length)
            length = sum1 ;

        i++ ;
    }

    loop = i ;
    k=0 ;
    sum1 = 0 ;

    for(j=length-1 ; j >= 0 ; j--)
    {
        for(i=0 ; i<loop ; i++)
        {
            if(isdigit(ara[i][j]))
                sum1 += ara[i][j] - '0' ;
            else
                sum1 += ara[i][j] - ara[i][j] ;
        }

        if(sum1 < 10)
            sum[k] = sum1 ;

        else
            sum[k] = sum1 % 10 ;

        k++ ;
        sum1 = sum1/10 ;
    }

    while(sum1 != 0)
    {
        sum[k] = sum1 % 10 ;
        k++;
        sum1 = sum1/10 ;
    }

    for (i=k-1 ; i>=0 ; i--)
        cout << sum[i] ;

    cout << endl ;

    return 0 ;
}

