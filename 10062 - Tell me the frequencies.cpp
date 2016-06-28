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

struct frequence
{
    int asci ;
    int cont ;
};

frequence calfreq[150] ;
map<char,int>mymap;

bool cmp(frequence p , frequence q);

int main()
{
    char str[1010] ;
    bool check = false;
//freopen("input.txt","r",stdin);
    while(gets(str))
    {
        mymap.clear();
        for(int i=0 ; i<strlen(str) ; i++)
        {
            mymap[str[i]]++;
        }

        int l=0 ;

        for(typeof(mymap.begin()) it = mymap.begin() ; it!=mymap.end() ; ++it)
        {
            calfreq[l].asci = it->first;
            calfreq[l++].cont = it->second;
        }

        sort(calfreq , calfreq+l , cmp);

        if(check)
            printf("\n");

        check = true;

        for(int i=0 ; i<l ; i++)
            printf("%d %d\n",calfreq[i].asci,calfreq[i].cont);
    }
    return 0 ;
}

bool cmp(frequence p , frequence q)
{
    if(p.cont < q.cont)
        return true;

    if(p.cont == q.cont)
    {
        if(p.asci>q.asci)
            return true;
    }
    return false;
}

