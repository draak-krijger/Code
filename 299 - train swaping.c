#include <stdio.h>
int  swap(int length[],int a)
{
    int i , j , k , l=0 ;
    for(i=0 ; i<a-1 ; i++)
    {
        for(j=0 ; j<a-i-1 ; j++)
        {
            if(length[j]>length[j+1])
            {
                l++;
                k = length[j];
                length[j]=length[j+1];
                length[j+1]=k;
            }
        }
    }
    return l;
}
int main()
{
    int a , b , j , i;
    while(scanf("%d",&a) == 1)
    {
        for(j=0 ; j<a ; j++)
        {
            scanf("%d",&b) != EOF;
            int d[b];
            for(i=0 ; i< b ; i++)
            {
                scanf("%d",&d[i]) != EOF;
            }
            printf("Optimal train swapping takes %d swaps.\n",swap(d,b));
        }
    }
    return 0;
}
