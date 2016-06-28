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

int n ;
unsigned long long int sum ;

void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d",&n);

        calculation(cas);
    }

    return 0 ;
}

void calculation(int cas)
{
    sum = 0 ;
    int k ;
    char s[100] ;

    printf("Case %d:\n",cas);

    while(n--)
    {
        scanf("%s",s);

        if(strcmp(s,"donate") == 0)
        {
            scanf("%d",&k) ;
            sum += k ;
        }

        else if(strcmp(s,"report") == 0)
            printf("%llu\n",sum);
    }
}
