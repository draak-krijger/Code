#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int a , d , i , j , num ;

    while(scanf("%d %d",&a,&d) == 2)
    {
        i=0 ;

        while(1)
        {
            num = a/d ;

            if(i==0)
                printf("[%d;",num);

            else if(i==1)
                printf("%d",num);

            else
                printf(",%d",num);

            a = a - (num*d) ;
            swap(a,d);

            if(d == 0)
            {
                printf("]\n");
                break;
            }
            i++;
        }
    }
    return 0 ;
}
