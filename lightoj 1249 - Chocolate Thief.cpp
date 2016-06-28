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

struct details
{
    char s[20] ;
    long long int area ;
};

details studen[110] ;
int n ;

void input();
bool cmp(details p ,details q);
void result(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        result(cas);
    }
    return 0 ;
}

void input()
{
    int a , b , c ;

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        scanf("%s %d %d %d",studen[i].s,&a,&b,&c);

        studen[i].area = a*b*c ;
    }
}

bool cmp(details p , details q)
{
    if(p.area > q.area)
        return true;

    return false;
}

void result(int cas)
{
    sort(studen,studen+n,cmp);

    if(studen[0].area == studen[n-1].area)
        printf("Case %d: no thief\n",cas);

    else if(studen[0].area>studen[n-1].area)
        printf("Case %d: %s took chocolate from %s\n",cas,studen[0].s,studen[n-1].s);
}
