#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <ctype.h>

void main()
{SStudent **m;int i,n,err,d;char word[10];
 err=IMPyt("data1.txt",&m,&n);
 if(err==0)
    {ka:;
     Vivod(m,n);
       printf("\n=============\nSortGroup\n==============\n");
     SortGroup_N(m,n,1);
       printf("\n==========\n\n============\n");
      Vivod(m,n);
       printf("\n=======\nSortirovka nachata.\n=========\n");
     Ratingsort(m,n);
       printf("\n======\nSortirovka okonchena.\n=========\n");
     Vivod(m,n);
       printf("\n========\nRazbivaem 10/.../10.\n=========\n");
     d=VivodR(m,n);printf("\n=========\nIsclichenei podlegat %d ychenikov\n=======\n",d);
     err=DelSS("Dilit.txt",m,&n,d,0);
        if(err==0)
         	 {
           	  kaa:;
          	  Vivod(m,n);
                   printf("\n============\nStarost\n==============\n");
    	           Starost(m,n);
                   printf("\n=================\n\n==================\n");
                  Vivod(m,n);




       		 }
        else
          {printf("---\nError 'DelSS' .\nFile not found.Prodolzit raboty bez vivoda dannih v fail?\nYES or NO?\n");
           scanf("%s",word);
            if(strcmp(word,"YES")==0)
            {
             err=DelSS("",m,&n,d,1);
             goto kaa;
            }
            else goto nc;
          }
  }
 else if(err==1)
  {
   printf("---\nError 'IMPyt' %d \nIs chitannih studentov ne vce cmogli bit chitani.\nProdolzit raboty?\nYES or NO?\n---\n",err);
   scanf("%s",word);
   if(strcmp(word,"YES")==0){err=0;goto ka;}
   else goto nc;
  }
 else
 nc:;
 for(i=0;i<n;i++){free(m[i]);m[i]=NULL;}
 free(m);m=NULL;
return;
}
