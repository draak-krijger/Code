#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int h1 , m1 , h2 , m2 , strt , close , diff ;

    while(cin >> h1 >> m1 >> h2 >> m2)
    {
        if(!h1 && !m1 && !h2 && !m2)
            return 0 ;

        strt = h1*60 + m1 ;
        close = h2*60 + m2 ;

        if(close < strt )
            close += 1440 ;

        diff = close - strt ;

        cout << diff << endl ;
    }
    return 0 ;
}

