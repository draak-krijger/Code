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
int seq[210] ;

int main()
{
    int n , cas=0 ;
    bool check ;

    while(scanf("%d",&n) != EOF)
    {
        for(int i=0 ; i<n ; i++)
            scanf("%d",&seq[i]);

        check = true;
        mymap.clear();

        for(int i=0 ; i<n ; i++)
        {
            if(i<n-1)
            {
                if(seq[i]<1 || seq[i]>=seq[i+1])
                {
                    check = false;
                    break;
                }
            }
            for(int j = i ; j<n ; j++)
            {
                if(mymap[seq[i]+seq[j]] == 1)
                {
                    check = false;
                    i = j = n ;
                }

                else
                    mymap[seq[i] + seq[j]] = 1 ;
            }
        }

        if(check)
            printf("Case #%d: It is a B2-Sequence.\n\n",++cas);

        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",++cas);
    }
    return 0 ;
}
