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

long long int all[100];

void cal();

int main()
{
    cal();
    int n ;

    while(scanf("%d",&n) != EOF)
    {
        if(n == -1)
            break;

        if(n==0)
            printf("0 1\n");

        else
            printf("%lld %lld\n",all[n-1],all[n]);
    }
    return 0 ;
}

void cal()
{
    all[0] = 1 ;
    all[1] = 2 ;
    all[2] = 4 ;

    for(int i=3 ;i<=44; i++)
    {
        all[i] = all[i-1] + all[i-2] + 1 ;
    }
}
