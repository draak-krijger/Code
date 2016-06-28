// LIS nlog(n)
#include <bits/stdc++.h>
using namespace std;

int test, cas = 1;

#define SIZ 10000

int n;
int num[SIZ];

vector<int> C;
int L[SIZ]; //where length of LIS from 1 to i is saved

/* beware: vector<int> C is not final LIS. it is just a temporary storage. */

int LIS_nlgn()
{
    int maxlen = 0;
    vector<int>::iterator it;
    for(int i = 1; i <= n; ++i)
    {
        it = lower_bound(C.begin(), C.end(), num[i]);
        L[i] = (int)(it - C.begin() + 1);
        if(it == C.end()) C.push_back(num[i]);
        else if(*it > num[i]) *it = num[i];
        maxlen = max(maxlen, L[i]);
    }
    return maxlen;
}

int main()
{
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> num[i];

        int res = LIS_nlgn();
        cout << "LIS = " << res << endl;
    }

    return 0;
}
