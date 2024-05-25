#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"

int STRput1(const char *fs,int ***m, int *q)
{FILE *f;int count=0,strcount=0,k,i,l;char str[256],num[256];
 char *nacal;
 f=fopen(fs,"r");if(f==NULL)return -1;
        while(fgets(str,256,f))
        {strcount++;for(nacal=str;(sscanf(nacal,"%s%n",num,&k)==1);nacal=nacal+k)count++;
        }
 *q=strcount;
 rewind(f);
 *m=(int**)malloc( (strcount+1)*sizeof(int*) + (count+strcount)*sizeof(int));
 (*m)[0]=(int*)((*m)+strcount+1);(*m)[1]=(*m)[0]+(*q);
        for(l=1;(fgets(str,256,f)!=0)&&(l<=(*q));l++)
        {for(i=0,nacal=str;sscanf(nacal,"%d%n",(*m)[l]+i,&k)==1;nacal=nacal+k,i++);
         (*m)[0][l-1]=i;if(l<(*q)){(*m)[l+1]=(*m)[l]+i;}
        }
return 0;
}



/*int STRput1(const char *sf,int ***m, int *q)
{FILE *f;int count=0,strcount=0,k,i,l;char str[256],num[256];
 char *nacal;
 f=fopen(sf,"r");if(f==NULL)return -1;
        while(fgets(str,256,sf))
        {strcount++;for(nacal=str;(sscanf(nacal,"%s%n",num,&k)==1);nacal=nacal+k)count++;
        }
 *q=strcount;
 rewind(sf);
 *m=(int**)malloc( (strcount+1)*sizeof(int*) + (count+strcount)*sizeof(int));
 (*m)[0]=(int*)((*m)+strcount+1);(*m)[1]=(*m)[0]+(*q);
        for(l=1;(fgets(str,256,sf)!=0)&&(l<=(*q));l++)
        {for(i=0,nacal=str;sscanf(nacal,"%d%n",(*m)[l]+i,&k)==1;nacal=nacal+k,i++);
         (*m)[0][l-1]=i;if(l<(*q)){(*m)[l+1]=(*m)[l]+i;}
        }
 fclose(sf);
return 0;
}*/


int search1(const char *fs,int **m,int q)
{FILE *f;
 f=fopen(fs,"w");
 if(f==NULL)return -1;
 int d=m[0][0],i,k,l;
 for(i=1;i<q;i++) {if(m[0][i]>d)d=m[0][i];}
 for(l=0;l<d;l++)
         {for(i=1;i<=q;i++)
                {for(k=0;(k<m[0][i-1])&&(l<m[0][i-1]);k++)
                        {if( (m[i][k]>=m[i][l]) && (k!=l) ){goto qr;}
                        }
                }
          break;
          qr:;
         }
 if(l==d);
 else
 {for(i=1;i<=q;i++)
      {for(k=l;k<(m[0][i-1]-1);k++){m[i][k]=m[i][k+1];}
       if(l<m[0][i-1])m[0][i-1]--;
      }
 }
  for(i=1;i<=q;i++)
   {for(k=0;k<m[0][i-1];k++){fprintf(f,"%d  ",m[i][k]);}
    fprintf(f,"\n");
   }
 fclose(f);
return 0;
}
