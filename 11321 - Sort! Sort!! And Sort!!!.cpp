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
#define Max 11000

using namespace std ;

int n , m , arra[Max] ;

void INPUT();
bool cmp(int p , int q);
void OUTPUT();

int main()
{
    while(scanf("%d %d",&n,&m) != EOF)
    {
        printf("%d %d\n",n,m);

        if(!n && !m)
            return 0 ;

        INPUT();
        OUTPUT();
    }
    return 0 ;
}

bool cmp(int p , int q)
{
    int a , b ;
    a = p%m ;
    b = q%m ;

    if(a<b)
        return true;

    if(a==b)
    {
        if((p&1) && !(q&1))
            return true;

        else if(!(p&1) && (q&1))
            return false;

        else if((p&1) && (q&1))
        {
            if(p>q)
                return true;

            else
                return false;
        }

        else
        {
            if(p<q)
                return true;

            else
                return false;
        }
    }

    return false;
}

void INPUT()
{
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&arra[i]);
    }
}

void OUTPUT()
{
    sort(arra,arra+n,cmp);

    for(int i=0 ; i<n ; i++)
        printf("%d\n",arra[i]);
}
