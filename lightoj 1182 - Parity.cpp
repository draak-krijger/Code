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
    int  n , cont , tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d",&n);

        cont = 0 ;

        while(n)
        {
            if(n&1)
                cont++;
            n = n/2;
        }

        if(cont&1)
            printf("Case %d: odd\n",cas);

        else
            printf("Case %d: even\n",cas);
    }
    return 0 ;
}
