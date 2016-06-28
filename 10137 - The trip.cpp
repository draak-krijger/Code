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

double perhead[1010] ;

int main()
{
    int numofstd ;
    double sum , upsum , pos , neg ;

    while(scanf("%d",&numofstd) != EOF && numofstd)
    {
        sum = 0 ;

        for(int i=0 ; i<numofstd ; i++)
        {
            scanf("%lf",&perhead[i]);
            sum += perhead[i] ;
        }

        sum /= (double)numofstd ;

        pos = neg = 0 ;

        for(int i=0 ; i<numofstd ; i++)
        {
            upsum = (long)((perhead[i]-sum)*100.0)/100.0;

            if(upsum>0)
                pos += upsum;

            else
                neg -= upsum;
        }

        if(pos>neg)
            upsum = pos ;

        else
            upsum = neg ;

        printf("$%.2lf\n",upsum);
    }
    return 0 ;
}
