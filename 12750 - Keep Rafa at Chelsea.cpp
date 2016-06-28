#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, n, cnt, nt_win, x, i , j , k;
    char res;

    scanf("%d", &t);

    for( i = 0; i<t; i++ )
    {
        scanf("%d", &n);

        cnt = nt_win = x = 0;
        for( j = 0; j<n; j++ ){
                getchar();
                scanf("%c", &res);

                if( x == 1 ){
                    continue;
                }
                else if( res != 'W' ){
                    nt_win++;
                    cnt++;
                    if( nt_win == 3 ){
                        x = 1;
                    }
                }
                else if( res == 'W' ){
                    cnt++;
                    nt_win = 0;
                }
        }
        if( cnt == n and x == 0 )
            printf("Case %d: Yay! Mighty Rafa persists!\n", i+1);
        else
            printf("Case %d: %d\n", i+1, cnt);
    }

    return 0;
}
