#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{char word[512];int err;
 err= search("KEK.txt", word);
 if(err)return -1;
 printf("\n%s\n",word);
return 0;
}


