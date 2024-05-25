#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "fun.h"



/*int main(void)
{FILE *f;char str[256],word[256],*sbegin,*send;
 f=fopen("in.txt","r");
 if(f)
 	{while(fgets(str,256,f))
		{for(sbegin=strchr(str,'"'), send=(sbegin?strchr(sbegin+1,'"' ):NULL);
		 sbegin&&send;sbegin=strchr(send+1,'"'),send=(sbegin?strchr(sbegin+1,'"'):NULL) )
			{strncpy(word,sbegin+1,send -sbegin -1);word[send-sbegin-1]='\0';
			if(*word>='A'&& *word<='Z')
			 printf(" %s\n ",word);
			}
		}
	fclose(f);
 	}
}
*/
int search(const char *SInputFile, char *ftr)
{FILE *f;char word[512],chek[512],*nacal1,*zup;int i,k1,k2,l,d=512;
 f=fopen(SInputFile,"r");
 if(f==NULL)return -1;
 while(fgets(chek,512,f))
  {printf("Read text:%s\n",chek);
	 for(;strchr(chek,',')!=0;){zup=strchr(chek,',');*zup=' ';}
	 for(;strchr(chek,'.')!=0;){zup=strchr(chek,'.');*zup=' ';}
	 printf("word processed.\n");
	 for(nacal1=chek;sscanf(nacal1,"%s%n",word,&k1)==1;nacal1+=k1)
		{printf("%s  ",word);l=strlen(word);if(word[0]!='A'){l=0;goto qr;}
		 for(i=1;i<l;i++)if( (word[i])<'A' || (word[i])>'Z' ){l=0;goto qr;}
		 if(l<d){sscanf(word,"%s",ftr);d=l;}
		qr:;
		}
		printf("\n\n");
	// printf("<%s>\n\n",ftr);
  }
 fclose(f);
return strlen(ftr);
}
