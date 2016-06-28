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

double ox , oy , ax , ay , bx , by , oa , ab , aob , dis ;

void input();
double caldis(double x1 , double y1 , double x2 , double y2);
void calculation(int cas);
double redtodeg(double red);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }

    return 0 ;
}

void input()
{
    scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
}

double caldis(double x1 , double y1 , double x2 , double y2)
{
    double a ;

    a = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));

    return a ;
}

void calculation(int cas)
{
    oa = caldis(ox,oy,ax,ay);
    ab = caldis(ax,ay,bx,by);

    aob = acos((((oa*oa) + (oa*oa)) - (ab*ab))/(2.0*oa*oa)) ;
    aob = redtodeg(aob);

    dis = (pi*oa*aob)/180.0 ;

    printf("Case %d: %.6lf\n",cas,dis);
}

double redtodeg(double red)
{
    double ang ;

    ang = (180.0 * red)/pi ;

    return ang;
}
