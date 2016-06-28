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
bool ckprimes[32700] ;

void sieve();
int calcount(int n);

int main()
{
    sieve();
    int n;

    while(scanf("%d",&n) != EOF && n)
        printf("%d\n",calcount(n));

    return 0 ;
}

void sieve()
{
    fill(ckprimes,ckprimes+32700,true);
    ckprimes[1] = false;

    for(int i=4 ; i<=32780 ; i += 2)
        ckprimes[i] = false;


    for(int i=3 ; i*i<=32780 ; i = i+2)
    {
        if(ckprimes[i])
        {
            for(int j=i+i ; j<=32700 ; j += i)
                ckprimes[j] = false;
        }
    }

    primes.push_back(2);

    for(int i = 3 ; i<=32780 ; i++)
        if(ckprimes[i])
            primes.push_back(i);
}

int calcount(int n)
{
    int cont = 0 , b = 0 , c ;
    n = n/2 ;

    for(int i=0 ; primes[i]<2*n ; i++)
    {
        if(primes[i]>=n)
        {
            b = i ;
            break;
        }
    }

    for(int i=0 ; primes[i]<=n ; i++)
    {
        for(int j=b ; primes[j]<=2*n ; j++)
        {
            c = primes[i] + primes[j];

            if(c == 2*n)
                cont++;

            if(c>2*n)
                break;
        }
    }
    return cont;
}


