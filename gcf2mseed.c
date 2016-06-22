#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int year,month,date,i;
  char gur[100],wav[100],final_file[100],sys_file[100];
  printf("Tell the year,month and date of records to be considered?\n");
  printf("Year : ");    scanf("%d",&year);
  printf("\nMonth : ");   scanf("%d",&month);
  printf("\nDate: ");   scanf("%d",&date);
  printf("\n");

  for(i=0;i<24;i++)
  {
    sprintf(gur,"dirf %d%d%d_%02d*.gcf",year,month,date,i);
    system(gur);
    system("./gursei.m");
  }
  for(i=0;i<24;i++)
  {
    sprintf(wav,"dirf %d-%d-%d-%02d*S*",year,month,date,i);
    system(wav);
    system("./mwavetool.sh");
  }

  sprintf(final_file,"%d%d%d0000.mseed",year,month,date);
  for(i=0;i<24;i++)
  {
    sprintf(sys_file,"%d-%d-%d-%02d00-00M.DG64_001BH_Z",year,month,date,i);

    FILE *fp1 = fopen(sys_file, "r");

    if(fp1 == NULL)
      printf("Could not open file %s",sys_file);

    else{
      FILE *fp  = fopen(final_file, "w");
      char c;
      while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp);

      fclose(fp);
      fclose(fp1);
    }

  }
  printf("\n\n Output file is %s\n",final_file");
  system("rm *S*");
  system("rm *M*");
  return 0;
}
