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
    int a , b , tcase ;
    double n , m , ans ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lf %lf %d %d",&n,&m,&a,&b);

        ans = (m*(double)(a+b) - n*(double)a)/(double)b ;

        if(ans>10 || ans<0)
        {
            printf("Case #%d: Impossible\n",cas);
            continue;
        }

        printf("Case #%d: %.2lf\n",cas,ans);
    }
    return 0 ;
}
