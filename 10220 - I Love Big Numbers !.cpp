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

int fact[1010][10000] , length[1010] ;

void calfactorial();
int multiply(int n);
int sumofdigit(int n);

int main()
{
    int n ;
    calfactorial();

    while(scanf("%d",&n) != EOF)
        sumofdigit(n);

    return 0;
}

void calfactorial()
{
    fact[0][0] = 1 ;
    fact[1][0] = 1 ;
    length[0] = length[1] = 0 ;

    for(int i=2 ; i<=1001 ; i++)
        multiply(i);
}

int multiply(int n)
{
    int r = 0 , i ;

    for(i = 0 ; i<=length[n-1] ; i++)
    {
        r = fact[n-1][i]*n + r ;
        fact[n][i] = r%10;
        r = r/10;
    }

    if(r)
    {
        while(r)
        {
            fact[n][i++] = r%10 ;
            r = r/10;
        }
    }
    length[n] = i-1 ;
}

int sumofdigit(int n)
{
    int sum = 0 ;

    for(int i=0 ; i<=length[n] ; i++)
        sum += fact[n][i] ;

    printf("%d\n",sum);
}
