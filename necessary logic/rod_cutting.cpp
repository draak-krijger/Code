// rod cutting algorithm
#include <bits/stdc++.h>

using namespace std ;

int cut_road(int price[] , int n);

int main()
{
    int price[100] , n ;

    while(scanf("%d",&n) != EOF)
    {
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&price[i]);
        }

        printf("%d\n",cut_road(price,n));
    }
    return 0;
}


int cut_road(int price[] , int n)
{
    int val[n+1];
    val[0] = 0 ;

    for(int i=1 ; i<=n ; i++)
    {
        int cst = INT_MIN ;
        for(int j=0 ; j<i ; j++)
        {
            cst = max(cst,price[j]+val[i-j-1]);
        }
        val[i] = cst ;
    }

    return val[n] ;
}
