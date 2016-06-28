#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std ;

vector<int>arr ;

int main()
{
    int tcase , m , n , temp , a , b ;
    char command[5];

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&m ,&n);
        arr.clear();

        for(int i=1 ; i<=m ; i++)
        {
            scanf("%d",&a);
            arr.push_back(a);
        }

        for(int i=1 ; i<=n ; i++)
        {
            getchar();
            scanf("%s",&command);

            if(command[0] == 'P')
            {
                scanf("%d %d",&a,&b);

                swap(arr[a],arr[b]);
            }

            if(command[0] == 'S')
            {
                scanf("%d",&a);

                for(int j=0 ; j<arr.size() ; j++)
                    arr[j] = arr[j] + a ;
            }

            if(command[0] == 'M')
            {
                scanf("%d",&a);

                for(int j=0 ; j<arr.size() ; j++)
                    arr[j] = arr[j] * a ;
            }

            if(command[0] == 'D')
            {
                scanf("%d",&a);

                for(int j=0 ; j<arr.size() ; j++)
                    arr[j] = arr[j]/a ;
            }

            if(command[0] == 'R')
            {
                reverse(arr.begin(),arr.end());
            }
        }

        printf("Case %d:\n%d",cas,arr[0]);

        for(int j=1 ; j<arr.size() ; j++)
            printf(" %d",arr[j]);

        printf("\n");
    }
    return 0 ;
}
