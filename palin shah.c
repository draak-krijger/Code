#include <stdio.h>
#include <string.h>

int main(){
    int test, len, x = 0, i, j, k;
    scanf("%d\n", &test);
    char value[test][100];
    for( i = 0; i<test; i++ ){
        gets(value[i]);
    }
    for( i = 0; i<test; i++ ){
        len = strlen(value[i]);
        for( j = 0, k = len-1; j<len; j++, k-- ){
            if( value[i][j] != value[i][k] ){
                x = 10;
            }
        }
        if( x == 0 ){
            printf("Case %d: Yes\n", i+1);
        }
        else{
            printf("Case %d: No\n", i+1);
            x = 0;
        }
    }

    return 0;
}
