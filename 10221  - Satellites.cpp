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
    int distance , angle ;
    double arc , chrod , angle2 ;
    char s[100] ;

    while(scanf("%d %d %s",&distance,&angle,s) != EOF)
    {
        if(strcmp(s,"min") == 0)
        {
            if(angle>180)
                angle = 360-angle;

            angle2 = (double)angle/60.0 ;
        }

        else
        {
            if(angle>180)
                angle = 360-angle;

            angle2 = angle;
        }

        distance = distance + 6440 ;

        arc = distance * (pi*angle2/180.0) ;
        chrod = 2*distance*sin(pi*angle2/360.0);

        printf("%.6lf %.6lf\n",arc,chrod);
    }
    return 0 ;
}
