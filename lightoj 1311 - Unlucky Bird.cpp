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

double v1 , v2 , v3 , a1 , a2 , t1 , t2 , dis , birddis ;
int cas ;

void calculation();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);
        calculation();
    }

    return 0 ;
}

void calculation()
{
    dis = ((v1*v1)/(2.0*a1)) + ((v2*v2)/(2.0*a2)) ;
    birddis = max((v1/a1),(v2/a2))*v3 ;

    printf("Case %d: %.6lf %.6lf\n",cas,dis,birddis);
}
