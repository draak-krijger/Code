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
#define jora pair<int,int>
#define pb push_back

using namespace std ;

stack<int>horizon;
vector<int>temp ;
map<int,int>mymap ;
int weight[5500] , n , mvalue[11000] , m ;

void calculation();
void reset();

int main()
{
    int l ;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        reset();
        l=0;

        for(int i=1 ; i<=n ; i++)
            scanf("%d",&weight[i]);

        for(int i=1 ; i<=m ; i++)
        {
            scanf("%d",&mvalue[i]);

            if(l<n)
            {
                if(!mymap[mvalue[i]])
                {
                    mymap[mvalue[i]] = 1 ;
                    temp.push_back(mvalue[i]);
                    l++;
                }
            }
        }

        for(int i=temp.size()-1 ; i>=0 ; i--)
            horizon.push(temp[i]);

        calculation();

    }
    return 0;
}

void reset()
{
    while(!horizon.empty())
        horizon.pop();

    mymap.clear();
    temp.clear();
}

void calculation()
{
    int a ;
    long long int wt = 0 ;

    for(int i=1 ; i<=m ; i++)
    {
        temp.clear();
        a = horizon.top();
        horizon.pop();

        while(a != mvalue[i])
        {
            temp.push_back(a);
            wt += weight[a] ;
            a = horizon.top();
            horizon.pop();
        }

        for(int i=temp.size()-1 ; i>=0 ; i--)
            horizon.push(temp[i]);

        horizon.push(a);
    }

    cout<<wt<<endl;
}
