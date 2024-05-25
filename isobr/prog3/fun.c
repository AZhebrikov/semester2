#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 {
  char c='a';
  char cc='\012';
  short int sd=12;
  int d=123;
  printf("d=%d\n",d);
  long ld=1234L;
  long long lld=12345LL;
  d=0123; //=3*8^0+2*8^1+1*8^2
  printf("d=%d\n",d);
  d=0x123;//= 3*16^0+2*16^1+1*16^2
  printf("d=%d\n",d);
  d=0xff; //=256-1=255
  printf("d=%d\n",d);

  printf("---\n");
  printf("c=%c\n",c);
  printf("sd=%hd\n",sd);
  printf("d=%d\n",d);
  printf("ld=%ld\n",ld);
  printf("lld=%lld\n",lld);
 }
 {
  float f=123.456e10f;
  double lf=123.456e10;
  printf("=======\n");
  printf("f=%f\n",f);
  printf("lf=%lf\n",lf);
  printf("f=%e\n",f);
  printf("lf=%le\n",lf);
  printf("f=%g\n",f);
  printf("lf=%lg\n",lf);
 }


  {
  printf("---\n");
  char c='a';
  char cc='\012';
  short int sd=12;
  int d=123;
  printf("d=%d\n",d);
  long ld=1234L;
  long long lld=12345LL;
  d=0123; //=3*8^0+2*8^1+1*8^2
  printf("d=%d\n",d);
  d=0x123;//= 3*16^0+2*16^1+1*16^2
  printf("d=%d\n",d);
  d=0xff; //=256-1=255
  printf("d=%d\n",d);
  printf("-----\n");
  printf("c=%c\n",c);
  printf("sd=%10.3hd\n",sd);
  printf("d=%10.3d\n",d);
  printf("ld=%10.3ld\n",ld);
  printf("lld=%10.3lld\n",lld);
 }
 {
  float f=123.456e10f;
  double lf=123.456e10;
  printf("=======\n");
  printf("f=%10.3f\n",f);
  printf("lf=%10.3lf\n",lf);
  printf("f=%10.3e\n",f);
  printf("lf=%10.3le\n",lf);
  printf("f=%10.6g\n",f);
  printf("lf=%10.6lg\n",lf);
 }


{
  printf("---\n");
  char c='a';
  char cc='\012';
  short int sd=12;
  int d=123;
  printf("d=%d\n",d);
  long ld=1234L;
  long long lld=12345LL;
  d=0123; //=3*8^0+2*8^1+1*8^2
  printf("d=%d\n",d);
  d=0x123;//= 3*16^0+2*16^1+1*16^2
  printf("d=%d\n",d);
  d=0xff; //=256-1=255
  printf("d=%d\n",d);
  printf("-----\n");
  printf("c=%c\n",c);
  printf("sd=%*.*hd\n",10,3,sd);
  printf("d=%*.*d\n",10,3,d);
  printf("ld=%*.*ld\n",10,3,ld);
  printf("lld=%*.3lld\n",10,lld);
 }
  {
  float f=123.456e10f;
  double lf=123.456e10;
  printf("=======\n");
  printf("f=%15.3f\n",f);
  printf("lf=%15.3lf\n",lf);
  printf("f=%15.3e\n",f);
  printf("lf=%15.3le\n",lf);
  printf("f=%15.*g\n",6,f);
  printf("lf=%15.*lg\n",6,lf);
 }

 {
  printf("=====\n");
  char str[256]="( 1 , 1 ) ( 12.12 , 12.12 ) ( 123.123 , 123.123 )",*s;int l,nr=0;
  float m[100][2];
  for(nr=0,s=str;sscanf(s," (%g ,%g )%n",m[nr]+0,m[nr]+1,&l)==2;s+=l,nr++);
  for(int i=0;i<nr;i++)printf("(%g,%g)\n",m[i][0],m[i][1]);
 }

 {char str[256],w[256],*s;float m[100][2]; int lm[100][2]={0},l,i,nr,lw;
  FILE *f;
  printf("-----\n");
  f=fopen("t.txt","r");
  while( fgets(str,sizeof(str),f) )
  {
   for(nr=0,s=str;sscanf(s," (%g ,%g )%n",m[nr]+0,m[nr]+1,&l)==2;s+=l,nr++)
   {
    sprintf(w,"%g",m[nr][0]);lw=(int)strlen(w);if(lw>lm[nr][0])lm[nr][0]=lw;
    sprintf(w,"%g",m[nr][1]);lw=(int)strlen(w);if(lw>lm[nr][1])lm[nr][1]=lw;

   }
  }
  fclose(f);
 f=fopen("t.txt","r");
  while( fgets(str,sizeof(str),f) )
  {
   for(nr=0,s=str;sscanf(s," (%g ,%g )%n",m[nr]+0,m[nr]+1,&l)==2;s+=l,nr++)
   {
    printf("(%*g,%*g) ",lm[nr][0],m[nr][0],lm[nr][1],m[nr][1]);
   }
   printf("\n");
  }
  fclose(f);
 //Есть еще формат %[],где внутри крадратных скобок мы можем записывать последовательность символ
 //которые мы можем считывать, например %[, ]-можем считывать слово из пробелов и запятых .
 }
return 0;
}
