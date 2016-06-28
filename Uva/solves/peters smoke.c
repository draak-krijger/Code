#include<stdio.h>
int main()
{
    long int n,a,b,c;
    while((scanf("%ld %ld",&a,&b)) != EOF)
    {
        c=a;
        n=a;
        if(b>1)
        {
            while(a>=b)
            {
                c = a;
                a=a/b;
                n+=a;
                a = a+(c%b);
            }
        }
        printf("%ld\n",n);
    }
    return 0;
}

