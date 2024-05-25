#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main()
{char word[10],yes[4]="YES",no[3]="NO";
 scanf("%s",word);
 if(strcmp(word,"YES")==0)printf("->");
 if(strcmp(word,"NO")==0)printf("-<");
}
