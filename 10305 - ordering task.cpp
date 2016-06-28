#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std ;

int main()
{
    vector<int>edge[100000] ;
    queue<int>q , s ;
    int ind[150] , i , j , tcase , edg , x , y , n ;

    while(scanf("%d %d",&tcase,&edg) == 2)
    {
        if(tcase == 0 && edg == 0)
            return 0 ;

        memset(ind , 0 , sizeof ind);

        for(i=0 ; i<=112 ; i++)
            edge[i].clear();

        for(i=0 ; i<edg ; i++)
        {
            scanf("%d %d",&x,&y);
            ind[y]++;
            edge[x].push_back(y);
        }

        for(i=1 ; i<=tcase ; i++)
        {
            if(ind[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            n = q.front();
            q.pop();
            s.push(n);

            for(i=0 ; i<edge[n].size() ; i++)
            {
                j = edge[n][i] ;
                ind[j]--;

                if(ind[j] == 0)
                    q.push(j) ;
            }
        }

        while(!s.empty())
        {
            printf("%d",s.front());
            s.pop();

            if(!s.empty())
                printf(" ");
        }

        printf("\n");
    }
    return 0 ;
}
