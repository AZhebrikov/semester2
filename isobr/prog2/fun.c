#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{FILE *f; int x=1,m[10]={10,11,12,13,14,15,16,17,18,19};
 f=fopen("KEK.txt","wb");//esli txt doc to read->rt,a esli na zapic ->wt,esli rabot c binarnim doc,to bw ili rb
 if(f)
 {
  if(fwrite(&x,sizeof(x),1,f)!=1)printf("err1\n");
  if(fwrite(m,sizeof(m[0]),10,f)!=10)printf("err2\n");
  fclose(f);
 }
printf("Done\n");
return 0;
}
