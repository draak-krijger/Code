#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , i , j , k , l ;
    bool check ;

    scanf("%d",&tcase);

    for(i=0 ; i<tcase ; i++)
    {
        scanf("%d",&k);

        j = 2 ;
        l = k ;
        check = false ;

        printf("Case #%d: %d = ",i+1,k);

        while(j<l)
        {
            if(k%j == 0)
            {
                if(!check)
                {
                    printf("%d * %d = ",j,k/j);
                    l = k/j ;
                    check = true ;
                }

                else
                {
                    printf("%d * %d\n",j,k/j);
                    break;
                }
            }
            j++;
        }
    }
    return 0 ;
}
