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

bool prime[10100] ;
vector<int>primes;

void calculateprime();

int main()
{
    int n , l , b , tcase ;
    calculateprime();

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);
        l = n/2 ;

        for(int i=0 ; primes[i]<=n ; i++)
        {
            if(primes[i]>l)
            {
                b = primes[i];
                break;
            }
        }
        printf("%d\n",b);
    }
    return 0 ;
}

void calculateprime()
{
    prime[1] = true;

    for(int i=4 ; i<=10000 ; i += 2)
        prime[i] = true;

    for(int i=3 ; i*i<=10000 ; i += 2)
    {
        if(!prime[i])
        {
            for(int j = i+i ; j<=10000 ; j += i)
            {
                prime[j] = true;
            }
        }
    }

    primes.push_back(2);

    for(int i=3 ; i<=10000 ; i += 2)
    {
        if(!prime[i])
        {
            primes.push_back(i);
        }
    }
}
