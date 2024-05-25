#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun1.h"
#define SWAP(a,b) {t=(a);(a)=(b);(b)=t;}
//---------------------------------------------------------------------------------------------------------
BMPHEAD *Input(const char *sf)
{FILE *f;BMPHEAD *h=NULL;int lb,j,i,ls;char c,*s=NULL;
 lb=(int)( ((char*)&(h->pal)) - ((char*)&(h->Signature)));
 f=fopen(sf,"rb");if(f==NULL)return NULL;
 h=(BMPHEAD*)malloc(sizeof(*h));
 if(fread(h,54,1,f)!=1){free(h);return NULL;}
 if(h->ClrUser==0)for(i=0;i< h->Ptr-54;i++)fread(&c,1,1,f);
 else  {
        for(i=0;i< h->Ptr-54-256*4;i++)fread(&c,1,1,f);
        fread(h->pal,4,256,f);
       }
 h->v=NULL;h->g=NULL;
 if(h->BitsPerPixel==24)
 {
  ls=h->SizeImage/h->Height;
  s=(char*)malloc(ls);
  h->v=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height*h->Width*4);
  h->v[0]=(unsigned char(*)[4])(h->v+h->Height);
  for(i=1;i< h->Height;i++)h->v[i]=h->v[i-1]+h->Width;
  for(i=0;i< h->Height;i++)
  {
   fread(s,1,ls,f);
   for(j=0;j< h->Width;j++){h->v[i][j][0]=s[j*3+2];h->v[i][j][1]=s[j*3+1];h->v[i][j][2]=s[j*3+0];}
  }
 }
 else if(h->BitsPerPixel==32)
 {
  ls=h->SizeImage/h->Height;
  s=(char*)malloc(ls);
  h->v=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height*h->Width*4);
  h->v[0]=(unsigned char(*)[4])(h->v+h->Height);
  for(i=1;i< h->Height;i++)h->v[i]=h->v[i-1]+h->Width;
  for(i=0;i< h->Height;i++)
  {
   fread(s,1,ls,f);
   for(j=0;j< h->Width;j++){h->v[i][j][0]=s[j*4+2];h->v[i][j][1]=s[j*4+1];h->v[i][j][2]=s[j*4+0];}
  }
 }
else if(h->BitsPerPixel==8)
 {
  ls=h->SizeImage/h->Height;
  s=(char*)malloc(ls);
  h->g=(int(**))malloc(h->Height*sizeof(void*)+h->Height*h->Width*sizeof(int));
  h->g[0]=(int(*))(h->g+h->Height);
  for(i=1;i< h->Height;i++)h->g[i]=h->g[i-1]+h->Width;
  for(i=0;i< h->Height;i++)
  {
   fread(s,1,ls,f);
   for(j=0;j< h->Width;j++){h->g[i][j]=(int)(unsigned int)(unsigned char)s[j];}
  }
 }

 free(s);
 fclose(f);
 return h;
}
//--------------------------------------------------------------------------------------------------------------------
int Output(const char *sf,BMPHEAD *h)
{FILE *f;int lb=54,j,i,ls;char c=' ',*s=NULL,pal[256][4];
 lb=(int)( ((char*)&(h->pal)) - ((char*)&(h->Signature)));
 f=fopen(sf,"wb");if(f==NULL)return -1;
 if(fwrite(h,54,1,f)!=1){return -2;}
 if( (h->BitsPerPixel==24)||(h->BitsPerPixel==32) )
    for(i=0;i< h->Ptr-54;i++)fwrite(&c,1,1,f);
 else if(h->BitsPerPixel==8 )
   {
    for(i=0;i<256;i++)pal[i][0]=pal[i][1]=pal[i][2]=i;
    fwrite(pal,4,256,f);
    for(i=0;i< h->Ptr -(54+256*4);i++)fwrite(&c,1,1,f);
   }
 ls=h->SizeImage/h->Height;
 s=(char*)malloc(ls);
if(h->BitsPerPixel==24)
 {
  for(i=0;i< h->Height;i++)
  {
   for(j=0;j< h->Width;j++){s[j*3+2]=h->v[i][j][0];s[j*3+1]=h->v[i][j][1];s[j*3+0]=h->v[i][j][2];}
   fwrite(s,1,ls,f);
  }
 }
else if(h->BitsPerPixel==32)
 {
  for(i=0;i< h->Height;i++)
  {
   for(j=0;j< h->Width;j++){s[j*4+2]=h->v[i][j][0];s[j*4+1]=h->v[i][j][1];s[j*4+0]=h->v[i][j][2];}
   fwrite(s,1,ls,f);
  }
 }
else if(h->BitsPerPixel==8)
 {
  for(i=0;i< h->Height;i++)
  {
   for(j=0;j< h->Width;j++){s[j]=(char)h->g[i][j];}
   fwrite(s,1,ls,f);
  }
 }

 free(s);
 fclose(f);
 return 0;
}
//-----------------------------------------------------------------------------------------------------------------------
int Output_8bit_pal(const char *sf,BMPHEAD *h)
{FILE *f;int j,i,ls;char *s=NULL,pal[256][4];
 f=fopen(sf,"wb");if(f==NULL)return -1;
 if(fwrite(h,54,1,f)!=1){return -2;}
char p=0;for(i=0;i<138-54;i++)fwrite(&p,1,1,f);
 printf("%d \n",h->ClrUser);
 for(int k=0;k<256;k++)printf("%d %d %d %d \n",(int)(unsigned int)h->pal[k][0],(int)(unsigned int)h->pal[k][1],(int)(unsigned int)h->pal[k][2],(int)h->pal[k][3]);

    if(h->ClrUser==0)
     {
      for(i=0;i<256;i++)h->pal[i][0]=h->pal[i][1]=h->pal[i][2]=i;
      fwrite(pal,4,256,f);
     }
    else fwrite(pal,4*256,1,f);
   s=(char*)malloc(h->Width);
   for(i=0;i< h->Height;i++)
  {
   for(j=0;j< h->Width;j++){s[j]=(char)h->g[i][j];}
   fwrite(s,1,h->Width,f);
  }
 free(s);
 fclose(f);
 return 0;
}
//----------------------------------------------------------------------------------------------------------------------
BMPHEAD *Input_8bit_pal(const char *sf)
{FILE *f;BMPHEAD *h=NULL;int j,i;char c,*s=NULL;
 f=fopen(sf,"rb");if(f==NULL)return NULL;
 h=(BMPHEAD*)malloc(sizeof(*h));
 int list=0;

 if( fread(h,54,1,f) !=1){free(h);return NULL;}
 list+=54;
 for(i=0;i<138-54;i++)list+=fread(&c,1,1,f);
 if(h->ClrUser==0){for(int i=0;i<256;i++)h->pal[i][0]=h->pal[i][1]=h->pal[i][2]=i;}
 else  {
        list+=fread(h->pal,1,4*256,f);
       }
  printf("--->> %d\n--w %d\n -- h %d\n",list,h->Width,h->Height);
       for(int k=0;k<256;k++)printf("%d %d %d %d \n",(int)(unsigned int)h->pal[k][0],(int)(unsigned int)h->pal[k][1],(int)(unsigned int)h->pal[k][2],(int)h->pal[k][3]);
  h->v=NULL;h->g=NULL;
  s=(char*)malloc(h->Width);
  h->g=(int(**))malloc(h->Height*sizeof(void*)+h->Height*h->Width*sizeof(int));
  h->g[0]=(int(*))(h->g+h->Height);
  for(i=1;i< h->Height;i++)h->g[i]=h->g[i-1]+h->Width;
  for(i=0;i< h->Height;i++)
  {
   printf("--%d %d\n",i,(int)fread(s,1,h->Width,f));
   for(j=0;j< h->Width;j++){h->g[i][j]=(int)(unsigned int)(unsigned char)s[j];}
  }

  FILE * ft;ft=fopen("t.txt","r");
  FILE * ft1;ft1=fopen("t1.txt","w");
  printf("-> %d\n",list);
  for(i=0;i< h->Height;i++)
   for(j=0;j< h->Width;j++)
     {
       int p;fscanf(ft,"%d",&p);
       if(h->g[i][j]==p)fprintf(ft1,"%s","+");
       else fprintf(ft1,"%s","-");
     }

 free(s);
 fclose(f);
 return h;
}

//-----------------------------------------------------------------------------------------------------------------------
unsigned int ui(unsigned char c){return (unsigned  int)c;}
//-----------------------------------------------------------------------------------------------------------------------
BMPHEAD* ImagBlack(BMPHEAD* m)
{BMPHEAD *L;int j,i,lb;
 lb=(int)( (char*)&(L->pal)-(char*)&(L->Signature) );
 L=(BMPHEAD*)malloc(sizeof(*m));
 if(L==NULL)return NULL;
 memcpy(L,m,lb);L->BitsPerPixel=8;
 L->Ptr=L->Ptr+256*4;
 L->FileLength=L->FileLength+256*4-(  L->Height*L->Width*(  ((m->BitsPerPixel) - (L->BitsPerPixel))/8 )  );
 for(i=0;i<256;i++){ L->pal[i][0]=L->pal[i][1]=L->pal[i][2]=i;}
 L->g=(int((**)))malloc(  (L->Height*L->Width*sizeof(int))  + L->Height*sizeof(int*)  );
 L->SizeImage=(L->Height*L->Width*sizeof(unsigned char) );
 if(L->g==NULL){free(L);return NULL;}
 L->g[0]=(int(*))(L->g+L->Height);
 for(i=1;i< L->Height;i++)L->g[i]=L->g[i-1]+L->Width;
 for(i=0;i< L->Height;i++)for(j=0;j< L->Width;j++)L->g[i][j]=(int)(unsigned char)
    (  ( ui(m->v[i][j][0])+ui(m->v[i][j][1])+ui(m->v[i][j][2]))/3  );
return L;
}
//-------------------------------------------------------------------------------------------------------
void VivodDanIs(BMPHEAD *l)
{char m[3];m[0]=((char *)(&(l->Signature)))[0];m[1]=((char *)(&(l->Signature)))[1];m[2]='\0';
  printf("----\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n-------\n",
        m,l->FileLength,l->Zero,l->Ptr,l->Version,l->Width,l->Height,l->Planes,l->BitsPerPixel,l->Compression,l->SizeImage,
        l->XPelsPerMeter,l->YPelsPerMeter,l->ClrUser,l->ClrImportant);
}
//--------------------------------------------------------------------------------------------------------------
void SmenaChB(BMPHEAD *m)
{int i,j;
 for(i=0;i< m->Height;i++)for(j=0;j< m->Width;j++)m->g[i][j]=255-m->g[i][j];
return;
}
//-------------------------------------------------------------------------------------------------------------------
void OtragGor(BMPHEAD *m)
{int i,j,d,t;d=(unsigned int)(m->Height/2);
 for(i=0;i< d;i++)for(j=0;j< m->Width;j++)
 {t=m->g[(m->Height-1-i)][j];m->g[(m->Height-1-i)][j]=m->g[i][j];m->g[i][j]=t;}
return;
}
//-------------------------------------------------------------------------------------------------------------
void OtragVer(BMPHEAD *m)
{int i,j,d,t;d=(unsigned int)(m->Width/2);
 for(i=0;i< m->Height;i++)for(j=0;j< d;j++)
 {t=m->g[i][j];m->g[i][j]=m->g[i][(m->Width-1-j)];m->g[i][(m->Width-1-j)]=t;}
return;
}
//-------------------------------------------------------------------------------------------------------------
void OtragPDig(BMPHEAD *m)
{if( m->Height != m->Width )return;
 int i,j,t;
 for(i=0;i< m->Height;i++)for(j=0;j < i;j++)
 {t=m->g[i][j];m->g[i][j]=m->g[j][i];m->g[j][i]=t;}
return;
}
//-------------------------------------------------------------------------------------------------------------
void OtragGDig(BMPHEAD *m)
{if( m->Height != m->Width )return;
 int i,j,t;
 for(i=0;i< m->Height;i++)for(j=0;j < m->Width-i;j++)
 {t=m->g[i][j];m->g[i][j]=m->g[(m->Height-1-j)][(m->Width-1-i)];m->g[(m->Height-1-j)][(m->Width-1-i)]=t;}
return;
}

//-------------------------------------------------------------------------------------------------------------
void Povorot_polpi(BMPHEAD *m)
{OtragGDig(m);
 OtragGor(m);
 return;
}
//-------------------------------------------------------------------------------------------------------------
void InversionRGB(BMPHEAD *m)
{int i,j;unsigned char t;
 for(i=0;i< m->Height;i++)for(j=0;j< m->Width;j++)
 SWAP(m->v[i][j][0],m->v[i][j][2]);
 return;
}
//-------------------------------------------------------------------------------------------------------------
void Negativ(BMPHEAD *m)
{int i,j;
 for(i=0;i< m->Height;i++)for(j=0;j< m->Width;j++)
 {
  m->v[i][j][0]=(unsigned char)(255-m->v[i][j][0]);
  m->v[i][j][1]=(unsigned char)(255-m->v[i][j][1]);
  m->v[i][j][2]=(unsigned char)(255-m->v[i][j][2]);
 }
return;
}


void creaty_f_PMB_1_bit(FILE *f)
{
 BMPHEAD* h=(BMPHEAD*)malloc(138);
 printf("+++===0\n");
 h->Signature=0x4d42;
 printf("+++===1\n");
 h->FileLength=138+900*900+256*4;
 h->Zero=0;
 h->Ptr=138+256*4;
 h->Version=124;
 h->Width=900;
 h->Height=900;
 h->Planes=1;
 h->BitsPerPixel=8;
 h->Compression=0;
 h->SizeImage=900*900;
 h->XPelsPerMeter=0;
 h->YPelsPerMeter=0;
 h->ClrUser=256;
 h->ClrImportant=4;
 printf("+++===2\n");
    unsigned char pal[256][4];
    pal[0][0]=0;pal[0][1]=0;pal[0][2]=0;
    pal[1][0]=100;pal[1][1]=0;pal[1][2]=0;
    pal[2][0]=0;pal[2][1]=100;pal[2][2]=0;
    pal[3][0]=0;pal[3][1]=0;pal[3][2]=100;
      for(int i=4;i<256;i++)
          {
              if(i%3==0){pal[i][0]=i;pal[i][1]=0;pal[i][2]=0;}
              if(i%3==1){pal[i][0]=0;pal[i][1]=i;pal[i][2]=0;}
              if(i%3==2){pal[i][0]=0;pal[i][1]=0;pal[i][2]=i;}
          }

 unsigned char h_[900][900];
 for(int i=0;i<900;i++)
    for(int j=0;j<900;j++)
       {
        h_[i][j]=rand()%4;
       }
 for(int k=0;k<256;k++)printf("%d %d %d %d \n",(int)(unsigned int)pal[k][0],(int)(unsigned int)pal[k][1],(int)(unsigned int)pal[k][2],(int)pal[k][3]);
 printf("+++===3\n");
 fwrite(h,54,1,f);
 char p=0;
 for(int m=0;m<138-54;m++)fwrite(&p,1,1,f);
 fwrite(pal,256*4,1,f);
 fwrite(h_,900*900,1,f);
 FILE * ft;ft=fopen("t.txt","w");
 for(int i=0;i<900;i++)
    for(int j=0;j<900;j++)
       {
        fprintf(ft,"%d ",(int)h_[i][j]);
       }

}


void Ramka_24bit(BMPHEAD * h)
{
 h->FileLength+=(4*h->Width + 4*h->Height + 4*4)*3;
 h->Width+=4;h->Height+=4;
 h->SizeImage+=(4*h->Width + 4*h->Height + 4*4)*3;
 unsigned char (**v_)[4];
 v_=(unsigned char(**)[4])malloc(h->Height*sizeof(void*)+h->Height*h->Width*4);
 v_[0]=(unsigned char(*)[4])(v_+h->Height);
int i,j;VivodDanIs(h);
 for(i=1;i< h->Height;i++)v_[i]=v_[i-1]+h->Width;
 for(i=0;i<2;i++)
   for(j=0;j<h->Width;j++)
     {
       v_[i][j][0]=0;
       v_[i][j][1]=0;
       v_[i][j][2]=0;
     }
  for(i=2;i<h->Height-2;i++)
      {
        for(j=0;j<2;j++)
          {
            v_[i][j][0]=0;
            v_[i][j][1]=0;
            v_[i][j][2]=0;
          }
        for(j=2;j<h->Width-2;j++)
          {
            v_[i][j][0]=h->v[i-2][j-2][0];
            v_[i][j][1]=h->v[i-2][j-2][1];
            v_[i][j][2]=h->v[i-2][j-2][2];
          }
        for(j=h->Width-2;j<h->Width;j++)
          {
            v_[i][j][0]=0;
            v_[i][j][1]=0;
            v_[i][j][2]=0;
          }

      }
    for(i=h->Height-2;i<h->Height;i++)
      for(j=0;j<h->Width;j++)
          {
            v_[i][j][0]=0;
            v_[i][j][1]=0;
            v_[i][j][2]=0;
          }
    free(h->v);
    h->v=v_;
}
//-------------------------------------------------------------------------------------------------------------
//======================================================================================================================
//======================================================================================================================
//------------------------------------------------------------------------------------------------------------
/*void VivodBMP(const char *fs, BMPHEAD *m)
{FILE *f;unsigned int p;pal
 f=fopen(sf,"wb");if(f==NULL)return -1;
 fwrite(m,2,1,f);
 p=m->Width*m->Height*(m->BitsPerPixel/8)+54+256*4;fwrite((unsigned int*)&p,4,1,f);
 fwrite((char*)m+6,4,1,f);
 p=54+256*4;fwrite((unsigned int*)&p,4,1,f);
 fwrite((char*)m+14,40,1,f);



 //if(fwrite(m,54,1,f)!=1){return -2;} printf("w=%d h=%d\n",m->Width,m->Height);
 //rewind(f);




unsigned short int Signature;     //MUST be 0x4d42 =="BM"
   unsigned int FileLength ;        // v baitah
   unsigned int Zero;               //Must be 0
   unsigned int Ptr;                //smeshenie k oblasti dannih
   unsigned int Version;            //dlina octavshesa chasti zagolovka=0x28
   unsigned int Width;              //shirina isobrog
   unsigned int Height;             //visota isobrog
   unsigned short int Planes;        //k-vo bitovih ploskostei
   unsigned short int BitsPerPixel;  //k-vo bit na piksel
   unsigned int Compression;        //shatie:0 ili 1 ili 2
   unsigned int SizeImage;          //razmer bloka dannih v baqtah
   unsigned int XPelsPerMeter;      //v shirinu: piksel na metr
   unsigned int YPelsPerMeter;      //v visoty: piksel na metr
   unsigned int ClrUser;            //k-vo cvetov v palitra
   unsigned int ClrImportant;       //k-vo ispilzoval cvitov v palitre
   unsigned  char pal[256][4];
   unsigned  char (**v)[4];      //true color
   int **g;  //grayscale  0<=g[i][j]<256 ||bitmap

}*/
//----------------------------------------------------------------------------------------------------------------------
/*int main(void)
{BMPHEAD *h,*s,*m;int i,j;
 h=Input("ball.bmp");
 s=Input("ball.bmp");
 m=ImagBlack(s);
   printf("---\n pexh= %d \n-----\n",h->BitsPerPixel);
   printf("---\n pexs= %d \n-----\n",s->BitsPerPixel);
   printf("---\n pexm= %d \n-----\n",m->BitsPerPixel);
     printf("1\n");
   Output("BAL1.bmp",s);
     printf("2\n");
   Output("BAL2.bmp",h);
     printf("3\n");
   Output("BAL3.bmp",m);
     printf("4\n");
   Output("ball1.bmp",h);
    for(i=0;i< h->Height;i++)for(j=0;j< h->Width;j++)
    { h->v[i][j][0]=h->v[i][j][1]=h->v[i][j][2]=(unsigned char)
    (  ( ui(h->v[i][j][0])+ui(h->v[i][j][1])+ui(h->v[i][j][2]))/3  );
    }
   Output("ball3.bmp",h);
    for(i=0;i< s->Height;i++)for(j=0;j< s->Width;j++)
    {s->v[i][j][0]=(unsigned char)
    (  ( ui(s->v[i][j][0])+ui(s->v[i][j][1])+ui(s->v[i][j][2]))/3  );
     s->v[i][j][1]=s->v[i][j][2]=0;
    }
   Output("ball4.bmp",s);
   printf("1\n");
   Output("ball6.bmp",m);
    for(i=0;i< m->Height;i++)for(j=0;j< m->Width;j++)
    {
     m->g[i][j]=255 - m->g[i][j];
    }
   printf("2\n");
   Output("ball5.bmp",m);
 printf("Done\n");

 free(m->g);
 free(s->v);
 free(h->v);
 free(m);m=NULL;
 free(h);h=NULL;
 free(s);s=NULL;
return 0;
}
*/


/*
   unsigned short int Signature;     //MUST be 0x4d42 =="BM"
   unsigned int FileLength ;        // v baitah
   unsigned int Zero;               //Must be 0
   unsigned int Ptr;                //smeshenie k oblasti dannih
   unsigned int Version;            //dlina octavshesa chasti zagolovka=0x28
   unsigned int Width;              //shirina isobrog
   unsigned int Height;             //visota isobrog
   unsigned short int Planes;        //k-vo bitovih ploskostei
   unsigned short int BitsPerPixel;  //k-vo bit na piksel
   unsigned int Compression;        //shatie:0 ili 1 ili 2
   unsigned int SizeImage;          //razmer bloka dannih v baqtah
   unsigned int XPelsPerMeter;      //v shirinu: piksel na metr
   unsigned int YPelsPerMeter;      //v visoty: piksel na metr
   unsigned int ClrUser;            //k-vo cvetov v palitra
   unsigned int ClrImportant;       //k-vo ispilzoval cvitov v palitre
   unsigned  char pal[256][4];
   unsigned  char (**v)[4];      //true color
   int **g;  //grayscale  0<=g[i][j]<256 ||bitmap
*/
