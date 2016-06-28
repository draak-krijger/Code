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

map<string,string>mymap;
map<string,bool>mapcheck ;

bool isvowel(char c);

int main()
{
    int l , n , length ;
    char s1[100] , s2[100] ;

    while(scanf("%d %d",&l,&n) != EOF)
    {
        mymap.clear();
        mapcheck.clear();

        for(int i = 0 ; i<l ; i++)
        {
            scanf("%s %s",s1,s2);
            mymap[s1] = s2;
            mapcheck[s1] = true;
        }

        for(int i=0 ; i<n ; i++)
        {
            scanf("%s",s1);

            length = strlen(s1);

            if(mapcheck[s1])
            {
                cout << mymap[s1] << endl;
                continue;
            }

            else if(s1[length-1] == 'y' && !isvowel(s1[length-2]))
            {
                for(int j=0 ; j<length-1 ; j++)
                    printf("%c",s1[j]);

                printf("ies\n");
            }

            else if(s1[length-1] == 'o' || s1[length-1] == 's' || s1[length-1] == 'x' || (s1[length-1] == 'h' && s1[length-2] == 'c') || (s1[length-1] == 'h' && s1[length-2] == 's'))
            {
                printf("%ses\n",s1);
            }

            else
                printf("%ss\n",s1);
        }
    }
    return 0 ;
}

bool isvowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

    return false;
}
