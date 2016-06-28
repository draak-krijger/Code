#include <cstdio>
#include <iostream>

using namespace std ;

int main()
{
    long long a ;

    while(cin >> a)
    {
        if(a<0)
            break ;
        a = (a*(a+1)/2) + 1 ;

        cout << a << endl;
    }
    return 0 ;
}

