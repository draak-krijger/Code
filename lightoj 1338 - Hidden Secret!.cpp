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

char s1[110] , s2[110] ;
int num[30] , cas ;

void calculationandresult();

int main()
{
    int tcase ;

    scanf("%d",&tcase);
    getchar();

    for(cas=1 ; cas<=tcase ; cas++)
    {
        gets(s1);
        gets(s2);
        calculationandresult();
    }

    return 0 ;
}

void calculationandresult()
{
    for(int i=0 ; i<27 ; i++)
        num[i] = 0 ;

    int l1 , l2 , a ;

    l1 = strlen(s1);
    l2 = strlen(s2);

    for(int i=0 ; i<l1 ; i++)
    {
        if(isalpha(s1[i]))
        {
            a = tolower(s1[i]) - 'a';
            num[a]++;
        }
    }

    for(int i=0 ; i<l2 ; i++)
    {
        if(isalpha(s2[i]))
        {
            a = tolower(s2[i]) - 'a';
            num[a]--;
        }
    }

    bool check = false;

    for(int i=0 ; i<26 ; i++)
    {
        if(num[i] == 0)
            continue;

        check = true;
        break;
    }

    if(check)
        printf("Case %d: No\n",cas);

    else
        printf("Case %d: Yes\n",cas);
}
