#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun1.h"

int main(void)
{BMPHEAD *h,*m,*s;int i,j;
 h=Input("ball.bmp");     VivodDanIs(h);
 m=ImagBlack(h);    VivodDanIs(m);
 s=Input("BAL3.bmp");
  //printf("---\n pexh= %d \n---\n",h->BitsPerPixel);
   //printf("---\n pexm= %d \n---\n",m->BitsPerPixel);
     printf("1\n");
   Output("BAL1.bmp",h);
     printf("2\n");
   Output("BAL2.bmp",m);
     printf("3\n");
   SmenaChB(m);
   Output("BAL3.bmp",m);
     printf("4\n");
   OtragGor(m);
   Output("BAL4.bmp",m);
     printf("5\n");
   OtragVer(s);
   Output("BAL5.bmp",s);
     printf("6\n");
   free(m->g);free(m);m=NULL;
   m=Input("BAL3.bmp");
   OtragPDig(m);
   Output("BAL7.bmp",m);
     printf("7\n");
   free(m->g);free(m);m=NULL;
   m=Input("BAL3.bmp");
   OtragGDig(m);
   Output("BAL8.bmp",m);
     printf("8\n");
   free(m->g);free(m);m=NULL;
   m=Input("BAL3.bmp");
   Povorot_polpi(m);
   Output("BAL9.bmp",m);
     printf("9\n");
   free(s->g);free(s);s=NULL;
   s=Input("BAL1.bmp");
   InversionRGB(s);
   Output("BAL10.bmp",s);
     printf("10\n");
   free(s->g);free(s);s=NULL;
   s=Input("BAL1.bmp");
   Negativ(s);
   Output("BAL11.bmp",s);
    printf("12\n");
    Ramka_24bit(h);
    Output("BAL12.bmp",h);
      printf("13\n");
    BMPHEAD *k;
    k=Input("ball.bmp");
    Output("BAL13.bmp",k);
    printf("11\n");
   FILE * fh;
   fh=fopen("Ceat.bmp","wb");
   creaty_f_PMB_1_bit(fh);
       printf("Creaty f.\n");

      printf("14\n");
    BMPHEAD *k1;
    k1=Input_8bit_pal("Ceat.bmp");
    VivodDanIs(k1);
//    Output_8bit_pal("BAL14.bmp",k1);

/*printf("------------------------------\n");
for(i=0;i<900;i++)
 {for(j=0;j<900;j++)
  {printf("%d ",m->g[i][j]);
  }
  printf("\n");
 }
printf("------------------------------\n");*/
 free(s->g);
 free(m->g);
 free(h->g);
 free(m);m=NULL;
 free(s);s=NULL;
 free(h);h=NULL;
return 0;
}
