#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fun1.h"

int main(void)
{int k,n,*m0,*msave,*tmp,*m,i;time_t t1,t2;
 n=10000+0*1000000;
 printf("%d\n",n);
 m0=(int*)malloc(sizeof(m0[0])*n);
 tmp=(int*)malloc(sizeof(m0[0])*(  ((n+1)<(1<<16))?(1<<16):(n+1)  ) );
 m=(int*)malloc(sizeof(m0[0])*n);
 msave=(int*)malloc(sizeof(m0[0])*n);
    //------------------
    for(i=0;i<n;i++)m0[i]=rand()%n;
    //------------------
 time(&t1);
 for(k=0;k<n;k++)
  if(Stat1(m0,n,tmp,msave,k)!=Stat2(m0,n,tmp,k))
   printf("error=k%d",k);
 time(&t2);
 printf("---\nTime=%d\n---",(int)(t2-t1));
 //------
 time(&t1);
 for(k=0;k<n;k++)
  if(Stat1(m0,n,tmp,msave,k)!=Stat3(m0,n,tmp,msave,k))
   printf("error=k%d",k);
 time(&t2);
 printf("---\nTime=%d\n---",(int)(t2-t1));
 //------
 printf("done\n");
 free(msave);msave=NULL;
 free(m);m=NULL;
 free(m0);m0=NULL;
 free(tmp);tmp=NULL;
}
