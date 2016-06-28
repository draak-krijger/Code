#include <bits/stdc++.h>

using namespace std ;

int arr[1000] ;

void merge(int l,int r)
{
    int mid , len1 , len2 ;
    mid = (l+r)/2 ;

    len1 = mid-l + 1 ;
    len2 = r-mid ;

    int lft[len1] , rgt[len2] ;

    for(int i=0 ; i<len1 ; i++)
        lft[i] = arr[l+i] ;

    for(int i=0 ; i<len2 ; i++)
        rgt[i] = arr[mid+i+1] ;

    int i=0 , j=0 , k=l ;

    while(i<len1 and j<len2)
    {
        if(lft[i]<rgt[j])
            arr[k++] = lft[i++] ;

        else
            arr[k++] = rgt[j++];
    }

    while(i<len1)
        arr[k++] = lft[i++];

    while(j<len2)
        arr[k++] = rgt[j++];

//    for(int i=l ; i<=r ; i++)
//        printf("%d ",arr[i]);
//    printf("\n");
}

void m_sort(int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2 ;

        m_sort(l,mid);
        m_sort(mid+1,r);
        merge(l,r);
    }
}

int main()
{
    int n ;

    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
        scanf("%d",&arr[i]);

    m_sort(0,n-1);

    printf("\nSorted Data:\n");

    for(int i=0 ; i<n ; i++)
        printf("%d\n",arr[i]);

    return 0;
}
