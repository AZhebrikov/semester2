#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"fun.h"

/*int STRput(const char *fs,int ***m, int *q)
{FILE *f;int count=0,strcount=0,k,i,l;char str[256],num[256];
 char *nacal;
 f=fopen(fs,"r");if(f==NULL)return -1;
	while(fgets(str,256,f))
	{strcount++;for(nacal=str;(sscanf(nacal,"%s%n",num,&k)==1);nacal=nacal+k)count++;
	}
 *q=strcount;
 rewind(f);
 *m=(int**)malloc(strcount*sizeof(int*) + (count+strcount)*sizeof(int));
 (*m)[0]=(int*)((*m)+strcount);
 	for(l=0;(fgets(str,256,f))&&(l<(*q));l++)
	{for(i=0,nacal=str;sscanf(nacal,"%d%n",(*m)[l]+i+1,&k)==1;i++,nacal=nacal+k);
	 if(l<*q-1){(*m)[l+1]=(*m)[0]+i+1;}(*m)[l][0]=i;
	}
return 0;
}*/

//int search(const char *fs, int **m,int q)
{FILE *f;f=fopen(fs,"w");
 if(f==NULL)return -1;
 int d=m[0][0],i,k,l,p;
		/*
		    for(i=0;i<q;i++)
		    {for(k=1;k<=m[i][0];k++){printf("%d  ",m[i][k]);}
		     printf("\n");
		    }
		*/
 for(i=1;i<q;i++) {if(m[i][0]>m[0][0])d=m[i][0];}
 for(l=1;l<=d;l++)
	 {for(p=0,i=0;i<q;i++)
		{for(k=1;k<=m[i][0];k++)
			{if( (m[i][k]<=m[i][l]) && (k!=l) ){goto qr;}
			}
		}
	  break;
	  qr:;
	 }
 if(l==d);
 else
 {for(i=0;i<q;i++)
      {for(k=l;k<m[i][0];k++){m[i][k]=m[i][k+1];}
       m[i][0]--;
      }
 }
		/*
  		 for(i=0;i<q;i++)
  		  {for(k=1;k<=m[i][0];k++){printf("%d  ",m[i][k]);}
  		   printf("\n");
    		}
		*/

 for(i=0;i<q;i++)
 {for(k=1;k<=m[i][0];k++){fprintf(f,"%d  ",m[i][k]);}
  fprintf(f,"\n");
 }
return 0;
}
 /*int nahodit(int **m,int q,int *w)
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
  }*/

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

/*int STRput2(const char *fs,int ***m, int *q)
{FILE *f;int count=0,strcount=0,k,i,l;char str[256],num[256];
 char *nacal;int *n;
 f=fopen(fs,"r");if(f==NULL)return -1;
        while(fgets(str,256,f))strcount++;
	n=(int*)malloc(strcount*sizeof(int));rewind(f);
	while(fgets(str,256,f))
        {for(i=0,nacal=str;(sscanf(nacal,"%s%n",num,&k)==1);nacal=nacal+k,i++)strcount++;
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
}*/

