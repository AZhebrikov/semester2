#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "fun.h"

int main(void)
{int n,*m0,*msave,*tmp,*m,i;time_t t1,t2;
 n=100+0*1000000;
 printf("%d\n",n);
 m0=(int*)malloc(sizeof(m0[0])*n);
 tmp=(int*)malloc(sizeof(m0[0])*(  ((n+1)<(1<<16))?(1<<16):(n+1)  ) );
 m=(int*)malloc(sizeof(m0[0])*n);
 msave=(int*)malloc(sizeof(m0[0])*n);
    //------------------
    for(i=0;i<n;i++)m0[i]=rand()%n;
    //------------------
  if(n<=100)
   {
    memcpy(msave,m0,sizeof(m0[0])*n);
    BubbleSort(msave,n);
   }
 //------

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);Sort1(m,n,tmp);time(&t2);
 printf("Sort1: dt=%d\n",(int)(t2-t1));
 if(n>100)memcpy(msave,m,sizeof(m0[0])*n);
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("Sort1: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);Sort1OMP(m,n,tmp);time(&t2);
 printf("Sort1OMP: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("Sort1: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);Sort2(m,n,tmp);time(&t2);
 printf("Sort2: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("Sort2: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);Sort2OMP(m,n,tmp);time(&t2);
 printf("Sort2OMP: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("Sort2OMP: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);QSort1(m,0,n-1);time(&t2);
 printf("QSort1: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("QSort1: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);QSort2(m,0,n-1);time(&t2);
 printf("QSort2: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("QSort2: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);QSort2_(m,0,n-1);time(&t2);
 printf("QSort2_: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("QSort2_: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);HeapSort(m,n);time(&t2);
 printf("HeapSort: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("HeapSort: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);CountSort(m0,n,n,tmp,m);time(&t2);
 printf("CountSort: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("CountSort: error i=%d\n",i);

 memcpy(m,m0,sizeof(m0[0])*n);
 time(&t1);DSort(m0,n,tmp,m);time(&t2);
 printf("DSort: dt=%d\n",(int)(t2-t1));
 for(i=0;i<n;i++)if(m[i]!=msave[i])printf("DSort: error i=%d\n",i);

 //------

 printf("done\n");
 free(msave);msave=NULL;
 free(m);m=NULL;
 free(m0);m0=NULL;
 free(tmp);tmp=NULL;
}
