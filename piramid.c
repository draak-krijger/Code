#include <stdio.h>

int main(){
    char x = '*';
    int slot, a, b, space, i, c, n = 1;
    scanf("%d", &slot);
    int line[slot];
    for( b = 0;b<slot;b++){
        scanf("%d", &line[b]);
    }
    for( b = 0; b<slot; b++){
        space = line[b];
        for( i = 1; i<=space; i++){
            printf(" ");
            if( i == space){
                for( c = 1; c<=n; c++){
                    printf("%c", x);
                    if( c == n){
                        printf("\n");
                        n = n + 2;
                        space = space -1;
                        if( space == 0){
                            printf("\n");
                            n = 1;
                        }
                        c = 0;
                        i = 0;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
