#include <cstdio>
#include <iostream>
#include <algorithm>

int a[2000010];

using namespace std ;

int main()
{
    int b , t , i ;

    while(cin >> t)
    {
        if(t==0)
            break ;

            for(i=0 ; i<t ; i++)
                cin >> a[i] ;

        sort(a,a+t);

        for(i=0 ; i<t ; i++)
        {
            if(a[i]>=1 && a[i]<=100)
            {
                cout << a[i] ;
                if(i != t-1)
                    cout << " ";
            }
        }
        cout << endl ;

    }
    return 0;
}

