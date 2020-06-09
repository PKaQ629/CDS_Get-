#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *CdsGet_cplmt(char **cdnt,char* s)
{
  int start = atoi(*(cdnt));
  int end = atoi(*(cdnt+1));


  char *cds;
  cds = (char*)malloc(sizeof(char)*(end - start + 2));
  int k = 0;
  for(int i = 0; i < end; i++)
    { if(i >= start-1)
	switch(s[i])
	  { case 'a':cds[k++] = 't';break;
	      case 'c':cds[k++] = 'g';break;
	      case 'g':cds[k++] = 'c';break;
	      case 't':cds[k++] = 'a';break;
	    default:printf("序列有错误");break;
	    }  
    }
  cds[k] = '\0';
  
  
  return cds;
  
}

int main()
{
  

  return 0;

}
