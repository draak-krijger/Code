#include <bits/stdc++.h>

using namespace std;

bool check[30] , ck ;
stack<char>q ;

void reset();

int main()
{
    int leng , n , right , left , mid ;
    char st[150] ;

    while(scanf("%d %s",&n,st) != EOF)
    {
        leng = strlen(st);
        mid = leng/2 ;

        reset();

        if(leng<2*n-1)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        for(int i=0 ; i<leng ; i++)
        {
            if(isalpha(st[i]))
                check[st[i] - 'a'] = true;

            if(st[i]-'a' >=n)
                ck = true;
        }

        if(!ck)
        {
            for(int i=0 ; i<n ; i++)
            {
                if(!check[i])
                    q.push(i+'a');
            }

            if(leng&1)
            {

                if(st[mid] == '?')
                {
                    if(q.empty())
                        st[mid] = 'a';

                    else
                    {
                        st[mid] = q.top();
                        q.pop();
                    }
                }
                for(int i=1 ; i<=mid ; i++)
                {
                    right = mid+i;
                    left = mid-i;

                    if(isalpha(st[right]) && isalpha(st[left]))
                    {
                        if(st[right] != st[left])
                        {
                            ck = right;
                            break;
                        }
                    }

                    else if(isalpha(st[left]) && st[right] == '?')
                        st[right] = st[left];

                    else if(isalpha(st[right]) && st[left] == '?')
                        st[left] = st[right];

                    else
                    {
                        if(q.empty())
                        {
                            st[left] = 'a';
                            st[right] = 'a';
                        }

                        else
                        {
                            st[left] = q.top();
                            st[right] = q.top();
                            q.pop();
                        }
                    }
                }
            }

            else
            {
                 for(int i=0 ; i<mid ; i++)
                {
                    right = mid+i;
                    left = mid-i-1;

                    if(isalpha(st[right]) && isalpha(st[left]))
                    {
                        if(st[right] != st[left])
                        {
                            ck = right;
                            break;
                        }
                    }

                    else if(isalpha(st[left]) && st[right] == '?')
                        st[right] = st[left];

                    else if(isalpha(st[right]) && st[left] == '?')
                        st[left] = st[right];

                    else
                    {
                        if(q.empty())
                        {
                            st[left] = 'a';
                            st[right] = 'a';
                        }

                        else
                        {
                            st[left] = q.top();
                            st[right] = q.top();
                            q.pop();
                        }
                    }
                }
            }

            if(!q.empty())
                ck = true;
        }

        if(ck)
            printf("IMPOSSIBLE\n");

        else
            printf("%s\n",st);
    }
    return 0;
}

void reset()
{
    ck = false;
    fill(check,check+29,false);

    while(!q.empty())
        q.pop();
}
