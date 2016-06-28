#include<stdio.h>
#include<malloc.h>

int main()
{
   char *ch;
   ch=malloc(20*sizeof(char));
   gets(ch);
   puts(ch);
   free(ch);
    return 0;
}
