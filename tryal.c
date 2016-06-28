#include <stdio.h>
int sort (int jolly[] , int j)
{
    int x , y ,temp ;
    for(x=0;x<=j-1;x++){
            for(y=x+1;y<=j-1;y++){
                if(jolly[y]<jolly[x]){
                    temp=jolly[y];
                    jolly[y]=jolly[x];
                    jolly[x]=temp;
                }
            }
        }
}
int main()
{
    int jolly[5],i ;

    while(1)
    {
    for(i=0 ;i<5 ; i++)
        scanf("%d",&jolly[i]);

    sort(jolly,5);

    for(i=0 ; i<5 ; i++)
        printf("%d ",jolly[i]);

    }

}
