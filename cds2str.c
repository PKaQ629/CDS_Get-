#include "cds.h"

char* cds2str(FILE* f){
	char c;
	char* s;
	s = (char*)malloc(200 * sizeof(char));
	char* seq;
	int i = 0, maxsize = 4000;
	seq = (char*)malloc(maxsize * sizeof(char));
	do {
		fgets(s, 1000, f);
	} while (strstr(s, "ORIGIN") == NULL);
	free(s);

	while ((c = fgetc(f)) != '/')
	{
		if (c == 'a' || c == 'g' || c == 'c' || c == 't')
		{
			seq[i] = c;
			++i;
		}
		if (i == maxsize)
		{
			maxsize += 4000;
			seq = (char*)realloc(seq, maxsize * sizeof(char));
		}
	}
	seq[i] = '\0';
	return seq;
}
