#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , n , i , j , no , movement , mcost[150] , l ;
    char command[100];

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);
        getchar();

        memset(mcost,0,sizeof mcost);
        movement = 0 ;

        for(i=0 ; i<n ; i++)
        {
            gets(command);

            if(command[0] == 'L')
            {
                mcost[i] = -1 ;
                movement -= 1 ;
            }

            else if(command[0] == 'R')
            {
                mcost[i] = 1 ;
                movement += 1 ;
            }

            else if(command[0] == 'S')
            {
                l = strlen(command);
                no = 0 ;
                j = 8 ;

                while(j<l)
                {
                    no = no*10;
                    no = no + (command[j] - '0');
                    j++;
                }
                mcost[i] = mcost[no-1];
                movement += mcost[no-1];
            }
        }
        printf("%d\n",movement);

    }
    return 0 ;
}
