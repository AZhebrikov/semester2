#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <ctype.h>

void main()
{SStudentL **m;int i,n,err;
 err=IMPyt_L("data1.txt",&m,&n);
 if(err >= 0)
 {Vivod_L(m,n);
  Ratingsort_L(m,n);
  VivodR_L(m,n);
 }
 else ;
 for(i=0;i<n;i++)free(m[i]);
 free(m);m=NULL;
return;
}
