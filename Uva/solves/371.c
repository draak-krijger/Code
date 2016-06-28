#include <stdio.h>
long long int max(long long int a,long long int b)
{
    if(a>b)
        return a;
    else return b;
}
long long int min(long long int a,long long int b)
{
    if(a<b)
        return a;
    else return b;
}
int main()
{
    long long int a,b,c,d,e,f,i,j=0;
    while(scanf("%lld %lld",&a,&b))
    {
        if(a==0 &b==0)
            break;
        c=f=max(a,b);
        d=min(a,b);
        b=0;
        while(1)
        {
            i=0;
            a=c;
            while(1)
            {
                if(a%2==0)
                    a=a/2;
                else
                    a= 3*a+1;
                i++;
                if(a==1)
                    break;
            }
            if(i>b)
            {
                e=c;
            }
            if(i==b)
            {
                e=c;
            }
            b=max(b,i);
            if(c==d)
                break;
            c--;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",d,f,e,b);
    }
    return 0;
}
