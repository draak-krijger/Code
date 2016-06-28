#include <iostream>
#include <cstdio>
#include <queue>

using namespace std ;

int main()
{
    int n , i , ara[500] , j ;
    queue<int>num ;

    while(scanf("%d",&n) != EOF)
    {
        if(!n)
            return 0 ;

        for(i=1 ; i<=n ; i++)
            num.push(i);

        i=0 ;

        while(1)
        {
            ara[i] = num.front();
            num.pop() ;
            i++;

            if(num.empty())
                break;

            num.push(num.front());
            num.pop();
        }

        printf("Discarded cards:");

        for(j=0 ; j<i-1 ; j++)
        {
            printf(" %d",ara[j]);

            if(j != i-2)
                printf(",");
        }

        printf("\nRemaining card: %d\n",ara[i-1]);
    }
    return 0 ;
}
