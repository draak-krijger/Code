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
#define jora pair<int,int>
#define pb push_back
#define sz 105

using namespace std ;

int diamond[2*sz][sz] , n;
long long level[2*sz][sz]  ;

void calculation(int cas);
void reset();
void input();
void bfs();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void reset()
{
    for(int i=0 ; i<2*n-1 ; i++)
    {
        if(i<n)
        {
            for(int j=0 ; j<=i ; j++)
                level[i][j] = -1 ;
        }

        else
        {
            for(int j=0 ; j<(2*n-i-1) ; j++)
                level[i][j] = -1 ;
        }
    }
}

void input()
{
    scanf("%d",&n);

    for(int i=0 ; i<2*n-1 ; i++)
    {
        if(i<n)
        {
            for(int j=0 ; j<=i ; j++)
                scanf("%d",&diamond[i][j]);
        }

        else
        {
            for(int j=0 ; j<(2*n-i-1) ; j++)
                scanf("%d",&diamond[i][j]);
        }
    }
}

void bfs()
{
    level[0][0] = diamond[0][0];

    for(int i=0 ; i<2*n-2 ; i++)
    {
        if(i<n-1)
        {
            for(int j=0 ; j<=i ; j++)
            {
                if(level[i][j]+diamond[i+1][j]>level[i+1][j])
                    level[i+1][j] = level[i][j] + diamond[i+1][j];

                if(level[i][j]+diamond[i+1][j+1]>level[i+1][j+1])
                    level[i+1][j+1] = level[i][j] + diamond[i+1][j+1] ;
            }
        }

        else
        {
            for(int j=0 ; j<(2*n-i-1) ; j++)
            {
                if(j<(2*n-i-2))
                {
                    if(level[i][j]+diamond[i+1][j]>level[i+1][j])
                        level[i+1][j] = level[i][j] + diamond[i+1][j] ;
                }

                if(j>0)
                {
                    if(level[i][j]+diamond[i+1][j-1]>level[i+1][j-1])
                        level[i+1][j-1] = level[i][j] + diamond[i+1][j-1] ;
                }
            }
        }
    }
}

void calculation(int cas)
{
    reset();
    bfs();

    printf("Case %d: %lld\n",cas,level[2*n-2][0]);
}
