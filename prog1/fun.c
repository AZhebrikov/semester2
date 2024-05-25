#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
int IRput(const char*sf,int***m,int *q,int*w)
{FILE *f;int i,k;
 f=fopen(sf,"r");
 if(f==NULL)return -1;  //Can't open file
 if(fscanf(f,"%d",q)!=1){fclose(f);return -2;}  //File if empty
 if(fscanf(f,"%d",w)!=1){fclose(f);return -3;}  //Ne zadada dlina macciva
 *m= (int**)malloc(  (sizeof(int)*(*q)*(*w)) + (sizeof(int*)*(*q))  );
 if(*m==NULL){fclose(f);return -4;}  //Memory allocation error
 (*m)[0]=(int*)(*m+*q);
 for(i=1;i<(*q);i++)(*m)[i]=(*m)[i-1]+(*w);
 for(i=0;i<(*q);i++)
  {for(k=0;k<(*w);k++)
   if(fscanf(f,"%d",((*m)[0]+(*w)*i+k))!=1){fclose(f);free((*m));*m=NULL;return-5;}  //File isporchen
  }
return 0;
}
int nahodit(int **m,int q,int *w)
{int i,k,l,d;
for(i=0,d=0;i<*w;i++)
 { for(k=0;k<q;k++)
        { for(l=0;l<*w;l++)
                 { if( (m[k][i]<=m[k][l])&&(l!=i)){d++;break;}
                 }
         if(d)break;
        }
  if(d==0)break;
  if(d)d=0;
 }
 if(i==*w)return 0;
for(k=0;k<q;k++)
 { for(l=i+1;l<*w;l++)
        {m[k][l-1]=m[k][l];
        }
 }*w=*w-1;
return 0;
}
