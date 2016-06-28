#include <bits/stdc++.h>
using namespace std;

//programme er runtime calculate korar sample code

int main()
{
    clock_t beginn, endd;
    double time_spent;
    beginn = clock();
    while(1)
    {
        endd = clock();
        time_spent = (double)(endd - beginn) / CLOCKS_PER_SEC;

        if(time_spent>2.00)
        {
            printf("ok pass\nWelcome in developer World !!! \n");
            break;
        }
    }
    endd = clock();
    time_spent = (double)(endd - beginn) / CLOCKS_PER_SEC;
    printf("%lf\n",time_spent);
    return 0;
}
