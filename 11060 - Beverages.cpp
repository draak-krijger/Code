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

map<string,int>matrix;
vector<int>graph[300] ;
char name[300][100] ;
int n , indegree[300] , taken[300] ;
queue<int>result;

void reset();
void Input();
void tpsort();
void output();

int main()
{
    int m , l , cas = 0 ;

    while(scanf("%d",&n) != EOF)
    {
        reset();
        Input();
        tpsort();

        printf("Case #%d: Dilbert should drink beverages in this order:",++cas);
        output();
        printf(".\n\n");
    }
    return 0 ;
}

void reset()
{
    for(int i = 0 ; i<=(n+10) ; i++)
    {
        graph[i].clear();
        indegree[i] = 0 ;
        taken[i] = 0 ;
    }
    matrix.clear();
}

void Input()
{
    int m ;
    char s1[100] , s2[100] ;

    for(int i = 1 ; i<=n ; i++)
    {
        scanf("%s",s1);
        matrix[s1] = i ;
        strcpy(name[i],s1);
    }

    scanf("%d",&m);

    for(int i=1 ; i<=m ; i++)
    {
        scanf("%s %s",s1,s2);

        indegree[matrix[s2]]++;
        graph[matrix[s1]].push_back(matrix[s2]);
    }
}

void tpsort()
{
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if(!indegree[j] && !taken[j])
            {
                taken[j] = 1 ;
                result.push(j);

                for(int k=0 ; k<graph[j].size() ; k++)
                {
                    indegree[graph[j][k]]--;
                }
                break;
            }
        }
    }
}

void output()
{
    int l ;
    while(!result.empty())
    {
        l = result.front();
        printf(" %s",name[l]);
        result.pop();
    }
}
