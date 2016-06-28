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

long long int grid[150][150];

void cal(long long int n ,long long int k);

int main()
{
    long long int cas = 0 ;
    long long a ;

    while(scanf("%lld",&a) == 1 && a)
    {
        cas++;

        for(int i=0 ; i<a ; i++)
        {
            for(int j=0 ; j<a ; j++)
                scanf("%lld",&grid[i][j]);
        }

        long long int k = 0 ;
        printf("Case %lld:",cas);

        while((a-k) )
        {
            cal((a-k),k);
            k++;

            if(k == ceil((double)a/2.0))
                break;
        }
        printf("\n");
    }
    return 0 ;
}

void cal(long long int n ,long long int k)
{
    long long int sum = 0 ;

    for(long long int i=k ; i<n ; i++)
    {
        if(i==k || i==n-1)
        {
            for(long long int j=k ; j<n ; j++)
                sum += grid[i][j] ;
        }

        else
        {
            sum += grid[i][k];
            sum += grid[i][n-1];
        }
    }

    printf(" %lld",sum);
}
