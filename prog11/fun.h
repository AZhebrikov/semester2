#pragma once
typedef
struct SStudentL_
{
 char name[512];
 int group;
 float Rating;
}SStudentL;


typedef
struct SStudent_
{
 char name[512];
 int group;
 int school;
 int IsElder;
 float Rating;
}SStudent;

void Publsort(int *m, int n);
void GroupRazdel(SStudent** m,int n);
#ifndef _FUN_H
void RaTsort(SStudent **m,int b,int l);
void Starost(SStudent **m,int n);
int DelSS(const char *fs,SStudent **m,int *n,int d,int a);
void Ratingsort(SStudent **m,int n);
void SortName(SStudent** m,int k, int p);
void Ratingsort_L(SStudentL **m,int n);
void Vivod(SStudent **m,int n);
void Vivod_L(SStudentL **m,int n);
int VivodR(SStudent **m,int n);
void  VivodR_L(SStudentL **m,int n);
int IMPyt(const char *fs,SStudent*** m,int *n);
void SortGroup_N(SStudent** m,int n,int D);
int IMPyt_L(const char *fs,SStudentL*** m,int *n);
#define _FUN_H
#endif


