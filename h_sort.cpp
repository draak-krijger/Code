#include <bits/stdc++.h>

using namespace std ;

int arr[1000] , n ;

void hfy(int l,int r)
{
    int temp , k = 2*l ;
    temp = arr[l] ;

    while(k<=r)
    {
        if(k<r and arr[k+1]>arr[k])
            k++;

        if(temp>arr[k])
            break;

        arr[k/2] = arr[k] ;
        k = k*2 ;
    }

    arr[k/2] = temp ;
}

void h_sort()
{
    for(int i=n ; i>1 ; i--)
    {
        swap(arr[i],arr[1]);
        hfy(1,i-1);
    }
}

int main()
{
    scanf("%d",&n);

    for(int i=1 ; i<=n ; i++)
        scanf("%d",&arr[i]);

    for(int i=n/2 ; i>=1 ; i--)
        hfy(i,n);

    h_sort();

    printf("\nSorted Data\n");

    for(int i=1 ; i<=n ; i++)
        printf("%d\n",arr[i]);

    return 0;
}
