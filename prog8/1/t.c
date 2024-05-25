#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t.h"
#include <ctype.h>
/*
 int main(void)
 {SStudent s;
  s.group=122;
  strcpy(s.name,"Petrov Vasilij");
  printf("%s: %d\n",s.name,s.group);
 return 0;
 }
*/

 int main(void)
  {int  n,i,group;SStudent *s;FILE *f;char str[512],*ss,sss*;
  f=fopen("t.txt","r");
  //fscanf(f,%d,&n);
  if(fgets(str,512,f)==NULL){printf("File empty\n");goto le;}
  if(sscanf(str,"%d",&n)!=1){printf("File empty2\n");goto le;}
  s=(SStudent*)malloc(n*sizeof(*s));
  for(i=0;i<n&&fgets(str,512,f)!=NULL&&sscanf(str,"%d",&group /* &s[i].group */)==1;i++)
  {
   s[i].group=proup;
   sscanf(str,"%d%n",&group/*&s[i].group*/,&l);
   ss=str+l;while(isspace(*ss))ss++;
   if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
   strcpy(s[i].name,ss);
  }
  n=i;
  printf("n=%d\n",n);
--------------
memcpy(s+n,s,sizeof(*s))
---------
for(i=0;i<n+1;i++)
  printf("%s: %d\n",s[i].name,s[i].group);
-------
 le:
  fclose(f);
  free(s);
  return 0;
  }

int main(void)
 {int  n,i,group;SStudent *s;FILE *f;char str[512],*ss,sss*;
 f=fopen("t.txt","r");
 //fscanf(f,%d,&n);
 if(fgets(str,512,f)==NULL){printf("File empty\n");goto le;}
 if(sscanf(str,"%d",&n)!=1){printf("File empty2\n");goto le;}
 s=(SStudent*)malloc((n+1)*sizeof(*s));
 for(i=0;i<n&&fgets(str,512,f)!=NULL&&sscanf(str,"%d",&group)==1;i++)
 {sscanf(str,"%d%n",&group,&l);
  ss=str+l;while(isspace(*ss))ss++;
  if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
  strcpy(s[i].name,ss);
 }
 n=i;
 printf("n=%d\n",n);
--------------
memcpy(s+n,s,sizeof(*s))
---------
for(i=0;i<n+1;i++)
  printf("%s: %d\n",s[i].name,s[i].group);
-------
le:
 fclose(f);
 free(s);
 return 0;
 }



*int main(void)
 {int  n,i,;SStudent **s;FILE *f;char str[512],*ss,sss*;
 f=fopen("t.txt","r");
 //fscanf(f,%d,&n);
 if(fgets(str,512,f)==NULL){printf("File empty\n");goto le;}
 if(sscanf(str,"%d",&n)!=1){printf("Ne zadano chiclo studetn\n");goto le;}
 s=(SStudent**)malloc((n+1)*sizeof(*s));
 for(i=0;i<n+1;i++)s[i]=(SStudent*)malloc(sizeof(**s));
 for(i=0;i<n&&fgets(str,512,f)!=NULL&&sscanf(str,"%d%n",&(s[i]->group,&l))==1;i++)
 {
  ss=str+l;while(isspace(*ss))ss++;
  if((sss=strchr(str,'\n'))!=NULL)*sss='\0';
  strcpy(s[i]->name,ss);
 }
 n=i;
 printf("n=%d\n",n);
memcpy(s[n],s[0],sizeof(**s));
for(i=0;i<n+1;i++)
  printf("%s: %d\n",s[i]->name,s[i]>group);

