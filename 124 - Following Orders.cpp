#include <bits/stdc++.h>

using namespace std ;

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>0 ; i--)
#define fore0(i,a,n) for(int i=a ; i>=0 ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 600000+10

int l ;
char str[30] ;
vector<int>graph[30] ;
vector<char>result ;
bool visit[30] ;

void initial();
bool check(int indx);
void backtracking();

int main()
{
    char tmp1 , tmp2 ;
    bool tp = false;

    while(scanf("%c",&tmp1) != EOF)
    {
        l = 0 ;
        str[l++] = tmp1 ;

        while(scanf("%c",&tmp1) != EOF)
        {
            if(tmp1 == '\n')
                break;

            scanf("%c",&tmp2);
            str[l++] = tmp2 ;
        }

        sort(str,str+l);
        initial();

        while(scanf("%c%c%c",&tmp1,&tmp2,&tmp2) !=EOF)
        {
            graph[tmp1-'a'].pb(tmp2-'a');
            scanf("%c",&tmp1);

            if(tmp1 == '\n')
                break;
        }
        if(tp)
            printf("\n");

        tp = true;

        backtracking();
    }
    return 0 ;
}

void initial()
{
    for(int i=0 ; i<30 ; i++)
    {
        graph[i].clear();
        visit[i] = false;
    }
    result.clear();
}

bool check(int indx)
{
    for(int i=0 ; i<graph[indx].size() ; i++)
    {
        if(visit[graph[indx][i]])
            return false;
    }

    return true;
}

void backtracking()
{
    if(result.size() == l)
    {
        forln(i,0,l)
        {
            printf("%c",result[i]);
        }
        printf("\n");
        return ;
    }

    forln(i,0,l)
    {
        if(!visit[str[i]-'a'])
        {
            if(check(str[i]-'a'))
            {
                visit[str[i]-'a'] = true;
                result.pb(str[i]);
                backtracking();
                visit[str[i]-'a'] = false;
                result.pp();
            }

            else
                return;
        }
    }
}
