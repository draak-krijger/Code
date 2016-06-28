#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long a[3] , b , d;

    while(cin >> a[0] >> a[1] >> a[2])
    {
        if(!a[0] && !a[1] && !a[2])
            break ;

        sort(a,a+3);

        if((pow((double)a[0],2) + pow((double)a[1],2)) == pow((double)a[2],2))
        {
            cout << "right" << endl ;
        }

        else
            cout << "wrong" << endl ;
    }
    return 0 ;
}

