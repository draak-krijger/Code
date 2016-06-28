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
#define jora pair<int,int>
#define pb push_back

using namespace std ;

unsigned long long int ans , ans2 ;

void calculation(int cas);
unsigned long long nCr(int n, int r);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        calculation(cas);
    }
    return 0;
}

unsigned long long nCr(int n, int r)
{
    int maxm , minm ;
    ans = 1 , ans2 = 1 ;

    maxm = max(r,n-r);
    minm = min(r,n-r);

    for(int i=maxm+1 ; i<=n ; i++)
        ans *= i ;

    for(int i=2 ; i<=minm ; i++)
        ans2 *= i;

    ans = ans/ans2 ;
}

void calculation(int cas)
{
    int n , k ;

    scanf("%d %d",&n,&k);

    if(k==0)
        ans = 1;

    else if(k>n)
        ans = 0 ;

    else
    {
        nCr(n,k);

        ans2 = 1 ;

        for(int i=n ; i>(n-k) ; i--)
            ans2 *= i ;

        ans = ans*ans2;
    }

    printf("Case %d: %llu\n",cas,ans);
}
