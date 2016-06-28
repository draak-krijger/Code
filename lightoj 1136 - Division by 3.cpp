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

long long int a , b ;

void kapjap(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lld %lld",&a,&b);
        kapjap(cas);
    }
    return 0 ;
}

void kapjap(int cas)
{
    long long int diff , x , y ;

    diff = b-a ;

    x = ceil((double)(a+2)/3.0);
    y = floor((double)(b+2)/3.0);

    diff -= (y-x) ;

    printf("Case %d: %lld\n",cas,diff);
}
