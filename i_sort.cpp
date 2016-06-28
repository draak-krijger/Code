#include <bits/stdc++.h>

using namespace std ;

int n , arr[1000] ;

void i_sort()
{
    for(int i=1 ; i<n ; i++)
    {
        int temp = arr[i] ;

        int j = i - 1 ;

        while(j>=0 and arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp ;
    }
}

int main()
{
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
        scanf("%d",&arr[i]);

    i_sort();

    printf("\Sorted data\n");

    for(int i=0 ; i<n ; i++)
        printf("%d\n",arr[i]);

    return 0;
}
