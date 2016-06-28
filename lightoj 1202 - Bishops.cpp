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

long long int r1,c1,r2,c2 ;

void inpcalresult(int cas);

int main()
{
    int tcase;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        inpcalresult(cas);

    return 0 ;
}

void inpcalresult(int cas)
{
    scanf("%lld %lld %lld %lld",&r1,&c1,&r2,&c2);

    long long int r , c ;

    r = abs(r1-r2);
    c = abs(c1-c2);

    if(r == c)
        printf("Case %d: 1\n",cas);

    else if(1 & (r+c))
        printf("Case %d: impossible\n",cas);

    else
        printf("Case %d: 2\n",cas);
}

