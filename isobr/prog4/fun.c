#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fun.h"
#define SWAP(a,b) {t=(a);(a)=(b);(b)=t;}

//-----------------------------------------------------------------------------------------------------------
void Merge(int *a,int n,int *b,int m,int *r)
{int i,k,j;
 for(i=0,j=0,k=0;i<n&&j<m;)
 if(a[i]<b[j])
   r[k++]=a[i++];
 else
   r[k++]=b[j++];
 while(i<n)r[k++]=a[i++];
 while(j<m)r[k++]=b[j++];
}
//------------------------------------------------------------------------------------------------------------
void Sort1(int *a,int n,int *tmp)
{int n1,n2;
 if(n<=1)return;
 n1=n/2;n2=n-n1;
 Sort1(a,n1,tmp);
 Sort1(a+n1,n2,tmp);
 Merge(a,n1,a+n1,n2,tmp);
 memcpy(a,tmp,n*sizeof(a[0]));
}

//------------------------------------------------------------------------------------------------------------
/*void Sort1OMP(int *a,int n,int *tmp)
{int nn1,nn2,n1,n2,n3,n4;
 nn1=n/2;nn2=n-nn1;n1=nn1/2;n2=nn1-n1;n3=nn2/2;n4=nn2-n3;
 if(n<10)BubbleSort(a,n);
 else
  {
#pragma omp parallel sections
   {
#pragma omp section
    {Sort1(a+0,n1,tmp);}
#pragma omp section
    {Sort1(a+n1,n2,tmp+n1);}
#pragma omp section
    {Sort1(a+nn1,n3,tmp+nn1);}
#pragma omp section
    {Sort1(a+nn1+n3,n4,tmp+nn1+n3);}
   }
#pragma omp parallel sections
   {
#pragma omp section
     {Merge(a+0,n1,a+n1,n2,tmp+0);memcpy(a+0,tmp+0,nn1*sizeof(a[0]));}
#pragma omp section
     {Merge(a+nn1,n3,a+nn1+n3,n4,tmp+nn1);memcpy(a+nn1,tmp+nn1,nn2*sizeof(a[0]));}
   }
   Merge(a+0,nn1,a+nn1,nn2,tmp+0);memcpy(a+0,tmp+0,n*sizeof(a[0]));
  }//END else
}
*/
//--------------------------------------------------------------------------------------------------------------------------
void QSort2_(int *a,int p,int q)
{int i,j,M,t;
l0:
 if(p>=q)return;
 if(q-p>5)
 {
  i=p+rand()%(q-p+1);
  SWAP(a[p],a[i]);
 }
 i=p;j=q;M=a[i];           //[p,i-1]<=M<=[j+1,q]
 for(;;)
  {while(a[i]<M)i++;       //[p,i-1]<=M<=[j+1,q]
   while(M<a[j])j--;       //[p,i-1]<=M<=[j+1,q]
   if(i>=j)
   {
    //i==j    a[i]=a[j]=M  //[p,j]<=[j+1,q]
    //i==j+1               //[p,j]<=[j+1,q]
    if(j-p<q-j)
     {
      QSort2_(a,p,j);
      p=j+1;q=q;goto l0;
      return;
    }
    else
     {
      QSort2_(a,j+1,q);
      p=p;q=j;goto l0;
      return;
     }
   }
   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
   i++;j--;
  }
}



void  QSort2__(int* a,int p, int q,int I)
{int i,j,M,t;
     if((I>2)||(p-q<1000000))
      {
	l0:
	 if(p>=q)return;
	 if(q-p>5)
	 {
	  i=p+rand()%(q-p+1);
	  SWAP(a[p],a[i]);
	 }
	 i=p;j=q;M=a[i];           //[p,i-1]<=M<=[j+1,q]
	 for(;;)
	  {while(a[i]<M)i++;       //[p,i-1]<=M<=[j+1,q]
	   while(M<a[j])j--;       //[p,i-1]<=M<=[j+1,q]
	   if(i>=j)
	   {
	    //i==j    a[i]=a[j]=M  //[p,j]<=[j+1,q]
	    //i==j+1               //[p,j]<=[j+1,q]
	    if(j-p<q-j)
	     {
	      QSort2_(a,p,j);
	      p=j+1;q=q;goto l0;
	    }
	    else
	     {
	      QSort2_(a,j+1,q);
	      p=p;q=j;goto l0;
	     }
	   }
	   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
	   i++;j--;
	  }
      }
else
 {
     I++;
     i=p+rand()%(q-p+1);
     SWAP(a[p],a[i]);
   i=p;j=q;M=a[i];           //[p,i-1]<=M<=[j+1,q]
   for(;;)
   {
    while(a[i]<M)i++;       //[p,i-1]<=M<=[j+1,q]
    while(M<a[j])j--;       //[p,i-1]<=M<=[j+1,q]
        if(i>=j)
         {
            //i==j    a[i]=a[j]=M  //[p,j]<=[j+1,q]
            //i==j+1               //[p,j]<=[j+1,q]
          #pragma omp parallel sections
          {
           #pragma omp section
           QSort2__(a,p,j,I);
           #pragma omp section
           QSort2__(a,j+1,q,I);
          }
         }
        SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
        i++;j--;
   }
 }
}
//----------------------------------------------------------------------------------------------------------------------
