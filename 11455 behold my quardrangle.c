#include <stdio.h>

int bubble(long long int a[])
{
    int i , j , temp ;

    for(i=0 ; i<3 ;i++)
    {
        for(j=0 ; j<3-i ; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp ;
            }
        }
    }
}
int main()
{
    long long  int t , length[4] , i , j ;
    while(scanf("%lld",&t) != EOF)
    {
        while(t--)
        {
            for(i=0 ; i<4 ; i++)
            {
                scanf("%lld",&length[i]);
            }

            if(length[0]==length[1] && length[1]==length[2] && length[2] == length[3])
            {
                printf("square\n");
                continue;
            }
            bubble(length);

            if(length[0] == length[1] && length[2] == length[3])
                printf("rectangle\n");
            else if((length[0]+length[1]+length[2]) > length[3])
                printf("quadrangle\n");
            else
                printf("banana\n");
        }
    }
    return 0 ;
}

