#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
void main()
{int i,err,n;SList** l;
 err=NWSpis("data.dat",&l,&n);
 if(err>=0)
  {	printf("%d\n",n);
   	for(i=0;i<n;i++)Vivod(l[i]);
   	printf("---\n");
   err=Proga(l,&n);
   	for(i=0;i<n;i++)Vivod(l[i]);
   	printf("---\n");
   err=VivodF("data.res",l,n);
   for(i=0;i<n;i++)Delete(l[i]);free(l);l=NULL;
  }
 else printf("%d\n",err);
return;
}

