#include <stdio.h>

int bubble(int a[])
{
    int i , j , temp ;

    for(i=0 ; i<9 ; i++)
    {
        for(j=0 ; j<9-i ; j++)
        {
            if(a[j+1]>a[j])
            {
                temp = a[j] ;
                a[j] = a[j+1];
                a[j+1] = temp ;
            }
        }
    }
}
int main()
{
    char s[10][150];
    int i , j , t , visitor[10], visitor2[10] ;

    while(scanf("%d",&t) != EOF)
    {
        for(j=0 ; j<t ; j++)
        {
            for(i=0 ; i<10 ; i++)
            {
                scanf("%s %d",s[i],&visitor[i]);
                visitor2[i] = visitor[i];
            }

            bubble(visitor);

            printf("Case #%d:\n",j+1);
            for(i=0 ; i<10 ; i++)
            {
                if(visitor[0] == visitor2[i])
                    printf("%s\n",s[i]);
            }
        }
    }
    return 0 ;
}

