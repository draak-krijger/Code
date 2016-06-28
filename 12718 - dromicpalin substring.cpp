#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int num[30] , odd ;
bool check ;
char line[10000];

void dromicpalin(int u , int v)
{
    int l ;

    l= v-u + 1 ;
    num[line[v] - 'a' ]++;

    if(num[line[v] - 'a' ] & 1)
        odd++;

    else
        odd--;

    if((l&1) && odd == 1)
        check = true ;

    if( !(l&1) && odd == 0)
        check = true ;
}

int main()
{
    int tcase , ncase = 0 , i , j , cnt , l ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%s",line);

        l = strlen(line);
        cnt = 0 ;

        for(i=0 ; i<l ; i++)
        {
            memset(num , 0 , sizeof(num));
            odd = 0 ;
            for(j=i ; j<l ; j++)
            {
                check = false ;

                dromicpalin(i,j);

                if(check)
                    cnt++;
            }
        }

        printf("Case %d: %d\n",++ncase,cnt);
    }
    return 0 ;
}
