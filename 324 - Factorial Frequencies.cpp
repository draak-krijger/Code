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

int fact[1010][10000] , length[1010] , digit[1010][12] ;

void calfactorial();
int multiply(int n);
int sumofdigit(int n);

int main()
{
    int n ;
    calfactorial();

    while(scanf("%d",&n) != EOF && n)
        sumofdigit(n);

    return 0;
}

void calfactorial()
{
    fact[0][0] = 1 ;
    digit[0][1] = 1 ;
    fact[1][0] = 1 ;
    digit[1][1] = 1 ;
    length[0] = length[1] = 0 ;

    for(int i=2 ; i<=400 ; i++)
        multiply(i);
}

int multiply(int n)
{
    int r = 0 , i ;

    for(i = 0 ; i<=length[n-1] ; i++)
    {
        r = fact[n-1][i]*n + r ;
        fact[n][i] = r%10;
        digit[n][fact[n][i]]++;
        r = r/10;
    }

    if(r)
    {
        while(r)
        {
            fact[n][i++] = r%10 ;
            digit[n][fact[n][i-1]]++;
            r = r/10;
        }
    }
    length[n] = i-1 ;
}

int sumofdigit(int n)
{
    printf("%d! --\n",n);

    for(int i=0 ; i<=9 ; i+=5)
        printf("   (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d    (%d)%5d\n",i,digit[n][i],i+1,digit[n][i+1],i+2,digit[n][i+2],i+3,digit[n][i+3],i+4,digit[n][i+4]);

    //printf("%d\n",sum);
}
