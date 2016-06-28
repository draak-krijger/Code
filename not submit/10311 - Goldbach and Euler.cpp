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

vector<int>primes ;
bool ckprimes[100000100] ;

void sieve();
int calcount(int n);

int main()
{
    sieve();
    int n;

    while(scanf("%d",&n) != EOF && n)
        calcount(n);

    return 0 ;
}

void sieve()
{
    ckprimes[1] = true;

    for(int i=4 ; i<=100000000 ; i += 2)
        ckprimes[i] = true;


    for(int i=3 ; i*i<=100000000 ; i = i+2)
    {
        if(ckprimes[i])
        {
            for(int j=i+i ; j<=100000000 ; j += i)
                ckprimes[j] = true;
        }
    }

    primes.push_back(2);

    for(int i = 3 ; i<=100000000 ; i++)
        if(!ckprimes[i])
            primes.push_back(i);
}

int calcount(int l)
{
    int cont = 0 , b = 0 , c , ans1 = 0 , ans2 = 0 , n ;
    n = l/2 ;

    for(int i=0 ; primes[i]<2*n ; i++)
    {
        if(primes[i]>=n)
        {
            b = i ;
            break;
        }
    }

    for(int i=b ; i>=0 ; i--)
    {
        for(int j=b ; primes[j]<=l ; j++)
        {
            c = primes[i] + primes[j];

            if(c == l)
            {
                if(!((primes[j]-primes[i])&1))
                {
                    cont++;
                    ans1 = primes[i] ;
                    ans2 = primes[j] ;
                    break;
                }
            }

            if(c>l)
                break;
        }

        if(cont)
            break;
    }

    if(!ans1 && !ans2)
        printf("%d is not the sum of two primes!\n",l);

    else
        printf("%d is the sum of %d and %d.\n",l,ans1,ans2);
}


