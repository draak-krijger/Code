// Base Conversation
#include<bits/stdc++.h>

long long POW(int a, int b)
{
    long long i, ans = 1;

    for(i=1; i<=b; i++)
        ans*=a;
    return ans;
}

int main()
{
    long long b1, b2, i, j, temp, quo, num, len, m;
    bool tag;
    char s[50], n[50];

    while(scanf("%lld %lld %s", &b1, &b2, s) == 3)
    {
        len = strlen(s);
        num = 0;
        m=0;
        tag = false;

        for(i=len-1; i>=0; i--)
        {
            if(isdigit(s[i]))
                temp = s[i] - 48;

            else
                temp = s[i] - 55;

            if(temp >= b1 || temp<0)
                tag = true;

            num += (temp)*POW(b1, m++);
        }

        if(tag)
        {
            printf("%s is an illegal base %lld number\n", s, b1);
            continue;
        }

        if(num == 0)
        {
            printf("%s base %lld = 0 base %lld\n", s, b1, b2);
            continue;
        }
        i=0;
        while(num)
        {
            temp = num%b2;
            if(temp<10)
                temp = temp + 48;
            else temp = temp + 55 ;
            n[i++]=temp;
            num /= b2;
        }

        printf("%s base %lld = ", s, b1);
        for(j=i-1; j>=0; j--)
            printf("%c", n[j]);
        printf(" base %lld\n", b2);

    }
    return 0;

}
