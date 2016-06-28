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

char str[50] ;
int leng , tacken[35] , r , l ;
string result ;
map<string,int>mymap ;

void backtracking(int i);

int main()
{
    while(scanf("%s %d",str,&r) != EOF)
    {
        leng = strlen(str);
        sort(str,str+leng);
        result.clear();
        mymap.clear();
        clr(tacken,0);
        backtracking(0);
    }
    return 0;
}


void backtracking(int i)
{
    if(result.size()== r)
    {
        if(!mymap[result])
        {
            mymap[result] = 1 ;
            cout<<result<<endl;
        }
    }

    for(;i<leng;i++)
    {
        if(!tacken[i])
        {
            if(!result.empty() && str[i]<result[result.size()-1])
                continue;

            tacken[i] = 1 ;
            result.pb(str[i]);
            backtracking(i+1);
            tacken[i] = 0 ;
            result.erase(result.end()-1); //this line

            while(str[i] == str[i+1])
                i++;
        }
    }
}

