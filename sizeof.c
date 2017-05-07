#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *input[] = {
    "hola"
    ,"chao"
    ,"penca"
    ,"bakan"
    ,"shiwa"
    ,"weon"
    ,"guaton"
    ,"cueck"
    ,"caca"
    ,"pichi"
};

int main()
{
    #define PRINT(X) printf(#X":%lu\n", X)
	#define PARRAY(X) for(int i=0; i<10; i++) puts(X[i])
	PRINT(sizeof(input));
	PARRAY(input);
	puts("---");
	char *another[] = {
		"hola"
		,"chao"
		,"penca"
		,"bakan"
		,"shiwa"
		,"weon"
		,"guaton"
		,"cueck"
		,"caca"
		,"pichi" };
	PRINT(sizeof(another));
	PARRAY(another);
	puts("---");
	char **any = malloc(sizeof(another));
	memcpy(any, another, sizeof(another));
	PRINT(sizeof(any));
	PRINT(sizeof((char (*)[10])any));
	PARRAY(any);
    return 0;
}
