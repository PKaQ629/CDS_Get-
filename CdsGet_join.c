#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *CdsGet_join(char *s, int (*cdnts)[2]);

char *CdsGet_join(char *s, char **cdnts){
  int xstart[5] = {0}, xend[5] = {0};
  int i = 0, j, k;
  int size = 0;
  while (cdnts[2 * i][0] != '\0')
  {
    xstart[i] = atoi(cdnts[2 * i]);
    xend[i] = atoi(cdnts[2 * i + 1]);
    ++ i;
    char tmp = cdnts[2 * i][0];
  }
  char **cds = malloc(sizeof(char *) * i);
  for ( j = 0; j < i; ++ j)
  {
    cds[j] = (char *)malloc(sizeof(char) * (xend[j] - xstart[j] + 2));
    size = size + xend[j] - xstart[j] + 2;
    for(k = xstart[j] - 1; k < xend[j]; ++k)
      *(cds[j] + (k - xstart[j] + 1)) = 0;
    for (k = xstart[j] - 1; k < xend[j]; ++ k)
    {
      *(cds[j] + (k - xstart[j] + 1)) = *(s + k);
      char a = *(s + k);
    }
    *(cds[j] + xend[j] - xstart[j] + 1) = '\0';
  }
  char *switchline = "\n", *CdsSeq = malloc(sizeof(char) * (size + i)), *endline = "\0";
  for (k = 0; k < size + i;  ++ k)
    *(CdsSeq + k) = 0;
  for (j = 0; j < i; ++ j)
  { 
    strcat(CdsSeq, cds[j]);
    if (j == i - 1)
    {
      strcat(CdsSeq, endline);

      break;
    }
   
    strcat(CdsSeq, switchline);
  }
  free(cds);
  return CdsSeq;
}