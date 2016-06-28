/*
ID: mohamma107
LANG: C
TASK: milk2
*/

#include <stdio.h>
int main()
{
    int a ;

    //freopen("milk2.in","r",stdin);
    //freopen("milk2.out","w",stdout);

    while(scanf("%d",&a) != EOF)
    {

        int time[a][2] , i, j ,k , longtime[a] , offtime[a] , b , l ;

        for(i=0 ; i<a ; i++ )
        {

            for(j=0 ; j<2 ; j++)
                scanf("%d",&time[i][j]) ;

            longtime[i] = offtime[i] = 0 ;
        }

        b = time[0][0] ;
        k = 0 ;

        for(i=0 ;i <a ;i++)
        {

            if(i == a-1)
            {
                longtime[k]=time[i][1] - b ;
                offtime[k] = 0 ;
                continue ;
            }

           if(time[i][1]<time[i+1][0])
           {
               longtime[k] = time[i][1] -  b;
               offtime[k] = time[i+1][0] - time[i][1] ;
               b = time[i+1][0] ;
               k++ ;
           }

           if(time[i][0] > time[i+1][0])
                b = time[i+1][0] ;
        }

        b = longtime[0] ;
        j = offtime[0] ;

         for(i=1 ;i <= k ;i++)
         {

             if(b<longtime[i])
                b = longtime[i] ;

             if(j<offtime[i])
                j = offtime[i] ;
         }

         printf("%d %d\n", b , j );

    }

    return 0 ;
}

