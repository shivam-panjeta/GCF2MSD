#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_LEN 100

int main(int argc,char *argv[])
{
  if(argc==2
  {
    char     gcffile[MAX_LEN+1];     /* input GCF file */
    FILE     *gcf;                   /* pointer to GCF file */

    /* get parameters */
    strcpy( gcffile, argv[1] );

    gcf = fopen( gcffile, "r" );
    if  (gcf == NULL)  {
  		fprintf(stderr, "%s: cannot open input file %s\n", argv[0], gcffile );
  		return 1;
  	} /*endif*/

    system(dirf);
  /* Run dirf command */

    system(gursei);
  /* Run gursei command */       /* converts gcf to seisan */

    system(wavetool);
  /* Run wavetool command */     /* converts seisan to mseed */


    fclose( gcf );
    return 0;
  }

  else
  {
    printf("Wrong input given\n" );
    return 1;
  }
}
