#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;

int main()
{
    double m[5] , sm , area ;

    while(scanf("%lf %lf %lf",&m[0],&m[1],&m[2]) != EOF)
    {
        sort(m,m+3);

        if(m[0] == 0 || m[1] == 0 || m[2] == 0)
        {
            printf("-1.000\n");
            continue;
        }

        if(m[0]+m[1] > m[2])
        {
            sm = (m[0]+m[1]+m[2])/2 ;

            area = (4.0/3.0) * sqrt(sm*(sm-m[0])*(sm-m[1])*(sm-m[2]));
            printf("%.3lf\n",area);
        }

        else
            printf("-1.000\n");
    }
    return 0 ;
}
