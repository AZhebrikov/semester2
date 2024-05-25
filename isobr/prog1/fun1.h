#pragma pack(1)
typedef struct BMPHEAD_
  {unsigned short int Signature;     //MUST be 0x4d42 =="BM"
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
  }BMPHEAD;
#pragma pack()

#ifndef _FUN_H
void InversionRGB(BMPHEAD *m);
void Povorot_polpi(BMPHEAD *m);
void OtragGDig(BMPHEAD *m);
void OtragPDig(BMPHEAD *m);
void Negativ(BMPHEAD *m);
void OtragGor(BMPHEAD *m);
BMPHEAD *Input(const char *sf);
int Output(const char *sf,BMPHEAD *h);
void OtragVer(BMPHEAD *m);
BMPHEAD* ImagBlack(BMPHEAD* m);
void SmenaChB(BMPHEAD *m);
void VivodDanIs(BMPHEAD *l);
void creaty_f_PMB_1_bit(FILE *f);
void Ramka_24bit(BMPHEAD * h);
int Output_8bit_pal(const char *sf,BMPHEAD *h);
BMPHEAD *Input_8bit_pal(const char *sf);
#define _FUN_H
#endif


void Sort2(int *a,int n,int *tmp);
void Heapify(int *a, int I,int n);
void CountSort(int *a, int n,int K,int *b,int *rez);
void HeapSort(int *a,int n);
void QSort1(int *a,int p,int q);
void Sort2OMP(int *a,int n,int *tmp);
void Sort1OMP(int *a,int n,int *tmp);
void Sort1(int *a,int n,int *tmp);
void BubbleSort(int *m,int n);
void Merge(int *a,int n,int *b,int m,int *r);

int Stat1(int *a,int n,int *tmp, int *tmp2,int k);
int Stat2_(int *a,int p,int q,int k);
int Stat2(int *a, int n,int *tmp,int k);
int Stat3(int *a,int n,int *tmp,int *tmp2,int k);
int Stat3_(int *a,int p,int q,int k,int *m);
