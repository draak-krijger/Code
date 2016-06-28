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

set<int>number;

int main()
{
    int n , r , a ;

    while(scanf("%d %d",&n,&r) != EOF)
    {
        number.clear();

        for(int i=1 ; i<=n ; i++)
            number.insert(i);

        for(int i=0 ; i<r ; i++)
        {
            scanf("%d",&a);
            number.erase(number.find(a));
        }

        if(number.empty())
        {
            printf("*\n");
            continue;
        }

        for(typeof(number.begin()) it = number.begin() ; it!=number.end() ; it++)
        {
            a = *it ;
            printf("%d ",a);
        }

        printf("\n");
    }
    return 0;
}
