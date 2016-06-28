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

using namespace std;

int main()
{
    char s[100] ;
    int a , b , tcase , l ;
    double weight  ;
    bool check ;

    scanf("%d",&tcase);
    getchar();

    for(int cas = 1 ; cas<=tcase ; cas++)
    {
        gets(s);
        check = false;

        l = strlen(s) ;
        a = b = 0 ;

        for(int i = 0 ; i<l ; i++)
        {
            if(!check)
            {
                if(isdigit(s[i]))
                {
                    a = a*10 + (s[i] - '0');
                }

                else
                {
                    check = true;
                }
            }

            else
            {
                if(isdigit(s[i]))
                {
                    b = b*10 + (s[i] - '0');
                }
            }
        }

        weight = (double)a*.5 + (double)b*.05 ;

        cout << "Case " << cas << ": " << weight << endl;
    }
    return 0 ;
}
