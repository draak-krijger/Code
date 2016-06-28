#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std ;

int main()
{
    set<string>word ;
    string s ;
    set<string>::iterator ik ;
    char s1[1000];
    int l , i , j ;

    //freopen("a.txt","r",stdin);

    while(cin >> s)
    {
         l = s.size() ;
         memset(s1 , 0 , sizeof s1);
         for(i=0 ,j=0 ; i<l ; i++)
         {
             if(isalpha(s[i]))
             {
                 s1[j] = tolower(s[i]);
                 j++;
             }
         }
          word.insert(s1);
    }

    for(ik = word.begin() ; ik != word.end() ; ik++)
        cout<<*ik<<endl ;

    return 0 ;
}
