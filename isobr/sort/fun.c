#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fun.h"
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
void Sort1OMP(int *a,int n,int *tmp)
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
/*
Легко видеть, что данный алгоритм решает задачу за время O(N log2 N), где N – количество элементов в сортируемом массиве.
Недостатком алгоритма является необходимость использования дополнительного массива с размером, равным  размеру исходного массива.

Сортировка слиянием без рекурсии.
Предыдущий алгоритм можно модифицировать так, что он уже не будет использовать рекурсию. Действительно. Рассмотрим последовательно все пары элементов
   в сортируемом массиве. Каждый из элементов в паре представляет собой уже отсортированный массив длины 1, поэтому эти массивы (пока длины 1)
   можно слить в упорядоченные куски длины 2. Далее мы рассматриваем уже пары упорядоченных массивов длины 2 и сливаем их в массивы длины 4. И т.д.
Отметим, что при этих операциях на k-том проходе по упорядочиваемому массиву на правом конце массива мы будем получать либо ситуацию, когда у правого
   оставшегося куска (длины £ 2k ) вообще нет парного куска для слияния, либо кусок есть и его длина £ 2k. В первом случае делать вообще ничего не нужно,
    а во втором следует стандартным способом сливать куски, возможно, существенно различной длины.
Легко видеть, что данный алгоритм решает задачу за время O(N log2 N), где N – количество элементов в сортируемом массиве.
*/
//------------------------------------------------------------------------------------------------------------
void Sort2(int *a,int n,int *tmp)
{int k,k2,i;
 for(k=1;k<n;k*=2)
 {
  for(i=0;i+k<n;i+=2*k)
  {k2=n-i-k;if(k2>k)k2=k;
   Merge(a+i,k,a+i+k,k2,tmp+i);
   memcpy(a+i,tmp+i,(k+k2)*sizeof(a[0]));
  }
 }
}
//------------------------------------------------------------------------------------------------------------
void Sort2OMP(int *a,int n,int *tmp)
{int k,k2,i;
 for(k=1;k<n;k*=2)
 {
#pragma omp parallel for private(k2)
  for(i=0;i <n-k;i+=2*k)
  {k2=n-i-k;if(k2>k)k2=k;
   Merge(a+i,k,a+i+k,k2,tmp+i);
   memcpy(a+i,tmp+i,(k+k2)*sizeof(a[0]));
  }
 }
}
//------------------------------------------------------------------------------------------------------------
void QSort1(int *a,int p,int q)
{int i,j,t;
 if(p>=q)return;
 i=p;j=q;
 //M=a[j] [p,i-1]<=M<=[j,q]
 for(;;)
  {                        //M=a[j] [p,i-1]<=M<=[j,q]
   while(a[i]<a[j])i++;    //M=a[j] [p,i-1]<=M<=[j,q]
   SWAP(a[i],a[j]);        //M=a[i] [p,i]<=M<=[j,q]
   j--;                    //M=a[i] [p,i]<=M<=[j+1,q]
   if(i>=j)
    {
     //i==j                //M=a[i] [p,i-1]<=M<=[i+1,q]
     //i==j+1              //M=a[i] [p,i-1]<=M<=[i+1,q]
    QSort1(a,p,i-1);QSort1(a,i+1,q);return;
    }
   while(a[i]<a[j])j--;       //M=a[i] [p,i]<=M<=[j+1,q]
   SWAP(a[i],a[j]);           //M=a[j] [p,i]<=M<=[j,q]
   i++;                       //M=a[j] [p,i-1]<=M<=[j,q]
   if(i>=j)
    {
     //i==j                   //M=a[j] [p,j-1]<=M<=[j+1,q]
     //i==j+1                 //M=a[j] [p,j-1]<=M<=[j+1,q]
     QSort1(a,p,j-1);QSort1(a,j+1,q);return;
    }
  }
}
/*
Теорема. Время работы алгоритма  QuickSort  равно O(N 2), где N – количество элементов в сортируемом массиве.
Теорема. Среднее время работы алгоритма QuickSort равно Q(N log2 N), где N – количество элементов в сортируемом массиве. Под средним временем
 подразумевается среднее время по всем перестановкам любого массива входных данных длины N, состоящего из различных элементов.
*/
//------------------------------------------------------------------------------------------------------------
void QSort2(int *a,int p,int q)
{int i,j,M,t;
 if(p>=q)return;
 i=p;j=q;M=a[i];            //[p,i-1]<=M<=[j+1,q]
 for(;;)
  {while(a[i]<M)i++;       //[p,i-1]<=M<=[j+1,q]
   while(M<a[j])j--;       //[p,i-1]<=M<=[j+1,q]
   if(i>=j)
   {
    //i==j    a[i]=a[j]=M  //[p,j]<=[j+1,q]
    //i==j+1               //[p,j]<=[j+1,q]
    QSort2(a,p,j);QSort2(a,j+1,q);return;
   }
   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
   i++;j--;
  }
}
//------------------------------------------------------------------------------------------------------------
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
      QSort2(a,p,j);
      p=j+1;q=q;goto l0;
      return;
     }
    else
     {
      QSort2(a,j+1,q);
      p=p;q=j;goto l0;
      return;
     }
   }
   SWAP(a[i],a[j]);        //[p,i-1]<=[j+1,q]
   i++;j--;
  }
}
//Теорема
//Алгоритм QSort2 работает за время O(n^2) и требует дополнительной памяти O(log n) из стека.
//Среднее время работы алгоритма QSort2 на массиве из n различных элементов = O( n*(log2_n) )
//------------------------------------------------------------------------------------------------------------
#define V a[I]
#define iL (2*I+1)
#define iR (2*I+2)
#define L a[iL]
#define R a[iR]

void Heapify(int *a, int I,int n)//-->  derevo yporadochennost dli i>I   <-- dli i>=I
{int t;
 while(iR<n)
  {
   if( (V>=L) && (V>=R) )return;
   if(L>=R){SWAP(V,L);I=iL;}
   else    {SWAP(V,R);I=iR;}
  }
 if( (iL<n) && (L>V) )SWAP(V,L);
}


void HeapSort(int *a, int n)
{int i,t;
 /*1*/ for(i=n-2;i>=0;i--)Heapify(a,i,n);//=> *yporadochenii macciv
 /*2*/ for(;n>1;n--){SWAP(a[0],a[n-1]);Heapify(a,0,n-1);}
}

//------------------------------------------------------------------------------------------------------------
//Сортировка подсчетом.
void CountSort(int *a, int n,int K,int *b,int *rez)
{int i,j;
 memset(b,0,(K+1)*sizeof(*b));
 for(i=0;i<n;i++)b[a[i]]++;
 for(i=1;i<K;i++)b[i]+=b[i-1];
 for(i=n-1;i>=0;i--)
  rez[(b[a[i]]--)-1]=a[i];
}
//Теорема
//Алгоритм CoutnSort требует дополнительной памяти O(n+K) и работает
//за время O(n+K).
//Следствие: Если O=O(n), то CountSort требует дополнительной памяти O(n) и работает за время O(n).
//------------------------------------------------------------------------------------------------------------
//!!!!!!!!!!!!
	void DSort(int* a_,int n,int *b,int *rez)
	{
    union US2I{unsigned short int s[2];int i;}*a=(union US2I*)a_;int I,K=(1<<16);
 	  for(I=0;I<2;I++)
 	  {
  	  int i,j;
  	  memset(b,0,(K+1)*sizeof(*b));
  	  for(i=0;i<n;i++)b[a[i].s[I]]++;
  	  for(i=1;i<K;i++)b[i]+=b[i-1];
  	  for(i=n-1;i>=0;i--)
  	  rez[(b[a[i].s[I]]--)-1]=a[i].i;
  	  if(I<1)memcpy(a,rez,sizeof(a[0])*n);
  	}
  }
//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
//=======================================================================================================================
//=======================================================================================================================
/*
switch(m)
 {case 1:
  ....
  case 2:
  ....
...
  ....
  case m:
  ....
  default:
  ....
 }
*/
