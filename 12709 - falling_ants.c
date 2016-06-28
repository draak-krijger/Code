#include <stdio.h>

int main(){
    int c, i, j, k;
    scanf("%d", &c);
    if ( c<=500 ){
        int t[c];
        double max_f[c], max_v[c];
        for( i = 0; i<=c; i++){
            if( i == c ){
                printf("0\n");
                break;
            }
            scanf("%d", &t[i]);
            if( t[i]<=100 ){
                int a = t[i];
                int l[a], w[a], h[a];
                double v[c][a], f[c][a];
                for( j = 0; j<t[i]; j++){
                    scanf("%d %d %d", &l[j], &w[j], &h[j]);
                    v[i][j] = l[j]*w[j]*h[j];
                    f[i][j] = 9.8 - 4.9/h[j];
                    max_f[i] = f[i][0];
                    max_v[i] = v[i][0];
                    if( f[i][j]>max_f[i] ){
                        max_f[i] = f[i][j];
                        max_v[i] = v[i][j];
                    }
                    if( f[i][j] == max_f[i] ){
                        if( v[i][j]>max_v[i] ){
                            max_f[i] = f[i][j];
                            max_v[i] = v[i][j];
                        }
                    }
                }
            }
        }
        for( i = 0; i<c; i++){
            printf("%.001lf\n", max_v[i]);
        }
        return 0;
    }
    else{
        return 0;
    }
}
