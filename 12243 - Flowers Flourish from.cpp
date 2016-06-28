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
    char c , space , cmp ;
    bool brk , spck , ynck ;
//freopen("input.txt","r",stdin);
    while(scanf("%c",&c) != EOF)
    {
        if(c == '*')
            break;

        cmp = tolower(c);
        ynck = true;
        spck = false;

        while(scanf("%c",&c) != EOF)
        {
            if(c == '\n')
                break;

            if(!ynck)
                continue;

            if(spck)
            {
                if(cmp != tolower(c))
                {
                    ynck = false;
                }

                spck = false;
            }

            if(c == ' ')
                spck = true;
        }

        if(ynck)
            printf("Y\n");

        else
            printf("N\n");
    }

    return 0 ;
}
