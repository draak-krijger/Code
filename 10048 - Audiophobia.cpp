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
#define PB push_back

using namespace std;

int matrix[150][150] , n ;

void floyed_warshal();
void reset();

int main()
{
    int s , q , cas = 0 , a , b , w;
    bool check = false ;

    while(scanf("%d %d %d",&n,&s,&q) && (n&&s&&q))
    {
        reset();

        for(int i=0 ; i<s ; i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            matrix[a][b] = matrix[b][a] = w ;
        }

        floyed_warshal();

        if(check)
            printf("\n");

        check = true ;

        printf("Case #%d\n",++cas);
        for(int i=0 ; i<q ; i++)
        {
            scanf("%d %d",&a,&b);

            if(matrix[a][b] == INT_MAX)
            {
                printf("no path\n");
                continue;
            }

            printf("%d\n",matrix[a][b]);
        }
    }
    return 0 ;
}

void reset()
{
    for(int i = 0 ; i<=105 ; i++)
    {
        for(int j=0 ; j<=105 ; j++)
            matrix[i][j] = INT_MAX;
    }
}

void floyed_warshal()
{
    for(int k=1 ; k<=n ; k++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=n ; j++)
            {
                matrix[i][j] = matrix[j][i] = min(matrix[i][j],max(matrix[i][k],matrix[k][j]));
            }
        }
    }
}
