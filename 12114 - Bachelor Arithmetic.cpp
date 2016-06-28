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

long long int b , s ;

void calculation(int cas);

int main()
{
    int cas=0;

    while(scanf("%lld %lld",&b,&s) != EOF && (b||s))
    {
        calculation(++cas);
    }
    return 0 ;
}

void calculation(int cas)
{
    if(b== 1 || b==0)
        printf("Case %d: :-\\\n",cas);

    else if(s>=b)
            printf("Case %d: :-|\n",cas);

    else
            printf("Case %d: :-(\n",cas);
}
