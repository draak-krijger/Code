#include <stdio.h>
int func(int a)
{
    int sum = 0;
    while(a > 0)
        {
            if(a < 10){
                sum +=a ;
                a = a/10 ;
            }
            else{
                sum += (a%10);
                a = a/10;
            }
        }
        return sum;
}
int main()
{
    int a , sum ;
    while(scanf("%d",&a) == 1)
    {
        if(a==0)
            break;
        sum= func(a);
        while(sum >9){
        a =sum;
        sum = func(a);
        }
        printf("%d\n",sum);
    }
    return 0;
}

