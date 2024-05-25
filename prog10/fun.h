#pragma once
typedef 
struct SNum_
{
 int v;
 struct SNum_ *next;
}SNum;
typedef
 struct SList_
{
 SNum *first;
 SNum *cur;
}SList;

#ifndef _FUN_H
int VivodF(const char *fs,SList** l,int n);
void Delete(SList *l);
int Proga(SList **l,int *n);
void Vivod(SList* l);
int NWSpis(const char *fs,SList ***l,int *n);
void SwapCh(SList *l);
void GoToStart(SList *l);
int ShiftUp(SList* l);
int ShiftDown(SList* l);
void Del_(SList *l);
int ProgKaT(SList **l,int n);
void Del(SList *l);
void GoToEnd(SList *l);
void Add(SList *l,int k);
SList  *Create();
#define _FUN_H
#endif



