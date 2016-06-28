/*
ID: mohamma107
LANG: C++
TASK: palsquare
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
    int base ;
    string s1 , s2 ;
    bool a ;

    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    while(fin>>base)
    {
        for(int i=1 ; i<=300 ; i++)
        {
            s1.clear();
            s2.clear();
            a = basecon(i*i,base);

            if(a)
            {
                reverse(str.begin(),str.end());
                s2 = str;
                basecon(i,base);
                reverse(str.begin(),str.end());
                s1 = str;
                fout<<s1<<" "<<s2<<endl;
            }
        }
    }
    return 0;
}
