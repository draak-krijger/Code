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

struct keepresult
{
    int number ;
    int divisor;
};

vector<int>primes;
int sprime[700] , l = 0 ;
bool isprime[1010] = {false};
keepresult result[1010] ;

void setprime();
int set_prime(int n , int position);
bool check_prime(int n , int position);
bool cmp(keepresult p , keepresult q);
void set_all();

int main()
{
    setprime();
    set_all();
    int tcase , n ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",cas,result[n-1].number);
    }
    return 0 ;
}

int set_prime(int n , int position)
{
    n = n | (1 << position) ;
    return n ;
}

bool check_prime(int n , int position)
{
    return n & (1 << position);
}

void setprime()
{
    sprime[0>>5] = set_prime(sprime[0>>5],1&31);

    for(int i=4 ; i<=1000 ; i = i+2)
        sprime[i>>5] = set_prime(sprime[i>>5],i&31);

    for(int i=3 ; i*i<=1000 ; i = i+2)
    {
        if(!check_prime(sprime[i>>5],i&31))
        {
            for(int j = i+i ; j<=1000 ; j = j+i)
                sprime[j>>5] = set_prime(sprime[j>>5],j&31);
        }
    }

    primes.push_back(2);
    isprime[2] = true;
    result[l].number = 1;
    result[l++].divisor = 1 ;
    result[l].number = 2;
    result[l++].divisor = 2 ;

    for(int i=3 ; i<=1000 ; i = i+2)
    {
        if(!check_prime(sprime[i>>5],i&31))
        {
            primes.push_back(i);
            isprime[i] = true;
            result[l].number = i;
            result[l++].divisor = 2 ;
        }
    }
}

void set_all()
{
    int p , a , cont ;

    for(int i =4 ; i<=1000 ; i++)
    {
        if(!isprime[i])
        {
            a = i ;
            cont = 1 ;
            for(int j = 0 ; j<=primes.size() ; j++)
            {
                if(a%primes[j] == 0)
                {
                    p = 1 ;
                    while(a%primes[j] == 0)
                    {
                        a = a/primes[j];
                        p++;
                    }
                    cont *= p;
                }

                if(a == 1)
                    break;
            }
            result[l].number = i;
            result[l++].divisor = cont ;
        }
    }

    sort(result,result+l ,cmp);
}

bool cmp(keepresult p , keepresult q)
{
    if(p.divisor<q.divisor)
        return true;

    if(p.divisor == q.divisor)
    {
        if(p.number>q.number)
            return true;
    }
    return false;
}


