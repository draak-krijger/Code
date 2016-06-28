#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    int t ,  n  , b , juce , miles , i ;

    while(scanf("%d",&t) != EOF)
    {
        for(b=1 ; b<=t ; b++)
        {
            scanf("%d",&n);

            int scnd[n+5];
            miles = juce = 0 ;

            for(i=0 ; i<n ; i++)
            {
                scanf("%d",&scnd[i]);
                miles += floor(scnd[i]/30) +1 ;
                juce += floor(scnd[i]/60) + 1 ;
            }

            miles *= 10 ;
            juce *= 15 ;

            if(miles < juce)
                printf("Case %d: Mile %d\n",b,miles);

            else if(juce < miles)
                printf("Case %d: Juice %d\n",b,juce);

            else if(miles == juce)
                printf("Case %d: Mile Juice %d\n",b,miles);
        }
    }
    return 0 ;
}

