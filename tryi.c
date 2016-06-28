#include<stdio.h>

int main()
{
    int n,num[3000],i,j,k,x,y,l,jolly[3000],r=0,val=0,temp;
    char ch;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
        }

        for(j=0;j<i-1;j++){
            jolly[j]=num[j+1]-num[j];
            if(jolly[j]<0){
                jolly[j]*=(-1);
            }
        }

        for(x=0;x<=j-1;x++){
            for(y=x+1;y<=j-1;y++){
                if(jolly[y]<jolly[x]){
                    temp=jolly[y];
                    jolly[y]=jolly[x];
                    jolly[x]=temp;
                }
            }
        }

        r=0 ;
        for(k=0;k<j-1;k++){
            val=jolly[k+1]-jolly[k];

            if(val != 1)
            {
                r=1 ;            // there is no need make it positive naumber .... if value of  "val"  is not 1 then its not jolly so there is no need to continue loop .
                break ;
            }
        }

        if(r==0){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    return 0;
}
