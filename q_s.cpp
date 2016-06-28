#include <bits/stdc++.h>

using namespace std ;

int arr[1000] ;

void q_sort(int l,int r)
{
    int indx1 = l , indx2 = r , privot = l ;

    if(indx1<indx2)
    {
        while(indx1<indx2)
        {
            while(arr[indx1]<=arr[privot] and indx1<indx2)
                indx1++;

            while(arr[indx2]>arr[privot])
                indx2--;

            if(indx1<indx2)
            {
                swap(arr[indx1],arr[indx2]);
            }
        }

        swap(arr[privot],arr[indx2]);

        q_sort(l,indx2-1);
        q_sort(indx2+1,r);
    }
}

int main()
{
    int n ;

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
        scanf("%d",&arr[i]);

    q_sort(0,n-1);

    printf("\nSorted Data:\n");

    for(int i=0 ; i<n ; i++)
        printf("%d\n",arr[i]);

    return 0 ;
}
