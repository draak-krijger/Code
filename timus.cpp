/**
  *                              ------------------------- ALLAH is Almighty -----------------------------
  *  @author: M. NAZIM UDDIN
  *  University: SUST
  *  OJ: Timus
  *  problem name:
  * Category :
  */

// Pre_code

//#include <bits/stdc++.h>

// header file
#pragma comment(linker, "/STACK:667772160")
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <numeric>
#include <cstring>

using namespace std ;

//define function

#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>n ; i--)
#define fore0(i,a,n) for(int i=a ; i>=n ; i--)
#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pii acos(-1.0)
#define jora_int pair<int,int>
#define jora_ll pair<long long,long long>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 1000000000000000
#define sz 5000+7
#define Mod 1000000009
#define EPS 1e-6
#define ll long long
#define ull unsigned long long
#define fs first
#define sc second
#define wait system("pause")
#define sf scanf
#define pf printf
#define mp make_pair
#define ps pf("PASS\n")
#define Read freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\input.txt","r",stdin)
#define Write freopen("C:\\Users\\RONIN-47\\Desktop\\input_output\\output.txt","w",stdout)
#define jora_double pair<double,double>
//debug

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

// moves

//int dx[]= {-1,-1,0,0,1,1};
//int dy[]= {-1,0,-1,1,0,1};
//int dx[]= {0,1,0,-1};/*4 side move*/
//int dy[]= {1,0,-1,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]= {1,1,2,2,-1,-1,-2,-2}; /*night move*/
//int dy[]= {2,-2,1,-1,2,-2,1,-1}; /*night move*/

//close

char str[5000] ;
int len , arr[5000] ;

int cal_sum()
{
    int cont = 0 ;

    for(int i=0 ; i<len ; i++)
    {
        arr[i] = 0 ;

        if(str[i] == '1')
        {
            cont += (i+1) ;
            arr[i] = 1 ;
        }

        if(i)
            arr[i] += arr[i-1] ;
    }

    return cont ;
}

int main()
{
    //Read;
    int n , sum , temp ;
    char ch ;

    sf1(n);

    while(ch = getchar())
    {
        len = 0 ;

        if(isdigit(ch))
            str[len++] = ch ;

        if(ch == EOF)
            break;

        while(ch = getchar())
        {
            if(ch == EOF)
                break;

            if(ch == ' ')
                continue;

            if(ch == '\n')
            {
                if(len)
                    break;

                continue;
            }

            str[len++] = ch ;
        }

        if(len == n)
        {
            sum = cal_sum();

            if(sum%(n+1))
            {
                for(int i=0 ; i<n ; i++)
                {
                    if(str[i] == '1' and (sum - i - 1)%(n+1) == 0)
                    {
                        str[i] = '0' ;
                        break;
                    }
                }
            }

            for(int i=0 ; i<len ; i++)
                pf("%c",str[i]);

            pf("\n");
        }

        else if(len>n)
        {
            sum = cal_sum();

            for(int i=0 ; i<len ; i++)
            {
                temp = arr[len-1] - arr[i] ;

                if(str[i] == '1')
                    temp += (i + 1) ;

                if((sum-temp)%(n+1) == 0)
                {
                    str[i] = 'n' ;
                    break;
                }
            }

            for(int i=0 ; i<len ; i++)
            {
                if(str[i] == 'n')
                    continue;

                pf("%c",str[i]);
            }

            pf("\n");
        }

        else
        {
            sum = cal_sum() ;
            int pos = len , t = 0 ;

            if(sum%(n+1) == 0)
            {
                for(int i=0 ; i<len ; i++)
                    pf("%c",str[i]);

                pf("0\n");
            }

            else if((sum+n)%(n+1) == 0)
            {
                for(int i=0 ; i<len ; i++)
                    pf("%c",str[i]);

                pf("1\n");
            }

            else
            {
                for(int i=0 ; i<len ; i++)
                {
                    if(!i)
                        temp = arr[len-1] ;

                    else
                        temp = arr[len-1] - arr[i-1] ;
//deb(temp,arr[len-1],arr[max(i-1,0)]);
                    if((sum+temp)%(n+1) == 0)
                    {
                        t = 0 ;
                        pos = i ;
                        break;
                    }

                    else if((sum+temp+i+1)%(n+1) == 0)
                    {
                        t = 1 ;
                        pos = i ;
                        break;
                    }
                }

                for(int i=0 ; i<len ; i++)
                {
                    if(pos == i)
                        pf("%d",t);

                    pf("%c",str[i]);
                }

                if(pos == len)
                    pf("0");

                pf("\n");
            }
        }

        if(ch == EOF)
            break;
    }

    return 0;
}
