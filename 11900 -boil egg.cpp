#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std ;

int main()
{
    int t , i , j , a , b , n , p , q ;

    //freopen("a.txt", "r" , stdin);
    while( cin >> t )
    {
        a=t ;
        for(j=0 ; j<t ; j++)
        {
            cin >> n >> p >> q ;

            int weight[n];

            for(i=0 ; i<n ; i++)
            {
                cin >> weight[i] ;
            }


            b=0 ;

            for(i=0 ; i<n ; i++)
            {
                if(b+weight[i]<= q && i<p)
                {
                    b+=weight[i];
                }

                else
                    break ;
            }

            cout << "Case " << j+1 << ": " << i << endl ;
        }
    }
    return 0 ;
}

