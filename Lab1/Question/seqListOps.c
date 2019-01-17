/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function

}
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
  s[0] = createlist();
  s[1] = createlist();
  s[2] = createlist();
  for(int i = 0; i<size; i++)
  {
    if(list[i].pri == PRI_0)
      s[0] = insert(list[i], s[0]); 
    if(list[i].pri == PRI_1)
      s[1] = insert(list[i], s[1]);
    if(list[i].pri == PRI_2)
      s[2] = insert(list[i], s[2]); 
  }
  copy_sorted_ele(s, list)  

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
  int c = 0;
  Store temp = st;
  for(int i = 2; i>=0; i--)
  {
    while(temp[i])
    {
      ele[c] = temp[i]->ele;
      temp[i] = temp[i]->next;
      c++;
    }
  }
      
 

}

void printlist(SeqList sl)
{

// Implement this function
  while(sl->next)
  {
    printJob(sl->job);
    sl =

}

void printJobList(JobList list, int size)
{

// Implement this function
  for(int i = 0; i<size; i++)
  {
     printJob(list[i]);
  }

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
