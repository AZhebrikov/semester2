#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <ctype.h>

int main(void)
{int err,i,n;SStudent **m;
 printf("Pocledovatelnost schitevaetsa:\n");
 err=STRCput("KEK.txt",&m,&n);
 if(err){printf("Error1 %d",err);return 0;}
 printf("Pocledovatelnost schitana.\nVivod pocledovatelnosti:\n");
 err=vivod(m,n);
 printf("Vivod pocledovatelnoste oconchen.\nMachalo sortirovki:\n");
 err=Vov(m,n);
 if(err<0){printf("Error2 %d",err);return 0;}
 else if(err==1)printf("Takoe racpredelenie ne vozmozhno.");
 else printf("Takoe racpredelenie  vozmozhno.");
 printf("Sortirovka oconchena.\n");
 err=vivod(m,n);
 printf("Vivod pocledovatelnoste oconchen.\n");
 for(i=0;i<n;i++)free(m[i]);free(m);m=NULL;
return 0;
}






/*
Vov(SStudent **m,int n);
vivod(SStudent **s,int n);
STRCput(const char *fs,SStudent ***s,int *n);
*/
