#include<stdio.h>
#include<stdlib.h>
#include"fun.h"


int IRput(const char *sf,int **m, int *n)
{FILE *f;int i,d;
 f=fopen(sf,"r");
 if(f==NULL)return -1;
 if(fscanf(f,"%d",&d)!=1){fclose(f);return -1;}
 for(i=0,*n=1;(fscanf(f,"%d",&d)==1);i++)(*n)++;
 *m=(int*)malloc(sizeof(int)*(*n));
 if(*m==NULL){fclose(f);return -1;}
 rewind(f);
 for(i=0;i<*n;i++)fscanf(f,"%d",(*m)+i);
 fclose(f);
 return 0;
}



int Puzrsort(int *m, int n)
{int i,k,l;
 for(i=0;i<n;i++)
 	{for(k=1;k<n-i;k++)
		{if(m[k-1]>m[k]){l=m[k-1];m[k-1]=m[k];m[k]=l;}
		}
 	}
return 0;
}


int main(void)
{int *q,w,*m,n,err,k,i,l=-1;
 FILE *f;f=fopen("output.txt","w");
 if(f==NULL)return -1;
 printf("1\n");
 err=IRput("ina.txt",&q,&w);if(err){printf("2\n");return -1;}
 err=IRput("inb.txt",&m,&n);if(err){printf("3\n");return -1;}
 if(w!=n){printf("4/n");return -1;}
 if(n<=2){printf("5/n");return -1;}  //fprintf(f,"%d",l);
 	for(i=0;i<n;i++)
	{printf("%d  %d\n",q[i],m[i]);
	}
 err=Puzrsort(m,n);
 err=Puzrsort(q,w);
	printf("\n");
	for(i=0;i<n;i++)
        {printf("%d  %d\n",q[i],m[i]);
        } 
for(k=1;k<n-1;k++)
 	{for(i=1,err=0;i<n;i++)
      		{if( ((q[k]-m[k])*(q[k-1]-m[k-1]))<0) {err++;}
                 if( ((q[k+1]-m[k+1])*(q[k]-m[k]))>0) {err++;}
                 if( ((q[k-1]-m[k-1])*(q[k+1]-m[k+1]))>=0) {err++;}
		 if( (((q[i]-m[i])*(q[i-1]-m[i-1]))<=0)&&(i<k) ){err++;}
                 if( (((q[i]-m[i])*(q[i-1]-m[i-1]))<=0)&&(i>k+1) ){err++;}
		}
         if(err==0){l=k;break;}
	}
 fprintf(f,"%d",l);free(m);fclose(f);m=NULL;
printf("6/n");return 0;
}
