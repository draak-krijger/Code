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

int pck[1100000] , primes[100000] ;

void set_prime();
bool check_bit(int n , int position);
int set_bit(int n , int position);

int main()
{
    int n , a , b ;
    bool check ;

    set_prime();

    while(scanf("%d",&n) != EOF && n)
    {
        check = false;

        for(int i = 0 ; primes[i]<=(n/2) ; i++)
        {
            a = primes[i] ;
            b = n - a ;

            if(!check_bit(pck[b>>5],b&31))
            {
                check = true;
                break;
            }
        }

        if(check)
            printf("%d:\n%d+%d\n",n,a,b);

        else
            printf("%d:\nNO WAY!\n",n);
    }
    return 0 ;
}

int set_bit(int n , int position)
{
    n = n | (1<<position);
    return n;
}

bool check_bit(int n , int position)
{
    return n & (1<<position);
}

void set_prime()
{
    int x ;
    x = sqrt(1000000);

    pck[0] = set_bit(pck[0],1);

    for(int i = 4 ; i<=1000010 ; i = i+2)
        pck[i>>5] = set_bit(pck[i>>5],i&31);

    for(int i = 3 ; i<=x ; i = i +2)
    {
        if(!check_bit(pck[i>>5],i&31))
        {
            for(int j = i+i ; j<=1000010 ; j = j+i)
                pck[j>>5] = set_bit(pck[j>>5],j&31);
        }
    }

    primes[0] = 2 ;
    int k = 1;

    for(int i=3 ; i<=1000010 ; i = i+2)
    {
        if(!check_bit(pck[i>>5],i&31))
            primes[k++] = i;
    }
}
