#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , trt , balan , i , a , j = 0;

    while(scanf("%d",&tcase) != EOF)
    {
        if(tcase == 0)
            return 0 ;

        trt = balan = 0 ;

        for(i=0 ; i<tcase ; i++ )
        {
            scanf("%d",&a);

            if(a==0)
                balan++;

            else
                trt++;
        }

        printf("Case %d: %d\n",++j,trt-balan);
    }
    return 0 ;
}
