#pragma once
typedef
struct SStudent_
{
 char name[256];
 int group;
 int school;
}SStudent;

#ifndef _FUN_H
void STRsort(SStudent **m, int v,int y);
int Vov(SStudent **m,int n);
int vivod(SStudent **s,int n);
int STRCput(const char *fs,SStudent ***s,int *n);
#define _FUN_H
#endif


