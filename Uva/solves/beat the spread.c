#include <stdio.h>
int main()
{
    long int a , b , c , i , diff , big , small ;
    while(scanf("%ld",&a) == 1)
    {
        for(i=0 ; i<a ; i++)
        {
            scanf("%ld %ld",&b,&c) != EOF;
            if(c>b){
                printf("impossible\n");
                continue;
            }
            diff = b-c;
            if(diff%2 != 0)
            {
                printf("impossible\n");
                continue;
            }
            big = c +diff/2;
            small = b -big;
            printf("%ld %ld\n",big,small);
        }
    }
    return 0 ;
}

