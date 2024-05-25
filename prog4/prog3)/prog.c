#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "fun.h"
int main(void)
{char word[512];int err,k;
 word[0]='\0';
 err= search("KOK.txt", word);
 if(err==-1){printf("Error.");return -1;}
 if(err==0){printf("No word found.");return 0;}
 printf("The word returned by function:\n%s\n",word);
return 0;
}


