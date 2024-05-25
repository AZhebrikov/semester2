#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
int main()
{int **m,q,w,i,k,l,err,d;
 FILE *f;f=fopen("data.res","w");
 if(f==NULL)return -1;
 err=IRput("data.dat",&m,&q,&w);
 if(err){printf("%d",err);return -1;} //Ne rabotaet programma

 printf("Before editing:\n");
 for(i=0;i<q;i++)
 {for(k=0;k<w;k++)
  printf("%d  ",m[i][k]);
 printf("\n");
 }

 err = nahodit(m,q,&w);
 	/* for(i=0,d=0;i<w;i++)
 	{ for(k=0;k<q;k++)
 		{ for(l=0;l<w;l++)
   			 { if(m[k][i]<=m[k][l]){d++;break;}
    		 	 }
       		  if(d)break;
  		}
  	if(d==0)break;
  	if(d)d=0;
 	}
 	if(i==w)return 1;
 	for(k=0;k<q;k++)
	 { for(l=i+1;l<w;l++)
  		{m[k][l-1]=m[k][l]
  		}
 	}w=w-1; */
 fprintf(f,"%d %d\n",q,w);
 for(i=0;i<q;i++)
 {for(k=0;k<w;k++)
 fprintf(f,"%d  ",m[i][k]);
 fprintf(f,"\n");
 }

 printf("After editing:\n");
 for(i=0;i<q;i++)
  {for(k=0;k<w;k++)
   printf("%d  ",m[i][k]);
  printf("\n");
  }

free(m);m=NULL;fclose(f);
return 0;
}



