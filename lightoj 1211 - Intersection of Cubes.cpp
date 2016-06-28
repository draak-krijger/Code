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

struct point
{
    int sx,sy,sz,ox,oy,oz ;
};

point takepoint[110] , finalpoint ;
int n ;

void reset();
void inpcal(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        inpcal(cas);
    }

    return 0 ;
}

void reset()
{
    finalpoint.sx = 0 ;
    finalpoint.sy = 0 ;
    finalpoint.sz = 0 ;
    finalpoint.ox = 10000 ;
    finalpoint.oy = 10000 ;
    finalpoint.oz = 10000 ;
}

void inpcal(int cas)
{
    long long int ans ;
    reset();

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d %d %d %d %d %d",&takepoint[i].sx,&takepoint[i].sy,&takepoint[i].sz,&takepoint[i].ox,&takepoint[i].oy,&takepoint[i].oz);

        finalpoint.sx = max(finalpoint.sx,takepoint[i].sx) ;
        finalpoint.sy = max(finalpoint.sy,takepoint[i].sy) ;
        finalpoint.sz = max(finalpoint.sz,takepoint[i].sz) ;
        finalpoint.ox = min(finalpoint.ox,takepoint[i].ox) ;
        finalpoint.oy = min(finalpoint.oy,takepoint[i].oy) ;
        finalpoint.oz = min(finalpoint.oz,takepoint[i].oz) ;
    }

    ans = (finalpoint.ox - finalpoint.sx) * (finalpoint.oy - finalpoint.sy) * (finalpoint.oz - finalpoint.sz) ;

    if(ans<0)
        ans = 0 ;

    printf("Case %d: %lld\n",cas,ans);
}
