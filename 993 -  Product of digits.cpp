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

long long int a ;
int l , prim[] = {2,3,5,7} , s[100] ;

void calres();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%lld",&a);
        calres();
    }
    return 0 ;
}

void calres()
{
    long long int b ;
    l = 0 ;
    b = a ;

    if(b<10)
    {
        printf("%lld\n",b);
        return;
    }

    for(int i=9 ; i>1 ; i--)
    {
        if(b%i == 0)
        {
            while(b%i == 0)
            {
                b = b/i;
                s[l++] = i ;
            }
        }
    }

    if(b == 1)
    {
        for(int i=l-1 ; i>=0 ; i--)
        {
            printf("%d",s[i]);
        }
        printf("\n");
    }

    else
        printf("-1\n");
}
