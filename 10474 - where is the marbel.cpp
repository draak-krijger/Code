#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;
bool found ;

int main()
{
    int mar , tcase , i , j = 0 , middle , first , last , search ;

    while(scanf("%d %d",&mar,&tcase) != EOF)
    {
        if(mar==0 && tcase==0)
            return 0 ;

        int b[mar];

        for(i=0 ; i<mar ; i++)
            scanf("%d",&b[i]);

        sort(b , b+mar);
        printf("CASE# %d:\n",++j);

        while(tcase--)
        {
            scanf("%d",&search);
            found = false ;

            for(i=0 ; i<mar ; i++)
            {
                if(b[i] == search)
                {
                        found = true ;
                        printf("%d found at %d\n",search,i+1);
                        break ;
                }

                else if(b[i]>search)
                    break;
            }

            if(!found)
                printf("%d not found\n",search);
        }
    }
    return 0 ;
}

