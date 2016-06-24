#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int year,month,date,i;
  char gur[100],wav[100],final_file[100],sys_file[100],stn_code[100],c;
  printf("Tell the year,month and date of records to be considered?\n");  //Taking input from user
  printf("Year : ");    scanf("%d",&year);
  printf("\nMonth : ");   scanf("%d",&month);
  printf("\nDate : ");   scanf("%d",&date);
  printf("\nEnter Station Code : ");
  scanf("%s\n",stn_code );

  int j[12],j_day;
  j[0]=31; j[1]=28+j[0]; j[2]=j[1]+31; j[3]=j[2]+30;
  j[4]=j[3]+31; j[5]=j[4]+30; j[6] = j[5]+31;
  j[7]=j[6]+31; j[8]=j[7]+30; j[9]=j[8]+31;
  j[10]=j[9]+30; j[11]=j[10]+31;

  if(year%4 == 0)                                 //Checking Leap Year
  {
    for(i=1;i<12;i++)
      j[i]++;
  }
  if(month>1)                                   //Computation of Julian Days
    j_day=j[month-2]+date;
  else
  {
    if(month ==1)
      j_day=date;
    else
      j_day = j[0]+date;
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

  sprintf(final_file,"%s%d%d.seed",stn_code,year,j_day);          //Combining Files
  for(i=0;i<24;i++)
  {
    sprintf(sys_file,"%d-%d-%d-%02d00-00M.%s__001BH_Z",year,month,date,i,stn_code);

    FILE *fp1 = fopen(sys_file, "r");

    if(fp1 == NULL)
      printf("Could not open file %s",sys_file);

    else{
      FILE *fp  = fopen(final_file, "w");

      while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp);

      fclose(fp);
      fclose(fp1);
    }

  }
  printf("\n\n Output file is %s\n",final_file);
  system("rm *S*");                                     //Remove Seisan & MSeed files
  system("rm *M*");
  return 0;
}
