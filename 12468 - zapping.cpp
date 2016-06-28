#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int a , b , c ;

    while(cin >> a >> b )
    {
        if(a==-1 && b==-1)
            return 0 ;

        if(b>a)
            swap(a,b);

        c= a-b ;

        if(c > 50)
        {
            b += 100 ;
            c = b-a ;
        }

        cout << c << endl ;
    }
    return 0 ;
}

