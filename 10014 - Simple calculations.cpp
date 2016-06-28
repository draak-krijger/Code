#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>

using namespace std ;

int main()
{
    int tcase , n ;
    double first , second , c[4000] , sum , ans ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %lf %lf",&n,&first,&second);

        sum = 0 ;

        for(int i=0 ; i<n ; i++)
        {
            scanf("%lf",&c[i]);
            sum += 2.0*(double)(n-i)*c[i] ;
        }
        ans = (n*first+second - sum)/(double)(n+1) ;

        printf("%.2lf\n",ans);

        if(tcase)
            printf("\n");
    }
    return 0 ;
}
