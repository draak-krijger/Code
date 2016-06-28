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

int x , y , x2 , y2 ;

void result();

int main()
{
    while(scanf("%d %d %d %d",&x,&y,&x2,&y2) != EOF)
    {
        if(!x && !x2 && !y && !y2)
            return 0 ;

        result();
    }
    return 0 ;
}

void result()
{
    if(x == x2 && y == y2)
        printf("0\n");

    else if (x == x2 || y == y2)
        printf("1\n");

    else
    {
        if(abs(x-x2) == abs(y-y2))
            printf("1\n");

        else
            printf("2\n");
    }
}
