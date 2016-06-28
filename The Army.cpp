#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std ;
int maxi[1000000] , order;

int main()
{
    int tcase , n , m , i , j , l , k , mam , mnm ;
    bool check1 , check2 ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&n,&m);

        mam = 0 ;
        mnm = 1000000;

        for(i=0 ; i<m ; i++)
        {
            scanf("%d",&order);

            if(order>mam)
                mam = order;

            if(order<mnm)
                mnm = order;
        }

        check1 = check2 = true ;

        for(i=0 ; i<n ; i++)
        {

            if(mam>=mnm)
                maxi[i] =mam;

            else
                maxi[i] = mnm;

            if(mam==0)
                check1=false;

            if(mnm==0)
                check2 = false;

            if(mam>0 && check1)
                mam--;

            if(mnm >0 && check2)
                mnm--;

            if(!check1)
                mam++;

            if(!check2)
                mnm++;

            printf("%d ",maxi[i]);
        }

        printf("\n");
    }
    return 0 ;
}
