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

using namespace std;

void nck(int n , int k);

int main()
{
    int n , c ;

    while(scanf("%d %d",&n,&c) && (n||c))
        nck(n,c);

    return 0 ;
}

void nck(int n , int k)
{
    long long unsigned result ;

    if(k>(n/2))
        k = n - k ;

    result = 1 ;

    for(int i = 0 ; i<k ; i++)
    {
        result *= (n-i);

        result = result/(1+i) ;
    }

    printf("%llu\n",result);
}
