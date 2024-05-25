#include<stdio.h>
#include<stdlib.h>
#include "fun1.h"
int Input(const char *sf, int**m, int *n)
{FILE *f;int i;
 f=fopen(sf,"r");
 if(f==NULL)return -1;// file can't open
 if(fscanf(f,"%d",n)!=1) {fclose(f); return -2;}// file is empty
  *m=(int*)malloc(*n*sizeof(int));
  if(*m==NULL) {fclose(f);return -3;}// memory allocation error
  for(i=0;i<*n;i++)
   if(fscanf(f,"%d",(*m)+i)!=1) {fclose(f);free(*m);*m=NULL;return -4;}// Can't cope
  fclose(f);
return 0;
}


int wow(int*m,int u,int n)
{int k,d,f=0,f1,i,p=0;
 if(n==1){printf("%d %d %d\n",m[u],u,u);return 0;}
 for(i=u;i<n-f;i++)
   {d=m[i];k=0;p=0;
    while(i<n)
      {p+=1;if(m[i]==d){k=p;}  }
    if(f<k){f=k;f1=i;}
   }
 printf("%d %d %d\n",m[f1],f1,f1+f);
 if(f1>u)wow(m,u,f1-u);
 if((f1+f)<n-1)wow(m,f1+f+1,n-1-f1-f);
 if(f>2)wow(m,f1+1,f-2);
return 0;
}

