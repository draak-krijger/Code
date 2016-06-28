#include <stdio.h>

int bubble(int a[], int b)
{
    int i , j , temp , k =0 ;

    for(i=0 ; i<b-1 ;i++)
    {
        for(j=0 ; j<b-i-1 ; j++)
        {
            if(a[j+1]<a[j])
            {
                k++;
                temp = a[j] ;
                a[j] = a[j+1];
                a[j+1] = temp ;
            }
        }
    }

    return k ;
}

int main()
{
    int a , t , s[10000] , i ;

    while(scanf("%d",&t) != EOF)
    {
        for(i=0 ; i<t ; i++)
        {
            scanf("%d",&s[i]);
        }

        printf("Minimum exchange operations : %d\n",bubble(s,t));
    }
    return 0 ;
}

