#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    long long int a ;

    while(scanf("%lld",&a) != EOF)
    {
        if(a<0)
            return 0 ;

        if(a==1)
        {
            cout << 0 <<'%' << endl;
            continue;
        }

        cout << a*25 << '%' <<endl;
    }
    return 0 ;
}
