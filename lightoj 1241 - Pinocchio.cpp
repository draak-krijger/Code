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

int nose[50] , n ;

void Input(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        Input(cas);
    }
    return 0 ;
}

void Input(int cas)
{
    int cont = 0 ;

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&nose[i]);

        if(i>0)
        {
            if(nose[i]>nose[i-1])
                cont += ceil((double)(nose[i] - nose[i-1])/5.0);
        }

        else
        {
            cont += ceil((double)(nose[i] - 2)/5.0);
        }
    }

    printf("Case %d: %d\n",cas,cont);
}
