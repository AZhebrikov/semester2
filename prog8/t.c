#include<stdio.h>
#include<stdlib.h>

int main(void)
{char *m;
 m=(char*)malloc(sizeof(int) + sizeof(float));
//======
 *(int*)(m+0)=5;
 *(float*)(m+sizeof(int))=6.;
 printf("int=%d float=%g\n",*(int*)(m+0),*(float*)(m+sizeof(int)) );
 free(m);
return 0;
}
