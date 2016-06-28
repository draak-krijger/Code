#include <stdio.h>
#include <string.h>

int main(){
    int r,c,i, j, k;
    scanf("%d %d\n", &r,&c);
    if(r<=50 && c<=50){
    char mat[r][c];
    for( i = 0; i<r; i++ ){
        gets(mat[i]);
    }
    printf("\n");
    for(i=0;i<c;i++){
        for(j=r-1;j>-1;j--){
            printf("%c",mat[j][i]);
        }
        printf("\n");
    }
    }
    return 0;
}

