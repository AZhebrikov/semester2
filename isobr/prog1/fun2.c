#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fun1.h"
#define SWAP(a,b) {t=(a);(a)=(b);(b)=t;}

//------------------------------------------------------------------------------------------------------------------
void BubbleSort(int *m,int n)
{int i,j,t;
 for(i=0;i<n;i++)for(j=1;j<n;j++)if( m[j-1]>m[j])SWAP(m[j-1],m[j]);
 return;
}
//------------------------------------------------------------------------------------------------------------------
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
int Stat1(int *a,int n,int *tmp, int *tmp2,int k)
{memcpy(tmp,a,n*sizeof(a[0]));
 Sort1(tmp,n,tmp2);
 return tmp[k];
}
//------------------------------------------------------------------------------------------------------------
int Stat2_(int *a,int p,int q,int k)
{int i,j,M,t;
l0:
 if(p>=q)return a[p];
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
      if(k<=j)return Stat2_(a,p,j,k);
      else {p=j+1;q=q;goto l0;}
     }
    else
     {if(k<=j){p=p;q=j;goto l0;}
      else return Stat2_(a,j+1,q,k);
     }
   }
   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
   i++;j--;
  }
}
//------------------------------------------------------------------------------------------------------------
int Stat2(int *a,int n,int *tmp,int k)
{
 memcpy(tmp,a,n*sizeof(a[0]));
 return Stat2_(tmp,0,n-1,k);
}
//------------------------------------------------------------------------------------------------------------
#define MIN(a,b) ((a)<(b)?(a):(b))

int Stat3_(int *a,int p,int q,int k,int *m)
{int i,j,M,t;
l0:
 if(p>=q)return a[p];
 if(q-p>5)
 {
    int nm=0,mm[5],M;
    for(i=p;i<=q;i+=5)
    m[nm++]=Stat3_(a,i,MIN(i+4,q),(i+MIN(i+4,q))/2,mm);
    M=Stat2_(m,0,nm-1,nm/2);
    for(i=p;i<=q;i++)if(a[i]==M)break;
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
      if(k<=j)return Stat3_(a,p,j,k,m);
      else {p=j+1;q=q;goto l0;}
     }
    else
     {if(k<=j){p=p;q=j;goto l0;}
      else return Stat3_(a,j+1,q,k,m);
     }
   }
   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
   i++;j--;
  }
}

int Stat3(int *a,int n,int *tmp,int *tmp2,int k)
{
  memcpy(tmp,a,n*sizeof(a[0]));
  return Stat3_(tmp,0,n-1,k,tmp2);
}
//------------------------------------------------------------------------------------------------------------
//=======================================================================================================================
//=======================================================================================================================
