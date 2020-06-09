#include "cds.h"

char *genename(FILE *fp){
  int i, j=0, flag=0;
  char b[100];
  char *name = (char *) malloc(100 * sizeof(char));
  for (i=0;i<100;i++) name[i] = '\0';
  while((fgets(b,100,fp)) != NULL){
    if (strstr(b,"/gene")) break;
  }
  for(i=0; b[i] != '\0'; i++){
    if(flag == 1) name[j++]=b[i];
    if(b[i] == '=') flag++;
    if(flag == 2) break;
  }
  name[j-1]='\0';
  return name;
}
