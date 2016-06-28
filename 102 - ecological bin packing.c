#include <stdio.h>
int main()
{
    long long  ara[9] , ara2[9] , a , i , j ,l;

    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&ara[6],&ara[7],&ara[8]) != EOF )
    {

        ara2[0]=ara[3] + ara[6]+ara[2] + ara[8]+ara[1] + ara[4];
        ara2[1]=ara[3] + ara[6]+ara[2] + ara[1] +ara[5]+ara[7];
        ara2[2]=ara[6]+ara[8]+ara[1] + ara[4]+ara[0]+ara[5];
        ara2[3]= ara[3] +ara[8]+ara[1] + ara[0]+ara[5]+ara[7];
        ara2[4]= ara[6]+ara[2]+ara[4]+ara[0]+ara[5]+ara[7];
        ara2[5]=ara[3]+ara[2] + ara[8]+ara[4]+ara[0]+ara[7];

        a=ara2[0];
        j=0 ;

        for(i=1 ; i<6 ; i++)
        {
            if(ara2[i]<a)
            {
                a=ara2[i] ;
                j = i ;
            }
        }

        if(j==0)
            printf("BCG %lld\n",a) ;

        else if(j==1)
            printf("BGC %lld\n",a) ;

        else if(j==2)
            printf("CBG %lld\n",a) ;

        else if(j==3)
            printf("CGB %lld\n",a) ;

        else if(j==4)
            printf("GBC %lld\n",a) ;

        else if(j==5)
            printf("GCB %lld\n",a) ;
    }
    return 0 ;
}
