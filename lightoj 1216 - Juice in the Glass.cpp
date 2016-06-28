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
#define pi acos(-1)

using namespace std ;

int r1 , r2 , h , p ;
double r3 , v ;

void input();
void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }

    return 0 ;
}

void input()
{
    scanf("%d %d %d %d",&r1,&r2,&h,&p);
}

void calculation(int cas)
{
    r3 = ((double)((r1-r2)*p)/(double)h) + (double)r2 ;

    v = (pi*(double)p*((r3*r3) + (r3*(double)r2) + (double)(r2*r2)))/3.0 ;

    printf("Case %d: %.6lf\n",cas,v);
}
