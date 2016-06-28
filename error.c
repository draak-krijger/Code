#include<stdio.h>
#include<math.h>
int main()
{
long n,b,i,bin,c,d,num,rev,bin2;
while(scanf("%ld",&n)==1)
{
num=n;
bin=0;
rev=0;
bin2=0;
if(n==2)
    {
    printf("%ld is prime.\n",n);
    continue;
    }
b=(int)sqrt(n);
if(n%2==0)
{
bin=1;
printf("%ld is not prime.\n",n);
}
else
for (i=3;i<=b;i+=2)
if (n%i==0)
{
printf("%ld is not prime.\n",n);
bin=1; break;
}
if(bin==0)
    {
    for(i=1;i!=0;i++)
        {
        d=num%10;
        num=num/10;
        rev=rev*10+d;
        if(num==0)
        break;
        }
    if(rev==n)
        {
        printf("%ld is prime.\n",n);
        continue;
        }
    c=(int)sqrt(rev);
    if(rev%2==0)
        {
        bin2=1;
        printf("%ld is prime.\n",n);
        }
    else
    for (i=3;i<=c;i+=2)
        if (rev%i==0)
            {
            printf("%ld is prime.\n",n);
            bin2=1; break;
            }
    if(bin2==0)
        printf("%ld is emirp.\n",n);

    }
}
return 0;
}
