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

using namespace std;

bool primes[1020];
int num[1020];

void set_num();

int main()
{
    int a , cas = 0 ;
    set_num();

    while(scanf("%d",&a) != EOF && a)
    {
        if(a==1)
        {
            printf("Case %d: 1\n",++cas);
            continue;
        }

        if(primes[a-1])
        {
            printf("Case %d: %d\n",++cas,a-1);
            continue;
        }

        if(num[a])
        {
            printf("Case %d: %d\n",++cas,num[a]);
            continue;
        }

        printf("Case %d: -1\n",++cas);
    }
    return 0 ;
}

void set_num()
{
    num[1] = 1 ;
    int sum , l , x ;
    bool check ;

    for(int i=0 ; i<=1010 ; i++)
    {
        primes[i] = true;
        num[i] = 0 ;
    }

    primes[1] = false;
    primes[0] = false;

    for(int i = 4 ; i<=1010 ; i++)
    {
        x = sqrt(i);
        sum=0 ;
        check = false;

        for(int j =1 ; j<=x ; j++)
        {
            if(i%j == 0)
            {
                check = true;
                l = i/j ;

                if(l == j)
                {
                    sum += l ;
                    continue;
                }

                sum = sum + j + l ;
            }
        }

        if(check)
            primes[i] = false;

        if(sum<=1010)
            num[sum] = i ;
    }
}

