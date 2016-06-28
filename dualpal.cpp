/*
ID: mohamma107
LANG: C++
TASK: dualpal
*/

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
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define pi acos(-1.0)
#define jora_int pair<int,int>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define Max 500+10
#define sz 1005
#define Mod 1000000007
#define EPS 1e-10
#define ll long long
#define ull unsigned long long

string str ;
vector<int>dualpalin;

bool ispalin()
{
    int i = 0 , j = str.size()-1 ;

    while(i<j)
    {
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool basecon(int n , int base)
{
    int i = n , len = 0 , temp ;
    str.clear();

    while(n)
    {
        temp = n%base ;
        n /= base;

        if(temp<10)
            str += (temp + '0') ;

        else
            str += ((temp-10) + 'A') ;
    }

    return ispalin();
}

int main()
{
    int cont , s , bcont , n ;

    cont = bcont = 0 ;
    dualpalin.clear();
    s = 1 ;

    while(s++)
    {
        bcont = 0 ;

        for(int base = 2 ; base<=10 ; base++)
        {
            if(basecon(s,base))
                bcont++;

            if(bcont>=2)
                break;
        }

        if(bcont>=2)
        {
            dualpalin.pb(s);

            if(s>10000)
                cont++;
        }

        if(cont == 16)
            break;
    }

    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    while(fin>>n>>s)
    {
        vector<int>::iterator it ;
        it = upper_bound(dualpalin.begin(),dualpalin.end(),s);
        int i = it-dualpalin.begin();
        cont = 0 ;

        while(cont<n)
        {
            cont++;
            fout<<dualpalin[i++]<<endl;
        }
    }
    return 0;
}
