#include <stdio.h>

int sorting(long long a[])
{
    int i , j , k ;
    for(i=0 ; i<2 ; i++)
    {
        for(j=0 ; j<2-i ;j++)
        {
            if(a[j]>a[j+1])
            {
                k = a[j];
                a[j] = a[j+1];
                a[j+1] = k;
            }
        }
    }
}
int main()
{
    int a , i , j ;
    long long length[3];
    scanf("%d",&a);
    for( i=0 ; i<a ; i++)
    {
        for(j=0 ; j<3 ; j++){
        scanf("%lld",&length[j]);}
        sorting(length);
        if((length[0]+length[1]) > length[2])
        {
            if(length[0] == length[1] && length[0] == length[2])
            {
                printf("Case %d: Equilateral\n",i+1);
            }
            else if(length[0] == length[1] || length[0] == length[2] || length[1]==length[2])
            {
                printf("Case %d: Isosceles\n",i+1);
            }
            else
                printf("Case %d: Scalene\n",i+1);
        }
        else
            printf("Case %d: Invalid\n",i+1);
    }
    return 0;
}

