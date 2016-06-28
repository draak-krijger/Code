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

int enable[5100] ;

bool isrepeat(int n);
void enablecal();
void output(int a , int b);

int main()
{
    int a, b ;
    enablecal();

    while(scanf("%d %d",&a,&b) != EOF)
        output(a,b);

    return 0 ;
}

void enablecal()
{
    for(int i=1 ; i<5010 ; i++)
    {
        if(isrepeat(i))
            enable[i] = enable[i-1];

        else
            enable[i] = enable[i-1] + 1 ;
    }
}

bool isrepeat(int n)
{
    bool digit[15] ;
    fill(digit,digit+10,false);
    int a ;

    while(n)
    {
        a = n%10 ;
        n /= 10 ;

        if(digit[a])
            return true;

        else
            digit[a] = true;
    }

    return false;
}

void output(int a , int b)
{
    printf("%d\n",enable[b] - enable[a-1]);
}
