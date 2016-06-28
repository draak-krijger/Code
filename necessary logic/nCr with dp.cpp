// nCr using dp
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
#define sz 100

using namespace std ;

unsigned long long ncr[sz][sz] ;

unsigned long long nCr(int n , int r);

int main()
{
    int n , r  ;

    while(scanf("%d %d",&n,&r) != EOF)
    {
        printf("%llu\n",nCr(n,r));
    }

    return 0;
}

unsigned long long nCr(int n , int r)
{
    if(r == 1)
        return n;

    if(n == r)
        return 1 ;

    if(!ncr[n][r])
    {
        ncr[n][r] = nCr(n-1,r)+nCr(n-1,r-1) ;
        return ncr[n][r];
    }

    else
        return ncr[n][r] ;
}
