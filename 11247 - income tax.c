#include<stdio.h>
int main()
{
    long long m ,m_t,x;
    int i ;
    while(scanf("%lld %lld",&m ,&x) == 2)
    {
        if(m==0 && x==0)
            break;
        if(m == 1 || x == 100 || x ==0)
        {
            printf("Not found\n");
            continue ;
        }
        m_t = (100*(m-1))/(100-x);
        if((100*(m-1))%(100-x) == 0)
            m_t--;
        if(m_t < m)
            printf("Not found\n");
        else
            printf("%lld\n",m_t) ;
    }
    return 0 ;
}

