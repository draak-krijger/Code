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

using namespace std;

int main()
{
    int h , u , d , f , cont ;
    double hight , dh , l ;
    bool check ;

    while(scanf("%d %d %d %d",&h,&u,&d,&f)  && h)
    {
        cont = 0 ;
        hight = 0 ;
        l = u ;

        dh = (((double)u*(double)f)/100.0) ;

        while(1)
        {
            cont++;

            if(l>0)
                hight = hight + l ;

            l = l - dh ;

            if(hight>h)
            {
                check = true;
                break;
            }

            hight = hight - d ;

            if(hight<0)
            {
                check = false;
                break;
            }
        }

        if(check)
            printf("success on day %d\n",cont);

        else
            printf("failure on day %d\n",cont);
    }
    return 0 ;
}
