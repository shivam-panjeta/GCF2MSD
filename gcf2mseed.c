#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  int year,month,date,n,i;
  char gur[100],wav[100],final_file[100],sys_file_1[100],sys_file_2[100];
  printf("Tell the year,month and date of records to be considered.\n");
  scanf("%d%d%d",&year,&month,&date);

  for(i=0;i<24;i++)
  {
    sprintf(gur,"dirf %d%d%d_%02d*",year,month,date,i);
    system(str);
    system("./gursei.m");
  }
  for(i=0;i<24;i++)
  {
    sprintf(wav,"dirf %d-%d-%d-%02d*",year,month,date,i);
    system(wav);
    system("./mwavetool.sh");
  }

  sprintf(final_file,"%d-%d-%d-0000-M.DG64_001_BH_Z",year,month,date);
  for(i=0;i<12;i++)
  {
    sprintf(sys_file_1,"%d-%d-%d-%02d00-00M.DG64_001_BH_Z",year,month,date,2*i);
    sprintf(sys_file_2,"%d-%d-%d-%02d00-00M.DG64_001_BH_Z",year,month,date,2*i+1);
    FILE *fp1 = fopen(sys_file_1, "r");
    FILE *fp2 = fopen(sys_file_2, "r")
    FILE *fp  = fopen(final_file, "w");
    char c;

    while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp);

    while ((c = fgetc(fp2)) != EOF)
      fputc(c, fp);

    fclose(fp1);
    fclose(fp2);
    fclose(fp);
  }
  return 0;
}
