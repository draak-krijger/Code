#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std ;

map<string , int > subject ;

int main()
{
    int tcase , numofsub , remainday , fd ;
    string sub ;
    map<string , int > ::iterator im ;

    scanf("%d",&tcase);

    for(int cas = 1 ; cas<=tcase ; cas++)
    {
        scanf("%d",&numofsub);
        subject.clear();

        for(int i=1 ; i<=numofsub ; i++)
        {
            cin >> sub >> fd ;
            subject[sub] = fd ;
        }

        scanf("%d",&remainday);
        cin >> sub;

        //*im = subject[sub];
        fd = subject[sub] ;

        if(fd<=remainday && fd != 0)
            printf("Case %d: Yesss\n",cas);

        else if(fd<=(remainday+5) && fd != 0)
            printf("Case %d: Late\n",cas);

        else
            printf("Case %d: Do your own homework!\n",cas);
    }
    return 0 ;
}
