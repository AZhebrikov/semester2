int nahodit(int **m,int q,int *w)
{int i,k,l,d;
for(i=0,d=0;i<*w;i++)
 { for(k=0;k<q;k++)
        { for(l=0;l<*w;l++)
                 { if( (m[k][i]<=m[k][l])&&(l!=i)){d++;break;}
                 }
         if(d)break;
        }
  if(d==0)break;
  if(d)d=0;
 }
 if(i==*w)return 0;
for(k=0;k<q;k++)
 { for(l=i+1;l<*w;l++)
        {m[k][l-1]=m[k][l];
        }
 }*w=*w-1;
return 0;
}

int ??(int **m,int *q, int w)
{int i,k,l,sum=0;
 l=(*q)*w;
 for(i=0;i<(*q);i++)
 	{for(k=0;k<w;k++)sum=+m[i][k];
 	}
 sum=sum/l;
 for(i=0;i<(*q);i++)
        {for(k=0;k<w;k++) {   if(m[i][k]==sum){goto ,lc;}    }
	}
 lc:;for(;i<(*q);i++)
 	{m[i]=m[i+1];
	}
 (*q)=(*q)-1;
}
