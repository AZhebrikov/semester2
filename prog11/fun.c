#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <ctype.h>
#define SWAP(a,b) {(t)=(a);(a)=(b);(b)=(t);}

//------------------------------------------------------------------------------------------------------------------------
int IMPyt(const char *fs,SStudent*** m,int *n)
{char str[512];FILE *f;char word[512];
 char *nacal;int i,l=0,err=0;
 (*n)=0;
 f=fopen(fs,"r");if(f==NULL)return-1;
     while( (fgets(str,512,f)!=NULL)&&(sscanf(str,"%s",word)==1) )(*n)++;
     if((*n)==0){fclose(f);return -2;}
 (*m)=(SStudent**)malloc((*n)*sizeof(**m));
     if((*m)==NULL){fclose(f);return -3;}
 rewind(f);
	 for(i=0;(fgets(str,512,f)!=NULL)&&(sscanf(str,"%s",word)==1);i++)
 	 {
	  (*m)[i]=(SStudent*)malloc(sizeof(**(*m)));
  	  for(nacal=str;(sscanf(nacal,"%s",word)==1)&&
                        (   sscanf(nacal,"%d%n",&( (*m)[i]->group ),&l)!=1  );)
 	    {
 	     while(isspace(*(nacal) )   )nacal++;
 	     while(isspace(*(nacal) )==0)nacal++;
 	    }
 	  *nacal='\0';
          strcpy((*m)[i]->name,str);
 	  nacal+=l;
          if(sscanf(nacal,"%d%n",&( (*m)[i]->school ),&l)!=1){err=-1;goto nc;}else nacal+=l;
          if(sscanf(nacal,"%d%n",&( (*m)[i]->IsElder ),&l)!=1){err=-1;goto nc;}else nacal+=l;
          if(sscanf(nacal,"%g%n",&( (*m)[i]->Rating ),&l)!=1){err=-1;goto nc;}else nacal+=l;
          nc:;if(err){free((*m)[i]);i--;err=0;}
          nacal=NULL;l=0;
 	 }
 if(i<(*n)){(*n)=i;fclose(f);return 1;}
 else
 fclose(f);
return 0;
}
//-------------------------------------------------------------------------------------------------------------------
void Vivod(SStudent **m,int n)
{int i;
 printf("%30s %7s %7s  %7s %7s\n","Name","Group","School","IsElder","Rating");
 for(i=0;i<n;i++)
 {printf("%30s %7d %7d %7d %7.4g\n",m[i]->name,m[i]->group,m[i]->school,m[i]->IsElder,m[i]->Rating);
 }
return;
}
//--------------------------------------------------------------------------------------------------------------------
void Ratingsort(SStudent **m,int n)
{
 int i,k;SStudent *d;
 for(i=0;i<n;i++)
   {for(k=n-1;k>i;k--)
       {if( (m[k-1]->Rating) < (m[k]->Rating) )
          {d=m[k-1];m[k-1]=m[k];m[k]=d;
          }
       }
   }
}
//--------------------------------------------------------------------------------------------------------------------
int VivodR(SStudent **m,int n)
{int i,d;
 d=n*10/100;
 printf("%30s %7s %7s  %7s %7s\n","Name","Group","School","IsElder","Rating");
 for(i=0;i<n;i++)
 {
  if(i==d)printf("----\n");
  if(i==n-d)printf("---\n");
  printf("%30s %7d %7d %7d %7.4g\n",m[i]->name,m[i]->group,m[i]->school,m[i]->IsElder,m[i]->Rating);
 }
return d;
}
//---------------------------------------------------------------
int DelSS(const char *fs,SStudent **m,int *n,int d,int a)
{int i;FILE *f;
 if(d==0)goto nc;
 if(a==0)
   {
    f=fopen(fs,"r+");if(f==NULL)return -1;
    for(i=(*n)-d;i<(*n);i++)
     {
      fprintf(f,"%30s %7d %7d %7d %7.4g\n",m[i]->name,m[i]->group,m[i]->school,m[i]->IsElder,m[i]->Rating);
      free(m[i]);m[i]=NULL;
     }
    fclose(f);
   }
 else
   {
    for(i=(*n)-d;i<(*n);i++){free(m[i]);m[i]=NULL;}
   }
 (*n)=(*n)-d;
nc:;
return 0;
}
//------------------------------------------------------------------------
 void GroupRazdel(SStudent** m,int n)
{int q[n];q[0]=0;
 int i,k,err,coll=0,j,t;
  for(i=0;i<n;i++)
   {for(err=0,k=0;k<coll;k++)
     {if(m[i]->group==q[k])err=1;
     }
    if(err==0){q[coll]=m[i]->group;coll++;}
   }
 Publsort(q,coll);
 t=n/coll;
 for(j=0,i=0;i<n;j++,i+=t)
 {
  for(k=i;k<i+t;k++)
   {m[k]->group=q[j];}
 }
 for(j=j-1,i+=t;i<n;i++) {m[i]->group=q[j];}
return;
}
//------------------------------------------------------------------------------------------------------------------
void Publsort(int *m, int n)
{int i,k,t;
  for(i=0;i<n;i++)
  {for(k=0;k<n-i-1;k++)
    {if(m[k]>m[k+1])SWAP(m[k],m[k+1])
    }
  }
return;
}
//-----------------------------------------------------------------------------------------------------------------
void SortGroup_N(SStudent** m,int n,int D)
{int i,k;SStudent* t;
 for(i=0;i<n;i++)
  {for(k=0;k<n-i-1;k++)
    {if(m[k]->group > m[k+1]->group)SWAP(m[k],m[k+1])
    }
  }
 if(D==1)
  {
   for(i=1,k=0;k<n;k=i)
   {
    for(i++;(i<n)&&( m[i-1]->group == m[i]->group );i++)
    SortName(m,k,i-1);
   }
  }
 else
return ;
}
//------------------------------------------------------------------------------------------------------------------
void SortName(SStudent** m,int k, int p)
{SStudent* t;int i,d;
 for(i=k;i<p;i++)
  {
   d=strcmp((m[i]->name),(m[i+1]->name));
   if(d>0)SWAP( m[i+1],m[i] )
  }
return ;
}
//---------------------------------------------------------------------------------------------------------------
void Starost(SStudent **m,int n)
{int i,k;
 SortGroup_N(m,n,0);
 for(k=1,i=0;i<n-1;i++,k++)
 {if(m[i]->group!=m[i+1]->group)
   {
    RaTsort(m,i+1-k,k);
    printf("Starosta gryppi %d ychenik(ca) %s.\n",m[i]->group,m[i+1-k+k/2]->name);
    k=0;
    if(i==n-2)printf("Starosta gryppi %d ychenik(ca) %s.\n",m[i+1]->group,m[i+1]->name);
   }
 else if(i==n-2)
   {
    RaTsort(m,i+1-k,k+1);
    printf("Starosta gryppi %d ychenik(ca) %s.\n",m[i]->group,m[i+1-k+(k+1)/2]->name);
   }
 }
return;
}
//-------------------------------------------------------------------------------------------------------------------
void RaTsort(SStudent **m,int b,int l)
{int i,k;SStudent *t;
  if(l==1)goto le;
  for(i=0;i<l;i++)
  {for(k=b;k<b+l-1;k++)
    {if( (m[k]->Rating) < (m[k+1]->Rating) )SWAP(m[k],m[k+1])
    }
  }
le:;
return;
}
//-------------------------------------------------------------------------------------------------------------------
//==================================================================================================================
//===================================================================================================================

int IMPyt_L(const char *fs,SStudentL*** m,int *n)
{char str[512];FILE *f;char word[512];
 char *nacal;int i,l=0,err=0;
 (*n)=0;
 f=fopen(fs,"r");if(f==NULL)return-1;
     while( (fgets(str,512,f)!=NULL)&&(sscanf(str,"%s",word)==1) )(*n)++;
     if((*n)==0){fclose(f);return -2;}
  (*m)=(SStudentL**)malloc((*n)*sizeof(**m));
     if((*m)==NULL){fclose(f);return -3;}
 rewind(f);
         for(i=0;(fgets(str,512,f)!=NULL)&&(sscanf(str,"%s",word)==1);i++)
         {
          (*m)[i]=(SStudentL*)malloc(sizeof(**(*m)));
            for(nacal=str;(sscanf(nacal,"%s",word)==1)&&
                          (   sscanf(nacal,"%d%n",&( (*m)[i]->group ),&l)!=1  );)
              {
               while(isspace(*(nacal) )   )nacal++;
               while(isspace(*(nacal) )==0)nacal++;
              }
          *nacal='\0';
          strcpy((*m)[i]->name,str);
          nacal+=l;
          if(sscanf(nacal,"%g%n",&( (*m)[i]->Rating ),&l)!=1){free((*m)[i]);i--;}
          nacal=NULL;l=0;
         }
 if(i<(*n)){(*n)=i;fclose(f);return 1;}
 else
 fclose(f);
return 0;
}
//--------------------------------------------------------------------------------------------------------------
void Vivod_L(SStudentL **m,int n)
{int i;
 printf("%30s %7s %7s\n","Name","Group","Rating");
 for(i=0;i<n;i++)
 {printf("%30s %7d %7.4g\n",m[i]->name,m[i]->group,m[i]->Rating);
 }
return;
}
//-------------------------------------------------------------------------------------------------------------
void Ratingsort_L(SStudentL **m,int n)
{
 int i,k;SStudentL *d;
 for(i=0;i<n;i++)
   {for(k=n-1;k>i;k--)
       {if( (m[k-1]->Rating) < (m[k]->Rating) )
          {d=m[k-1];m[k-1]=m[k];m[k]=d;
          }
       }
   }
}
//----------------------------------------------------------------------------------------------------------------
void VivodR_L(SStudentL **m,int n)
{int i,d;
 d=n*10/100;
 printf("%30s %7s %7s\n","Name","Group","Rating");
 for(i=0;i<n;i++)
 {
  if(i==d)printf("----\n");
  if(i==n-d)printf("---\n");
  printf("%30s %7d %7.4g\n",m[i]->name,m[i]->group,m[i]->Rating);
 }
return ;
}
//=============================================================================================================
//===============================================================================================================
//------------------------------------------------------------------------------------------------------------------

/*
  ss=str+l;if(sscanf(ss,"%d%n",&( (*s)[i]->school ),&l)!=1)break;
  ss=ss+l;while(isspace(*ss))ss++;
  if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
  strcpy((*s)[i]->name,ss);
*/
/*for(i=0;i<n;i++)q[i]=m[i]->group;
 for(i=0;i<n;i++)
  {for(k=0;k<n-i-1;k++)
    {if(q[k]>q[k+1])SWAP(q[k],q[k+1])
    }
  }
 for(coll=1,i=0;i<n-1;i++){if(q[i]!=q[i+1])coll++;}
   int p[coll];t=n/coll;
   for(k=0,p[k]=q[k],i=0;i<n;i++)
     {if(q[i]!=q[i+1])
        {k++;p[k]=q[i+1];
        }
     }
*/


