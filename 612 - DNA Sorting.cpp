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

struct sorting
{
    char str[100];
    int cont ;
};

sorting variable[150] ;
int calculate(char strin[] , int l );
bool cmp(sorting p , sorting q);

int main()
{
    int tcase , r , c ;
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&c,&r);

        for(int i=0 ; i<r ; i++)
        {
            scanf("%s",variable[i].str);
            variable[i].cont = calculate(variable[i].str,c);
        }

        stable_sort(variable , variable+r , cmp);

        for(int i=0 ; i<r ; i++)
            printf("%s\n",variable[i].str);

        if(tcase)
            printf("\n");
    }
    return 0 ;
}

int calculate(char strin[] , int l )
{
    int b = 0 ;

    for(int i=0 ; i<l ; i++)
    {
        for(int j=i+1 ; j<l ; j++)
        {
            if(strin[j]<strin[i])
                b++;
        }
    }

    return b ;
}

bool cmp(sorting p , sorting q)
{
    if(p.cont<q.cont)
        return true;

    return false;
}

