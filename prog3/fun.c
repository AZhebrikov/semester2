#include<stdio.h>
#include<string.h>
#include<ctype.h>




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
{FILE *f;char word[512],chek[512],clog[512],*zup,*m;int l,k,d=512;
 f=fopen(SInputFile,"r");
 if(f==NULL)return -1;
 while(fgets(chek,512,f))
  {for(;scanf(chek,"%s",word)!=0;)
	{printf("Read word: %s\n",word);
	 for(;strchr(word,',')!=0;){zup=strchr(word,',');*zup=' ';}
	 printf("word processed.\n");
	 for(;scanf(word,"%s",clog)!=0;)
		{printf("%s",clog);l=strlen(clog);if(*clog!='A'){l=0;goto qr;}
		 for(m=clog+1,k=0;k<l;m++,k++)if( (*m)<'A' || (*m)>'Z' ){l=0;}
		 if(l==0);
		 else
		   {if(l<d){scanf(clog,"%s",ftr);d=l;}
	           }
		qr:;
		}
	 printf("\n");
	}
  }
return 0;
}
