#include "cds.h"

int main(int argc, char* argv[]){
    int type = 1;
    int i, j;
    char s;
    char filename[20] = {'\0'};
    strcpy(filename,argv[1]);
    FILE *fp = fopen(filename,"r");
    FILE *fp1 = fopen(filename,"r");
    FILE *fp2 = fopen(filename,"r");
    FILE *fp3 = fopen("cds.fasta","w");
    char **nt = CdntGet(fp, &type);
    char *name = genename(fp1);
    char *origin = cds2str(fp2);
    char *cds;
    if(type == 0) cds = CdsGet_cplmt(nt, origin);
    if(type == 1) cds = CdsGet_join(origin, nt);
    fputc('>',fp3);
    fputs(name,fp3);
    fputc('\n',fp3);
    fputs(cds,fp3);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
