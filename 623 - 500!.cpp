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

void multiple(int num);
void factorialcal();

int main()
{
    long long int a ;
    fact[1][0] = fact[0][0] = 1 ;
    length[1] = 0 ;
    factorialcal();

    while(scanf("%lld",&a) != EOF)
    {
        printf("%lld!\n",a);
        for(int i=length[a] ; i>=0 ; i--)
            printf("%d",fact[a][i]);

        printf("\n");
    }
    return 0 ;
}

void factorialcal()
{
    for(int i=2 ; i<1001 ; i++)
        multiple(i);
}

void multiple(int num)
{
    int ara[10000] , i , r=0 ;

    for(i=0 ; i<=length[num-1] ; i++)
        ara[i] = fact[num-1][i];

    for(int i=0 ; i<=length[num-1] ; i++)
    {
        fact[num][i] = (ara[i]*num + r )%10;
        r = (ara[i]*num + r )/10 ;
    }

    if(r)
    {
        while(r)
        {
            fact[num][i] = r%10;
            r = r/10;
            i++;
        }
    }

    length[num] = i-1;
}
