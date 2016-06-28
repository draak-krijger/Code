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

int main()
{
    int a , x , y , z , d ;
    long long b ;
    bool check ;

    while(scanf("%d",&a) != EOF && a)
    {
        check = false;

        for(int i=1 ; i<a ; i++)
        {
            b = a+pow((double)i,3.0);

            d = round(pow((double)b,(double)(1.0/3.0)));

            if((long long)(d*d*d) == b)
            {
                check = true;
                x = i ;
                y = d ;
                break;
            }
        }

        if(check)
            printf("%d %d\n",x,y);

        else
            printf("No solution\n");
    }
    return 0 ;
}
