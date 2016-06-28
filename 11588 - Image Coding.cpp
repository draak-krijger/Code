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

bool cmp(int p , int q);

int main()
{
    int tcase , r , c , m , n , num[50] , cost , cont ;
    char graph[50][50];

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d %d",&r,&c,&m,&n);

        cost = 0 ;

        for(int i = 0 ; i<=30 ; i++)
            num[i] = 0 ;

        for(int i = 0 ; i<r ; i++)
            scanf("%s",graph[i]);

        cont = 1;

        for(int i = 0 ; i<r ; i++)
        {
            for(int j = 0 ; j<c ; j++)
            {
                num[graph[i][j] - 'A']++;
            }
        }

        sort(num , num+28 , cmp);

        for(int i = 1 ; i<26 ; i++)
        {
            if(num[0] == num[i])
                cont++;

            else
                break;
        }

        cost = (num[0]*cont*m) + ((r*c) - (num[0]*cont))*n ;

        printf("Case %d: %d\n",cas,cost);
    }
    return 0 ;
}

bool cmp(int p , int q)
{
    return p>q ;
}
