#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n , i , j , t ;

    while(cin >> n)
    {
        int a[n] , b [n];

        for(i=0 ; i<n ; i++)
            cin >> a[i] ;

        for(i=0 ; i<n-1 ; i++)
            b[i] = abs(a[i+1] -  a[i]) ;

        t=0 ;
        sort(b,b+i);

        for(i=0 ; i<n-2 ; i++)
        {
           if(b[i] != b[i+1]-1)
            {
                t=1 ;
                cout << "Not jolly" << endl ;
                break ;
            }
        }

        if(t==0)
            cout << "Jolly" << endl ;

    }

    return 0;
}


