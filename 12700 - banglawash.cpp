#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , numofmach , res[30] , i , j=0 ;
    char s[20];

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&numofmach);
        scanf("%s",s);
        memset(res , 0 , sizeof res );

        for(i=0 ; i<numofmach ; i++)
            res[s[i] - 'A']++ ;

        if(res[0] > 0){
            numofmach -= res[0] ;
        }

        if(numofmach == 0)
            printf("Case %d: ABANDONED\n",++j);

        else if(res[1] == numofmach)
            printf("Case %d: BANGLAWASH\n",++j);

        else if(res[22] == numofmach)
            printf("Case %d: WHITEWASH\n",++j);

        else if(res[1]>res[22])
            printf("Case %d: BANGLADESH %d - %d\n",++j,res[1],res[22]);

        else if(res[22]>res[1])
            printf("Case %d: WWW %d - %d\n",++j,res[22],res[1]);

        else if(res[1] == res[22])
            printf("Case %d: DRAW %d %d\n",++j,res[1],res[19]);

    }
    return 0 ;
}
