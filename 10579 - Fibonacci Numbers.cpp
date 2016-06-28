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

int fib[5010][1050];

void fibonacci()
{
    fib[0][0] = 0 ;
    fib[1][0] = 1 ;
    fib[2][0] = 1 ;

    for(int i=3 ; i<=5008 ; i++)
    {
        for(int j=0 ; j<=1049 ; j++)
        {
            fib[i][j] += fib[i-1][j]+fib[i-2][j] ;

            if(fib[i][j]>=10)
            {
                fib[i][j+1] = fib[i][j]/10;
                fib[i][j] = fib[i][j]%10 ;
            }
        }
    }
}

int main()
{
    int a ;
    fibonacci();

    while(scanf("%d",&a) != EOF)
    {
        int i ;

        for(i=1049 ; i>=0 ; i--)
        {
            if(fib[a][i] != 0)
                break;
        }

        for(;i>=0 ; i--)
            printf("%d",fib[a][i]);

        printf("\n");
    }
    return 0 ;
}
