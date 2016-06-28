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

int sd[7][7] ;
vector<int>result ;

void backtracking(int i);
void initial();

int main()
{
    initial();
    result.clear();
    result.pb(1);
    backtracking(1);
    return 0;
}

void initial()
{
    forln(i,1,7)
    {
        forln(j,1,7)
        {
            sd[i][j] = 1 ;
        }
    }

    sd[1][5] = sd[5][1] = sd[1][3] = sd[3][1] = sd[1][2] = sd[2][1] = 0 ;
    sd[2][5] = sd[5][2] = sd[2][3] = sd[3][2] = 0 ;
    sd[3][5] = sd[5][3] = sd[3][4] = sd[4][3] = 0 ;
    sd[4][5] = sd[5][4] = 0 ;
}

void backtracking(int i)
{
    if(result.size() == 9)
    {
        forln(j,0,9)
        {
            printf("%d",result[j]);
        }

        printf("\n");
        return;
    }

    forln(j,1,6)
    {
        if(sd[i][j] == 0)
        {
            sd[i][j] = 1 ;
            sd[j][i] = 1 ;
            result.pb(j);
            backtracking(j);
            sd[i][j] = 0 ;
            sd[j][i] = 0 ;
            result.pp();
        }
    }
}
