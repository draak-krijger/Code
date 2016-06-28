/*
ID: mohamma107
LANG: C++
TASK: milk2
*/
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

struct farmerstime
{
    int start , stop ;
};

bool cmp(farmerstime p , farmerstime q);

int main()
{
    int tcase , contint , stopt , a , b ;
    farmerstime collecttime[6000];

    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);

    while(scanf("%d",&tcase) != EOF)
    {
        for(int i=0 ; i<tcase ; i++)
        {
            scanf("%d %d",&collecttime[i].start,&collecttime[i].stop);
        }

        sort(collecttime , collecttime+tcase , cmp);
        contint = stopt = 0 ;

        a = collecttime[0].start;
        b = collecttime[0].stop;

        for(int i=1 ; i<tcase ; i++)
        {
            if(collecttime[i].start>b)
            {
                if((b-a)>contint)
                    contint = b-a ;

                if((collecttime[i].start-b)>stopt)
                    stopt = collecttime[i].start - b ;

                a = collecttime[i].start;
            }

            if(collecttime[i].stop>b)
                b = collecttime[i].stop;
        }

        if((b-a)>contint)
            contint = b-a ;

        printf("%d %d\n",contint,stopt);
    }

    return 0 ;
}

bool cmp(farmerstime p , farmerstime q)
{
    if(p.start<q.start)
        return true;

    return false;
}
