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
#define MXN
#define MXE
#define SZE
#define MOD
#define HI printf("HI\n")
#define sf scanf
#define pf printf
#define pb push_back
#define ppb pop_back
#define ll long long int
#define ul unsigned long
#define ull unsigned long long
#define x first
#define y second
#define JURA pair<int, int>
using namespace std;

ll cal_sum( ll a, ll b );

int main(){
    ll t, cas, num, half, n1, n2, cnt, sum, i, j, k;
    sf("%lld", &t);

    for( cas = 1; cas<=t; cas++ ){
        sf("%lld", &num);
        sum = 0;
        for( i = 2; i*i<=num; i++ ){
            n1 = num/i;
            if( i == n1 ){
                sum += n1*( i - 1 );
                break;
            }
            n2 = num/(i+1);
            sum += (n1-1)*i;
            sum += cal_sum( n2+1, n1 )*(i-1);
        }

        pf("Case %lld: %lld\n", cas, sum);
    }

    return 0;
}
ll cal_sum( ll a, ll b ){
    ll n = ( b - a ) + 1, tmp;
    tmp = n*( (2*a) + ( b - a) );
    tmp /= 2;
    return tmp;
}
