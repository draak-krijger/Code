#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>

using namespace std ;

double r1 , r2 , r3 , a , b , c , s , aa , ab , ac , area_triangle ;

void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        calculation(cas);
    }
    return 0 ;
}

void calculation(int cas)
{
    a = r1+r2 ;
    b = r2+r3 ;
    c = r3+r1 ;

    s = (a+b+c)/2.0 ;

    area_triangle = sqrt(s*(s-a)*(s-b)*(s-c));

    aa = acos((b*b + c*c - a*a)/(2.0*b*c));
    ab = acos((a*a + c*c - b*b)/(2.0*a*c));
    ac = acos((a*a + b*b - c*c)/(2*a*b));

    s = ((r3*r3*aa)/2.0) + ((r2*r2*ac)/2.0) + ((r1*r1*ab)/2.0) ;

    s = area_triangle - s ;

    printf("Case %d: %lf\n",cas,s);
}
