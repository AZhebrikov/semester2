#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#include <ctype.h>
#define SWAP(a,b) {(t)=(a);(a)=(b);(b)=(t);}
int STRCput(const char *fs,SStudent ***s,int *n )
{int  i,l;FILE *f;char str[512],*ss,*sss;
 f=fopen(fs,"r");
 if(f==NULL)return -1;
 if(fgets(str,512,f)==NULL){fclose(f);return -2;}  //File is empty
 if(sscanf(str,"%d",n)!=1){fclose(f);return -3;} //Ne zadano collichestvo
 (*s)=(SStudent**)malloc((*n)*sizeof(**s));
 if((*s)==NULL){fclose(f);return -4;}
 for(i=0;i<(*n);i++){(*s)[i]=(SStudent*)malloc(sizeof(***s));if((*s)[i]==NULL)break;}
 if( (i<(*n)) && ((*s)[i]==NULL) ){for(i=i-1;i>=0;i--)free((*s)[i]);free((*s));fclose(f);return -5;}
 for(i=0;i<(*n)&&fgets(str,512,f)!=NULL&&sscanf(str,"%d%n",&((*s)[i]->group),&l)==1;i++)
 {
  ss=str+l;if(sscanf(ss,"%d%n",&( (*s)[i]->school ),&l)!=1)break;
  ss=ss+l;while(isspace(*ss))ss++;
  if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
  strcpy((*s)[i]->name,ss);
 }
 if((*n)>i)
 {for(;i<(*n);i++){free((*s)[i]);}
  (*n)=i;printf("/--\nObrezanie posledovatelnosti/--\n");
 }
 fclose(f);
return 0;
}

int vivod(SStudent **s,int n)
{int i;
 printf("n=%d\n",n);
 for(i=0;i<n;i++)
 printf("%20s: %d %d\n",s[i]->name,s[i]->group,s[i]->school);
return 0;
}




void STRsort(SStudent **m, int v,int y)
{int i,d;SStudent *t;
 for(i=v;i<v+y-1;i++) {d=strcmp((m[i]->name),(m[i+1]->name));if(d>0)SWAP( m[i+1],m[i]);}
}


int Vov(SStudent **m,int n)
{int *g,*s;int i=0,q,v,c,y; SStudent *t;
 s=(int*)malloc(n*sizeof(int));
 if(s==NULL)return -1;
 g=(int*)malloc(n*sizeof(int));
 if(g==NULL){free(s);return -2;}
 while(i<n){g[i]=0;s[i]=0;i++;}
 g[0]=(m[0]->group);
 for(i=1;i<n;i++)
   {q=0;
    while((g[q]!=0)&&(q<n)){if(g[q]==(m[i]->group)){goto le;}q++; }
    g[q]=(m[i]->group);
    le:;
   }
 for(v=0,q=0;(q<n)&&(g[q]!=0);q++)
   {y=0;
    if(v!=n){s[0]=(m[v]->school);(m[v]->group)=g[q];y=1;}
    for(i=v+y;i<n;i++)
      {for(c=0;(c<n)&&(s[c]!=0);c++){if( (m[i]->school)==s[c] ){goto te;}}
       s[c]=(m[i]->school);SWAP(m[v+y],m[i]);(m[v+y]->group)=g[q];y++;
       te:;
      }
    if(y>1)STRsort(m,v,y);
    v=v+y;for(c=0;c<n;c++){s[c]=0;}
   }
 if(v<n)
 {
  for(i=v;i<n;i++) {(m[i]->group)=g[q-1];}
  free(g);
  free(s);
 return 1;
 }
  free(g);
  free(s);
return 0;
}

//

