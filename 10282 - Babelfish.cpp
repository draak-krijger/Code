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

map<string,string>matrix;
map<string,int>check ;
map<string,string>:: iterator it ;

int main()
{
    int a ;
    char s[100] , s1[50] , s2[50] ;
//freopen("input.txt","r",stdin);
    while(gets(s) && strlen(s)>0)
    {
        sscanf(s,"%s %s",s1,s2);
        matrix[s2] = s1 ;
        check[s2] = 1 ;
    }

    while(scanf("%s",s1) != EOF)
    {
       if(check[s1])
            cout << matrix[s1] << endl;

       else
        printf("eh\n");
    }
    return 0 ;
}
