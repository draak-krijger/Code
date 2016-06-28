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

char str[1000010];

int main()
{
    bool check;
    int a , b , query , cas=0 ;
    char c ;
 //freopen("input.txt","r",stdin);
    while(scanf("%s",str) != EOF)
    {
        scanf("%d",&query);
        printf("Case %d:\n",++cas);

        for(int i=0 ; i<query ; i++)
        {
            scanf("%d %d",&a,&b);

            if(a>b)
                swap(a,b);

            check = true;
            c = str[a];
            a = a+1 ;
            int k=1 ;

            while(a<=b)
            {
                if(str[a] != c )
                {
                    check = false;
                    break;
                }

                if(str[b] != c)
                {
                    check = false;
                    break;
                }

                a = a+k;
                b = b-k;
                k++;
            }

            if(check)
                printf("Yes\n");

            else
                printf("No\n");
        }
    }
    return 0 ;
}
