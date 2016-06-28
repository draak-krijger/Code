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

bool isprime[40] ;
void seave();

int main()
{
    unsigned long long ans ;
    int n ;
    seave();

    while(scanf("%d",&n) != EOF && n)
    {
        if(n==11 || n==23 || n==29)
        {
            printf("Given number is prime. But, NO perfect number is available.\n");
            continue;
        }

        if(!isprime[n])
        {
            ans = pow(2.0,n-1)*(pow(2.0,n)-1);
            printf("Perfect: %llu!\n",ans);
        }

        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0 ;
}

void seave()
{
    isprime[1] = true;

    for(int i=4 ; i<=32 ; i += 2)
        isprime[i] = true;

    for(int i=3 ; i<=5 ; i += 2)
        for(int j= i+i ; j<=32 ; j += i)
            isprime[j] = true;
}
