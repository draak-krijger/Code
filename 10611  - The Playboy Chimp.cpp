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

int height[51000] ;
set<int>p ;

int main()
{
    int n , m , a , first , last , midle , lh , hh ;
    bool check ;

    scanf("%d",&n);
    p.clear();

    for(int i = 0 ; i<n ; i++)
    {
        scanf("%d",&a);
        p.insert(a);
    }

    n = 0;

    for(typeof(p.begin()) it = p.begin() ; it!=p.end() ; ++it)
    {
        height[n++] = *it ;
    }

    scanf("%d",&m);

    for(int cas=1 ; cas<=m ; cas++)
    {
        scanf("%d",&a);

        if(a>=height[n-1])
        {
            if(a == height[n-1])
                printf("%d X\n",height[n-2]);

            else
                printf("%d X\n",height[n-1]);

            continue;
        }

        if(a<=height[0])
        {
            if(a == height[0])
                printf("X %d\n",height[1]);

            else
                printf("X %d\n",height[0]);

            continue;
        }

        first = 0 ;
        last = n ;
        check = false;

        while(first<=last)
        {
            midle = (first+last)/2 ;

            if(a>height[midle])
                first = midle + 1 ;

            else if(a<height[midle])
                last = midle - 1 ;

            else
            {
                if(a == height[midle])
                    check = true;

                break;
            }
        }

        if(check)
            printf("%d %d\n",height[midle-1],height[midle+1]);

        else
        {
            if(a>height[midle])
                printf("%d %d\n",height[midle],height[midle+1]);

            else
                printf("%d %d\n",height[midle-1],height[midle]);
        }
    }
    return 0 ;
}
