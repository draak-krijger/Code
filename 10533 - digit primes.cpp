#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 10000000 ;
#include <cmath>

using namespace std ;

int prime[1000000] , fcnt[1000000] ;

int setbit(int n , int position);
int checkbit(int n , int position);
void setprime();
void proces();
int digit(int n);

int main()
{
    int tcase , a , b , c , d , cont ;
    setprime();
    proces();

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&a,&b);

        printf("%d\n",fcnt[b] - fcnt[a-1]);
    }
    return 0 ;
}

int setbit(int n , int position)
{
    n = n | (1 << position);
    return n ;
}

int checkbit(int n , int position)
{
    return n & (1 << position);
}

void setprime()
{
    int x = sqrt(1000000);
    prime[0] = setbit(prime[0] , 1);

    for(int i = 4 ; i<= 10000000 ; i += 2)
        prime[i >> 5] = setbit(prime[i >> 5] , i&31);

    for(int i = 3 ; i<= x ; i++)
    {
        if(!checkbit(prime[i >> 5] , i&31))
        {
            for(int j = i+i ; j<= 10000009 ; j += i)
                prime[j >> 5] = setbit(prime[j >> 5], j&31);
        }
    }
}

void proces()
{
    int cont = 0 , l ;

    fcnt[0] = fcnt[1] = fcnt[2] = 0 ;

    for(int i=2 ; i<=1000009 ; i++)
    {
        if( !checkbit(prime[i >> 5] , i&31))
        {
            l = digit(i);

            if( !checkbit(prime[l >> 5] , l&31))
            {
                cont++;
            }
        }

        fcnt[i] = cont;
    }
}

int digit(int n)
{
    int t =0 ;

    while(n>0)
    {
        t += n%10 ;
        n = n/10;
    }
    return t ;
}
