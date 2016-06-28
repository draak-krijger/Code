#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std ;

char graph[1000][1000] , c ;
int m , n ;

void dfs(int i , int j)
{
    if(i<0 || i>=m || j<0 || j>=n || graph[i][j] != c )
        return ;

    graph[i][j] = '2';

    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i-1,j);
    dfs(i+1,j);
}
int main()
{
    int tcase , i , j , a[30] , b[30] , k , l=0 ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&m,&n);

        for(i=0 ; i<m ; i++)
            scanf("%s",&graph[i]);

        memset(a , 0 , sizeof a);
        memset(b , 0 , sizeof b);
        k=0 ;

        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
            {
                if(isalpha(graph[i][j]))
                {
                    k++;
                    c = graph[i][j] ;
                    a[graph[i][j] - 'a']++;
                    b[graph[i][j] - 'a']++;
                    dfs(i,j);
                }
            }
        }
        sort(a , a+26 , greater<int>());
        printf("World #%d\n",++l);
        for(i=0 ; i<k ; i++)
        {
            if(a[i]>0)
            {
                for(j=0 ; j <26 ; j++)
                {
                    if(a[i] == b[j])
                    {
                        printf("%c: %d\n",j+'a',a[i]);
                        b[j] = 0 ;
                    }
                }
            }
        }
    }
    return 0 ;
}

