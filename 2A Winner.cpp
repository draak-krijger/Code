#include <bits/stdc++.h>

using namespace std ;

struct r
{
    char name[100] ;
    long long point ;
};

struct r2
{
    int indx ;
    long long point ;
};

map<string,int>mymap ;
r store[1100] ;
r2 store2[1100] ;
int player , n ;

void calculation();
void input();

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        input();
        calculation();
    }
    return 0;
}

void input()
{
    char st[100] ;
    int p ;
    player = 0 ;
    mymap.clear();

    for(int i=0 ; i<n ; i++)
    {
        scanf("%s %d",st,&p);

        if(!mymap[st])
        {
            mymap[st] = ++player ;
            strcpy(store[player-1].name,st);
            store[player-1].point = p ;
            store2[i].indx = player-1;
            store2[i].point = p ;
        }

        else
        {
            store[mymap[st]-1].point += p ;
            store2[i].point = store[mymap[st]-1].point ;
            store2[i].indx = mymap[st] - 1 ;
        }
    }
}

void calculation()
{
    long long maxim = -10000000 ;
    int indx = 0 ;

    for(int i=0 ; i<player ; i++)
    {
        if(store[i].point>maxim)
            maxim = store[i].point;
    }

    for(int i=0 ; i<n ; i++)
    {
        int shahriar = store2[i].indx;
        if(store2[i].point>=maxim and store[shahriar].point == maxim )
        {
                indx = store2[i].indx ;
                break;
        }
    }
    printf("%s\n",store[indx].name);
}
