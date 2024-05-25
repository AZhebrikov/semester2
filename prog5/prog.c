#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"

int main(void)
{int err,**m,q,k,i;
 err = STRput1("datares.txt",&m,&q);
 if(err)return -1;
	printf("Before editing:\n");
 	for(i=0;i<q;i++)printf("%d ",m[0][i]);printf("\n");
	for(i=1;i<=q;i++)
 	 {for(k=0;k<m[0][i-1];k++){printf("%d  ",m[i][k]);}
          printf("\n");
  	 }
 err = search2("dataout.txt",m,q);
	printf("After  editing:\n");
	for(i=1;i<=q;i++)
         {for(k=0;k<m[0][i-1];k++){printf("%d  ",m[i][k]);}
          printf("\n");
         }
free(m);m=NULL;
return 0;
}

