/*
ID: mk.shah1
LANG: C
TASK: milk2
*/
#include <stdio.h>

int main(){
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");

    int n, i, j;
    fscanf(fin, "%d\n", &n);
    int begin[n], end[n], sort[n], pos[n], ver[n], min, r, p = 0, stop = 1, milking_tym[n], idle_tym[n], max_end = 0, max_m = 0, max_i = 0;

    for( i = 0; i<n; i++ ){
        fscanf(fin, "%d %d", &begin[i], &end[i]);
        ver[i] = 0;
        idle_tym[i] = 0;
        milking_tym[i] = 0;
    }

    for( i = 0; i<n; i++ ){
        if( ver[i] == 0 && stop == 1 ){
            min = begin[i];
            r = i;
            stop = 0;
        }
        else if( ver[i] == 1 && stop == 1 ) continue;

        if( begin[i]<min && ver[i] == 0 ){
            min = begin[i];
            r = i;
        }

        if( i == n-1 ){
            sort[p] = min;
            pos[p] = r;
            ver[r] = 1;
            i = -1;
            stop = 1;
            p++;
            if( p == n ) break;
        }
    }
    p = 0;
    r = 0;

    for( i = 0; i<n; i++ ){
        if( end[ pos[i] ] >= max_end ){
            max_end = end[ pos[i] ];
        }

        if( i+1 == n ){
            milking_tym[p] = end[ pos[i] ] - sort[i];
            if( milking_tym[p] > max_m ) max_m = milking_tym[p];

            break;
        }

        for( j = i+1; j<n; j++ ){
            if( sort[j] <= max_end ){
                if( end[ pos[j] ] > max_end ) max_end = end[ pos[j] ];
                else if( j == n-1 ){
                    milking_tym[p] = max_end - sort[i];
                    if( milking_tym[p] >= max_m ) max_m = milking_tym[p];

                    i = j;
                    break;
                }

                continue;
            }
            else if( sort[j] > max_end ){
                milking_tym[p] = max_end - sort[i];
                idle_tym[p] = sort[j] - max_end;
                if( milking_tym[p] >= max_m ) max_m = milking_tym[p];
                if( idle_tym[p] >= max_i ) max_i = idle_tym[p];

                max_end = 0;
                i = j - 1;
                p++;
                break;
            }
        }
    }

    fprintf(fout, "%d %d\n", max_m, max_i);

    return 0;
}
