#include <stdio.h>

int max(int a,int b)

{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a,int b)

{
    if(a<b)
        return a;
    else
        return b;

}

int main()

{
    int a,b,c,d,t,e,m;
    while(scanf("%d %d",&a,&b)==2)
    {
        m=0;
        e=c=max(a,b);
        d=min(a,b);

        while(e>(d-1))
        {
            t=0;
            c=e;

            while(1)
            {
                t++;
                if(c==1)
                    break;
                if(c%2 !=0)
                    c=c*3+1;
                else
                    c=c/2;
            }

            m=max(m,t);
            e--;
        }
        printf("%d %d %d\n",a,b,m);
    }

    return 0;
}

