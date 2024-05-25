#include<stdio.h>
#include<stdlib.h>
#include "fun.h"


SList  *Create()
{
 SList *l;
 l=(SList*)malloc(sizeof(SList));
 l->first=NULL;l->cur=NULL;
 return l;
}
//--------------------------------------------
void GoToEnd(SList *l)
{
 if(l&&l->first)
 {while(l->cur->next)l->cur=l->cur->next;//poka ne poslednii element pereiti k sledyishemy
 }
}
//-----------------------------------------------
void Add(SList *l,int k) //dobavliet posle i-ogo elementa spiska element ili zapolniet 0-oi element v sluchae ego nesychetv
{SNum *n;
 n=(SNum*)malloc(sizeof(SNum));
 n->v=k;
 n->next=NULL;
 if(l->first==NULL)
 {
  l->first=l->cur=n;
 }
 else
 {
  n->next=l->cur->next;
  l->cur->next=n;
 }
}
//--------------------------------------------------------------
void Del_(SList *l)
{SNum *t;
 if(l->cur==NULL)return;
 else if(l->cur==l->first)
   {if(l->cur->next==NULL)
      {free(l->cur);
       l->cur=l->first=NULL;
      }
    else
      {
       l->first=l->cur->next;
       free(l->cur);l->cur=l->first;
      }
   }
 else
 {ShiftDown(l);Del(l);
 }
return;
}
//--------------------------------------------------
void Del(SList *l)
{SNum *t;
 if(l->cur->next==NULL){return;}
 else if(l->cur->next->next==NULL)
 {
  free(l->cur->next);
  l->cur->next=NULL;
 }
 else
 {
  t=l->cur->next->next;
  free(l->cur->next);
  l->cur->next=t;
 }
return;
}
//--------------------------------------------------
void SwapCh(SList *l)
{int t;
 t=l->cur->v;
 l->cur->v=l->cur->next->v;
 l->cur->next->v=t;
}
//------------------------------------------------
void GoToStart(SList *l)
{if(l&&l->first)
 {l->cur=l->first;
 }
}
//----------------------------------------------
int ShiftUp(SList* l)
{if(l->cur->next==NULL)return -1;
 else l->cur=l->cur->next;return 0;
}
//----------------------------------------------
int ShiftDown(SList* l)
{SNum *t;
 if(l->cur==l->first)return -1;
 else
 {
  t=l->cur;l->cur=l->first;
  while(l->cur->next!=t)l->cur=l->cur->next;
 }
 return 0;
}
//------------------------------------------------
int NWSpis(const char *fs,SList ***l,int *n)
{FILE *f;int i,d,k;char str[256];char *nacal;
 f=fopen(fs,"r");
 if(f==NULL)return -1;
 for((*n)=0;(fgets(str,256,f)!=0)&&(sscanf(str,"%d",&d)==1);){(*n)++;}
 rewind(f);
 (*l)=(SList**)malloc(*n*sizeof(SList*));
 if((*l)==NULL){fclose(f);return -3;}
 for(i=0;fgets(str,256,f)&&(i<(*n));i++)
 {(*l)[i]=Create();
  for(nacal=str;sscanf(nacal,"%d%n",&d,&k)==1;nacal+=k)
     {
      GoToEnd((*l)[i]);Add((*l)[i],d);
     }
 }
 if(fgets(str,256,f)!=NULL){fclose(f);return 1;}
 fclose(f);
return 0;
}
//-------------------------------------------------
int VivodF(const char *fs,SList **l,int n)
{int i;FILE *f;
 f=fopen(fs,"w");if(f==NULL)return -1;
 for(i=0;i<n;i++)
  {
   for(l[i]->cur=l[i]->first;l[i]->cur;l[i]->cur=l[i]->cur->next)fprintf(f," %d",l[i]->cur->v);
   fprintf(f,"\n");
  }
 fclose(f);
return 0;
}
//------------------------------------------------
void Vivod(SList* l)
{
 for(l->cur=l->first;l->cur;l->cur=l->cur->next)printf("%d ",l->cur->v);
 l->cur=l->first;
 printf("\n");
}
//----------------------------------------
void Delete(SList *l)
{l->cur=l->first;
 while(l->cur->next!=NULL)
 {l->cur=l->cur->next;
  free(l->first);l->first=l->cur;
 }
  free(l->first);
l->first=l->cur=NULL;
}
//------------------------------------------
int Proga(SList **l,int *n)
{int i,p=-1,sum=0,q=0;int m[(*n)];
 for(i=0;i<(*n);i++){m[i]=-1; l[i]->cur=l[i]->first;}//zapolniem  massiv -1 i vozhvrachaem ukazateli "cur" na nachalo
 for(p=0,i=0;i<(*n);i++){sum=sum+(l[i]->cur->v);p++;}//poschitali srednee arifmeticheskoe v 1 stolbche
 for(q=0,i=0;i<(*n);i++)
   {
    if((p*(l[i]->cur->v))==sum){m[q]=i;q++;} //zapomnili nomera vozmozhnih strok
   }
 while(p!=0) //proveriem do tex por,poka "ShiftUp" ne srabotaet ni na odnom elemente
 {
  for(p=0,sum=0,i=0;i<(*n);i++){  if(ShiftUp(l[i])==0){sum+=(l[i]->cur->v);p++;}  } //chitaem srednee arifmetich. v novom
  for(i=0;i<q;i++)                                                                  //stolbche
    {  if((m[i]!=-1)&&( (l[m[i]]->cur->v)*p!=sum ))m[i]=-1;  //teper cravnivaem tolko te elementi,nomera kotorih legat v
    }                                                        //massive m[].
 }
 for(i=0;((i<(*n))&&(m[i]==-1));i++);// nahodim pervei ostavchisa nomer v massive m[].
 if(i==(*n))return 1;                // esli takogo net,to nichego ne izmenaem
 else
 {Delete(l[m[i]]);             //esli takoi est,to ydalaem spisok i sdvigaem ykazateli
  for(q=m[i];q<(*n)-1;q++)
   {l[q]=l[q+1];
   }
  (*n)--;                      //ymenchaem dlinny
 }
 return 0;
}
//---------------------------------------------------------------------------------
int  ProgKaT(SList **l,int n)
{int sum,i,q,d;
  for(i=0;i<n;i++)
    {

       l[i]->cur=l[i]->first;
           for(  q=1,sum=0,sum=sum+l[i]->cur->v;
                 l[i]->cur->next!=NULL;
                 q++,sum=sum+l[i]->cur->next->v  )l[i]->cur=l[i]->cur->next;
       l[i]->cur=l[i]->first;d=0;
           if( (l[i]->cur->v)*q==sum )goto nc;
           for(;l[i]->cur->next!=NULL;)
              {d++; l[i]->cur=l[i]->cur->next;
               if( (l[i]->cur->v)*q==sum )goto nc;
              }
       if(1==0)
        {
           nc:;
           if(d==0)
            {
             for(i=0;i<n;i++)Del_(l[i]);
            }
           else
            {
             for(i=0;i<n;i++)
               {
                q=0;l[i]->cur=l[i]->first;
                for(;(q<d )&&(l[i]->cur->next!=NULL);q++,l[i]->cur=l[i]->cur->next);
                if(q==d)Del_(l[i]);
               }
            }
         return 0;
        }


    }
return -1;
}

