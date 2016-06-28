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

int fact[20000];

void callastdigit();

int main()
{
    int n ;
    callastdigit();

    while(scanf("%d",&n) != EOF)
        printf("%5d -> %d\n",n,fact[n]);

    return 0 ;
}

void callastdigit()
{
    fact[0] = fact[1] = 1 ;
    int a , b ;

    a=1;

    for(int i=2 ; i<=10000 ; i++)
    {
        a *= i ;

        while(a%10 == 0)
            a = a/10;

        a = a%100000 ;
        fact[i] = a%10 ;
    }
}
