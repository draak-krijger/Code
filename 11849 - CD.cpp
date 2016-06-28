#include <iostream>
#include <cstdio>

using namespace std ;

int num1[100000100] , num2[100000100];

int main()
{
    int a , b , i , j , sum , l ;

    while(scanf("%d %d",&a,&b) != EOF)
    {
        if(!a && !b)
            return 0 ;

        sum = 0 ;

        for(i=0 ; i<a ; i++)
            scanf("%d",&num1[i]);

        for(i=0 ; i<b ; i++)
            scanf("%d",&num2[i]);

        l=0;

        for(i=0 ; i<a ; i++)
        {
            for(l ; l<b ; l++)
            {
                if(num1[i] == num2[l])
                {
                    sum++;
                    break;
                }

                if(num2[l] > num1[i])
                    break;
            }

            if(l==b-1)
                break;

        }

        printf("%d\n",sum);
    }

    return 0 ;
}
