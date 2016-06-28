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

char s[500] ;
long long int b , a ;

void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%s %lld",s,&b);
        calculation(cas);
    }
    return 0 ;
}

void calculation(int cas)
{
    a = 0 ;
    int i , length ;

    length = strlen(s);

    if(s[0] == '-')
    {
        i = 2 ;
        a = s[1] - '0' ;
    }

    else
    {
        i = 1 ;
        a = s[0] - '0' ;
    }

    for(i ; i<length ; i++)
    {
        a = a*10 + (s[i] - '0') ;
        a = a%b ;
    }

    if(!a)
        printf("Case %d: divisible\n",cas);

    else
        printf("Case %d: not divisible\n",cas);
}
