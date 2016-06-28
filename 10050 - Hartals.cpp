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

map<int,int>mymap ;
int party;

int main()
{
    int day , tcase , p , a ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&day,&p);
        mymap.clear();

        for(int i=0 ; i<p ; i++)
        {
            scanf("%d",&party);

            a = party;

            while(a<=day)
            {
                mymap[a] = 1 ;
                a = a+party;
            }
        }

        a = 6 ;
        party = 0 ;

        while(a<=day)
        {
            mymap[a] = 1;
            a = a+7;
            party++;

            if((a+1)<=day)
            {
                party++;
                mymap[a+1] = 1 ;
            }
        }
        a = mymap.size() - party;
        printf("%d\n",a);
    }
    return 0 ;
}
