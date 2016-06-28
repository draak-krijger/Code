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

char s[100] ;

bool ispalindrome(char p[]);
void calculation(int cas);

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
        calculation(cas);

    return 0 ;
}

void calculation(int cas)
{
    scanf("%s",s);

    if(ispalindrome(s))
        printf("Case %d: Yes\n",cas);

    else
        printf("Case %d: No\n",cas);
}

bool ispalindrome(char p[])
{
    int l ;
    bool check = true;

    l = strlen(p) - 1 ;

    for(int i=0 , j=l ; i<j ; i++,j--)
    {
        if(p[i] != p[j])
        {
            check = false;
            break;
        }
    }

    return check;
}
