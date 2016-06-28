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

int egg , n , p , q ;

void INPUT(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        INPUT(cas);
    }

    return 0 ;
}

void INPUT(int cas)
{
    scanf("%d %d %d",&n,&p,&q);
    int cont = 0 , wt = 0 ;

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&egg);

        if(i<p && (wt+egg)<=q)
        {
            cont++;
            wt += egg;
        }
    }
    printf("Case %d: %d\n",cas,cont);
}
