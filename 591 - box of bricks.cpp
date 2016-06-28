#include <iostream>>
#include <cstdio>

using namespace std;

int main()
{
    int t , i , a , b , se = 0 ;

    while(cin >> t)
    {
        if(t==0)
            return 0 ;

        se++;
        int height[t];
        a=0 ;

        for(i=0 ; i<t ; i++)
        {
            cin >> height[i];
            a += height[i];
        }

        a = a/t ;
        b=0 ;

        for(i=0 ; i<t ; i++)
        {
            if(height[i]<a)
            {
                b +=  a - height[i];
            }
        }

        printf("Set #%d\n",se);
        printf("The minimum number of moves is %d.\n\n",b);

    }

    return 0 ;
}

