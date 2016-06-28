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

int s1[100] ;
long long int a , b , c , d , e , f , g , h ;

long long dtob(long long p);

int main()
{
    int tcase ;
    char ch ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lld %c %lld %c %lld %c %lld",&a,&ch,&b,&ch,&c,&ch,&d);
        a = dtob(a);
        b = dtob(b);
        c = dtob(c);
        d = dtob(d);

        scanf("%lld %c %lld %c %lld %c %lld",&e,&ch,&f,&ch,&g,&ch,&h);

        if((a == e) && (b == f) && (c == g) && (d == h))
            printf("Case %d: Yes\n",cas);

        else
            printf("Case %d: No\n",cas);
    }

    return 0 ;
}

long long dtob(long long p)
{
    int l = -1 ;
    long long s = 0 ;

    while(p)
    {
        s1[++l] = p%2 ;
        p = p/2;
    }

    for(int i=l ; i>=0 ; i--)
        s = s*10 + s1[i] ;

    return s ;
}
