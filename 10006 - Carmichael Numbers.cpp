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

using namespace std ;

bool primes[70000] ;

void seave();
int bigmod(long long int base , int exp , int mod);
void charmicle(int n);

int main()
{
    seave();
    int n ;

    while(scanf("%d",&n) != EOF && n)
    {
        charmicle(n);
    }

    return 0 ;
}

void seave()
{
    fill(primes,primes+65000,true);

    primes[1] = false;
    int x ;
    x = sqrt(65000.0);

    for(int i=4 ; i<=65000 ; i = i+2)
        primes[i] = false;

    for(int i = 3 ; i<=x ; i++)
    {
        if(primes[i])
        {
            for(int j=i+i ; j<=65000 ; j+=i)
                primes[j] = false;
        }
    }
}

int bigmod(long long int base , int exp , int mod)
{
    long long int result = 1 ;

    while(exp)
    {
        if(exp&1)
        {
            result = (result*base)%mod;
        }

        exp = exp/2;
        base = (base*base)%mod;
    }
    return result;
}

void charmicle(int n)
{
    int a , b ;
    bool ischarmicle = true;

    if(!primes[n])
    {
        for(int i=2 ; i<n ; i++)
        {
            if(bigmod(i,n,n) != i)
            {
                ischarmicle = false;
                break;
            }
        }
    }

    else
        ischarmicle = false;

    if(ischarmicle)
        printf("The number %d is a Carmichael number.\n",n);

    else
        printf("%d is normal.\n",n);
}
