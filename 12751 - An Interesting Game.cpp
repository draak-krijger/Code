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

int main()
{
    int tcase , n , k , x , start , ends , all ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d",&n,&k,&x);

        all = (n*(n+1))/2 ;
        start = (x*(x-1))/2;
        k = k+x ;
        ends = (k*(k-1))/2;
        all = all - (ends-start);

        printf("Case %d: %d\n",cas,all);
    }
    return 0 ;
}
