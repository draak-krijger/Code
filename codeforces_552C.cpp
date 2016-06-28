#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <utility>
#define pb push_back
#define mp make_pair
#define ft first
#define nd second
#define init(x,n,y) x.assign(n,y);
#define Kagami(f) f.end()
#define Natsu(f) f.begin()
#define NatsuKagami(f) f.begin(),f.end()
#define low(f,x) lower_bound(f.begin(),f.end(),x)
#define hi(f,x) upper_bound(f.begin(),f.end(),x)
#define poi(a,x,y) for(int a = x; a < (int)y; ++a)
#define meow(a,x,y) for (int a = x; a >= (int)y; --a)
using namespace std;

typedef vector<int> vi;
long long n, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    if (n == 2) return cout << "YES\n", 0;
    long long rem = 0;
    while (w) {
        long long f = w % n + rem;
        if (f == n - 1 || f == n) rem = 1;
        else if (f == 0 || f == 1) rem = 0;
        else break;
        w /= n;
    }
    cout << (w ? "NO" : "YES") << endl;
}
