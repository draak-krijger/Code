#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std ;
int prime[1000000];
int setprime();
int checkbit(int n , int position);
int setbit(int n , int position);

int main()
{
    int a ;
    setprime();

    while(scanf("%d",&a) != EOF)
    {
        if(!checkbit(prime[a >> 5],a&31))
            printf("prime\n");

        else
            printf("not prime\n");
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

int setprime()
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
