#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int t, rt, chk, router_pos[115][4], chk_x, chk_y, i, j, k;
    double dist, temp;
    scanf("%d", &t);

    for( i = 0; i<t; i++ ){
        scanf("%d %d", &rt, &chk);
        for( j = 0; j<rt; j++ ){
            scanf("%d %d %d", &router_pos[j][0], &router_pos[j][1], &router_pos[j][2]);
        }
        printf("Case %d:\n", i+1);
        for( j = 0; j<chk; j++ ){
            scanf("%d %d", &chk_x, &chk_y);
            for( k = 0; k<rt; k++ ){
                dist = pow( (chk_x-router_pos[k][0]), 2 ) + pow( (chk_y-router_pos[k][1]), 2 );
                dist = sqrt( (double)dist );
                if( dist<= router_pos[k][2] ){
                    printf("Yes\n");
                    break;
                }
                else if( k == rt-1 )
                    printf("No\n");
            }
        }
    }

    return 0;
}
