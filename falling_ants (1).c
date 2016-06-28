#include <stdio.h>
#define g 9.8;

int main(){
    int c, i, j, k = 0;
    scanf("%d", &c);
    if ( c<=500 ){
        int t[c];
        int max_f[c], max_v[c];
        for( i = 0; i<=c; i++){
            if( i == c ){
                printf("0\n");
                break;
            }
            scanf("%d", &t[i]);
            if( t[i]<=100 ){
                int a = t[i];
                int l[a], w[a], h[a];
                int v[c][a], f[c][a];
                for( j = 0; j<t[i]; j++){
                    scanf("%d %d %d", &l[j], &w[j], &h[j]);
                    if( l[j]>=1 && l[j]<=50 && w[j]>=1 && w[j]<=50 && h[j]>=1 && h[j]<=50 ){
                        v[i][j] = l[j]*w[j]*h[j];
                        f[i][j] = 9.8 - 4.9/h[j];
                        max_f[i] = f[i][k];
                        max_v[i] = v[i][k];
                        if( f[i][j]>max_f[i] ){
                            max_f[i] = f[i][j];
                            max_v[i] = v[i][j];
                            k = j;
                            continue;
                        }
                        if( f[i][j] == max_f[i] ){
                            if( v[i][j]>max_v[i] ){
                                max_f[i] = f[i][j];
                                max_v[i] = v[i][j];
                            }
                        }
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
        for( i = 0; i<c; i++){
            printf("%d\n", max_v[i]);
        }
        return 0;
    }
    else{
        return 0;
    }
}
