#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{

    long long int  first, last, sum1, sum2, diff, j, k;
    int i , t ;

    scanf("%d", &t);

    for( i = 1; i<=t; i++ )
    {
        cin >> first >> last ;

        first = first - 1 ;

        sum1 = first*first*(first+1)*(first+1)/4 ;
        sum2 = last*last*(last+1)*(last+1)/4 ;
        diff = sum2 - sum1;
        cout<<"Case #"<<i<<": "<<diff<<endl;
    }

    return 0;
}
