#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , n , i , j , cnt , k =0 ;
    char s[150];

    scanf("%d",&tcase);

    while(tcase--)
    {
        k++ ;
        scanf("%d",&n);
        getchar();
        gets(s);
        cnt = 0 ;

        for(i=0 ; i<n ; i++)
        {
            if(s[i] == '.')
            {
                j = 1 ;
                cnt = 1 ;
                break;
            }
        }

        //cout << i << endl ;

        for(i = i+1 ; i<n ; i++)
        {
            if(j==3)
            {
                if(s[i] == '.')
                {
                    j=1 ;
                    cnt++;
                    continue ;
                }

                else
                    continue ;
            }

            else
                j++ ;
        }

        printf("Case %d: %d\n",k,cnt);

    }
    return 0;
}

