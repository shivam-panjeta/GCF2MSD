#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  int year,month,date,n,i;
str[100];
  printf("Tell the year,month and date of records to be considered.\n");
  scanf("%d%d%d",&year,&month,&date);
  printf("How many records you want to work with?\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    sprintf(str,"dirf %d%d%d_%02d*",year,month,date,i);
    system(str);
    system("./gursei.m");
  }
  return 0;
}
