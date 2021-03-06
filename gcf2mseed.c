#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int year,month,date,i;
  char gur[100],wav[100],final_file[100],sys_file[100],stn_code[100],cat_cmd[100],c;
  printf("Tell the year,month and date of records to be considered?\n");  //Taking input from user
  printf("Year : ");    scanf("%d",&year);
  printf("\nMonth : ");   scanf("%d",&month);
  printf("\nDate : ");   scanf("%d",&date);
  printf("\nEnter Station Code : ");
  scanf("%s\n",stn_code );

  int julian = date;                          //Computes Julian day
  int mm = month-1;
  switch(mm)
  {
  case 11 : julian=julian+30;
  case 10 : julian=julian+31;
  case 9 : julian=julian+30;
  case 8 : julian=julian+31;
  case 7 : julian=julian+31;
  case 6: julian=julian+30;
  case 5: julian=julian+31;
  case 4 : julian=julian+30;
  case 3 : julian=julian+31;
  case 2 : if(year%4==0)julian=julian+29;
               else julian=julian+28;
  case 1 : julian=julian+31;
  }

  for(i=0;i<24;i++)                             //Run Gursei command
  {
    sprintf(gur,"dirf %d%d%d_%02d*.gcf",year,month,date,i);
    system(gur);
    system("./gursei.m");
  }
  for(i=0;i<24;i++)                             //Run Wavetool command
  {
    sprintf(wav,"dirf %d-%d-%d-%02d*S*%s*",year,month,date,i,stn_code);
    system(wav);
    system("./mwavetool.sh");
  }

  sprintf(final_file,"%s%d%d.seed",stn_code,year,julian);          //Combining Files

  sprintf(cat_cmd,"cat /home/guest1/Shivam/%d-%d-%d*M* > %s",year,month,date,final_file);

  system(cat_cmd);

  printf("\n\n Output file is %s\n",final_file);
  system("rm *S*");                                     //Remove Seisan & MSeed files
  system("rm *M*");
  return 0;
}
