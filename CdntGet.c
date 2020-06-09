#include "cds.h"

char **CdntGet(FILE *fp, int *type){
  char b[100];
  int i = 0, j = 0, k = 0;
  char **cdt;
  cdt = (char**)malloc(10*sizeof(char*));
  for(i=0;i<10;++i)
    {
      cdt[i]=(char*)malloc(10*sizeof(char));
      for(j=0;j<10;++j)
        {
	  cdt[i][j] = '\0';
        }
    }
  i = 0; j = 0;
  while((fgets(b,100,fp)) != NULL){
    if(strstr(b,"CDS") != NULL){
      if(strstr(b,"complement")) *type = 0;
      if(strstr(b,"join")) *type = 1;
      while(b[i] != '\0'){
        if(b[i] >= '0' && b[i] <= '9') cdt[j][k++] = b[i];
        if(b[i-1] >= '0' && b[i-1] <= '9' && (b[i] < '0' || b[i] > '9')){j++; k=0;}
        i++;
      }
    }
    else continue;
  }
  return cdt;
}
