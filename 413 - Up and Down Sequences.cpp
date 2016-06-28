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
    unsigned int number[50] , n , countequal ;
    bool up , down ;
    double upcount , downcount , upaverage , downaverage ;

    while(scanf("%u",&number[0]) && number[0])
    {
        n = 1 ;

        up = down = true ;
        upcount = downcount = upaverage = downaverage = 0 ;
        countequal = 0 ;

        while(scanf("%u",&number[n]) != EOF && number[n])
        {
            if(number[n]>number[n-1])
            {
                upaverage++;

                if(up)
                {
                    upcount++;
                    upaverage += countequal ;
                    countequal = 0 ;
                }

                up = false;
                down = true;
            }

            else if(number[n]<number[n-1])
            {
                downaverage++;

                if(down)
                {
                    downcount++;
                    downaverage += countequal ;
                    countequal = 0;
                }

                up = true;
                down = false;
            }

            else
            {
                if(!up)
                    upaverage++;

                else if(!down)
                    downaverage++;

                else
                    countequal++;
            }
            n++;
        }

        printf("Nr values = %u:  ",n);

        if(upcount)
        {
            upaverage = upaverage/upcount;
            printf("%.6lf ",upaverage);
        }

        else
            printf("%.6lf ",upcount);

        if(downcount)
        {
            downaverage = downaverage/downcount ;
            printf("%.6lf\n",downaverage);
        }

        else
            printf("%.6lf\n",downcount);
    }

    return 0 ;
}
