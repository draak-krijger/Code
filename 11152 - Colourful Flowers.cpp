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
#define pi acos(-1)

using namespace std ;

int main()
{
    int a[5]  ;
    double y , r , v , s , R , b_R ;

    while(scanf("%d %d %d",&a[0],&a[1],&a[2]) != EOF)
    {
        s = (double)(a[0] + a[1] + a[2])/2.0 ;
        v = sqrt(s*(s-a[0])*(s-a[1])*(s-a[2]));

        b_R = (double)(a[0]*a[1]*a[2])/(4.0*v);
        R = v/s;

        r = pi*(R*R);
        y = pi*(b_R*b_R);
        y = y-v;
        v = v-r;
        printf("%.4lf %.4lf %.4lf\n",y,v,r);
    }
    return 0 ;
}
