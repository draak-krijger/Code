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

set<string>myset;
map<string,int>mymap;

int main()
{
    int tcase , l ;
    char str[50] ;
    double b ;
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);
    getchar();
    getchar();

    while(tcase--)
    {
        myset.clear();
        mymap.clear();
        l = 0 ;

        while(gets(str) && strlen(str)>0)
        {
            l++;
            mymap[str]++;
            myset.insert(str);
        }
        for(typeof(myset.begin()) ik = myset.begin() ; ik!=myset.end() ; ++ik)
        {
            cout << *ik << " ";
            b = ((double)mymap[*ik]*100.0)/(double)l;
            printf("%.4lf\n",b);
        }

        if(tcase)
            printf("\n");
    }
    return 0;
}
