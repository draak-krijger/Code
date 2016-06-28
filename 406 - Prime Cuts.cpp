#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>

using namespace std;

int primeck[2000] , primes[1000] , num ;

void set_prime();
bool check_bit(int n , int position);
int set_bit(int n , int position);
int cal_num(int n);

int main()
{
    int n , c , l , midle ;
    set_prime();

    while(scanf("%d %d",&n,&c) == 2)
    {
        cal_num(n);

        printf("%d %d:",n,c);
        if(num%2 == 1)
        {
            midle = ceil((double)num/2.0) - c ;

            if(midle<=0)
            {
                for(int i = 0 ; i<num ; i++)
                    printf(" %d",primes[i]);
            }

            else
            {
                while(midle<((num/2)+c))
                    printf(" %d",primes[midle++]);
            }
        }
        else
        {
            midle = (num/2) - c ;

            if(midle<=0)
            {
                for(int i = 0 ; i<num ; i++)
                    printf(" %d",primes[i]);
            }

            else
            {
                while(midle<((num/2)+c))
                    printf(" %d",primes[midle++]);
            }
        }
        printf("\n\n");
    }
    return 0 ;
}

int set_bit(int n , int position)
{
    n = n | (1<<position);

    return n ;
}

bool check_bit(int n , int position)
{
    return n & (1<<position);
}

void set_prime()
{
    for(int i = 4 ; i<=1050 ; i = i+2)
        primeck[i>>5] = set_bit(primeck[i>>5],i&31);

    for(int i = 3 ; i<=sqrt(1050) ; i = i+2)
    {
        if(!check_bit(primeck[i>>5],i&31))
        {
            for(int j = i+i ; j<=1050 ; j = j+i )
                primeck[j>>5] = set_bit(primeck[j>>5],j&31);
        }
    }

    num = 0 ;

    for(int i=1 ; i<=1050 ; i++)
    {
        if(!check_bit(primeck[i>>5],i&31))
            primes[num++] = i ;
    }
}

int cal_num(int n)
{
    num = 0;

    while(primes[num]<=n)
    {
        num++;
    }
}
