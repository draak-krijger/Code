#include <stdio.h>
int main ()
{
    int marks_count[11],total_marks[]={86,86,83,90,88,93,85,80,99,100},i;
    for(i=0;i<101;i++)
    {
        marks_count[i]=0;
    }
    for(i=0;i<11;i++)
    {
        marks_count[total_marks[i]]++;
    }
    for(i=90;i<101;i++)
    {
        printf("marks:%d count:%d\n",i,marks_count[i]);
    }
    return 0;
}
