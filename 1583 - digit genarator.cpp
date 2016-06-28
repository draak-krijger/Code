#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , number , bac , i , l ;
    bool check ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&number);
        check = false ;

        bac = number ;
        i = 0 ;

        while(bac>0)
        {
            i++;
            bac = bac/10;
        }

        bac = number - (i*9) ;

        for(i=bac ; i<number ; i++)
        {
            bac = i ;
            l = 0 ;

            while(bac>0)
            {
                l += bac%10 ;
                bac = bac/10;
            }

            if(i+l == number)
            {
                check = true ;
                break;
            }
        }

        if(check)
            printf("%d\n",i);

        else
            printf("0\n");
    }
    return 0 ;
}
