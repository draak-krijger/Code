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

int head[20010] ;
vector<int>kheight;

int main()
{
    int n , m , a , gd ;

    while(scanf("%d %d",&n ,&m) != EOF && (n||m))
    {
        for(int i = 0 ; i<n ; i++)
            scanf("%d",&head[i]);

        kheight.clear();

        for(int i = 0 ; i<m ; i++)
        {
            scanf("%d",&a);
            kheight.push_back(a);
        }

        sort(kheight.begin(),kheight.end());

        gd = 0 ;

        if(n>m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }

        bool check ;

        for(int i=0 ; i<n ; i++)
        {
            check = true;

            for(int j=0 ; j<kheight.size() ; j++)
            {
                if(kheight[j]>=head[i])
                {
                    check = false;
                    gd+=kheight[j];
                    kheight.erase(kheight.begin()+j);
                    break;
                }
            }

            if(check)
                break;
        }

        if(check)
            printf("Loowater is doomed!\n");

        else
            printf("%d\n",gd);
    }
    return 0 ;
}
