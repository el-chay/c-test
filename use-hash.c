#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <search.h>

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

static int values[] = {1,2,3,4,5,6,7,8,9,10};
static int exit_value = 0;

#define TOSTR(X) #X
#define LINE2STR(X) TOSTR(X)
#define DINFO __FILE__ "|" LINE2STR(__LINE__)

#define PERROR() \
    exit_value = errno;\
    perror(DINFO);

#define ERROR(LABEL)\
    PERROR();\
    goto LABEL;

int main(int argc, char *argv[])
{
    struct hsearch_data *htab = calloc(1, sizeof(struct hsearch_data));

    if(!hcreate_r(100, htab)){
        PERROR();
        return 1;
    }
    ENTRY *found = NULL;
    for(int i=0; i<10; i++){
        ENTRY entry = { input[i], values+i };
        if(!hsearch_r(entry, ENTER, &found, htab)){
            ERROR(fin);
        }
    }

    for(int i=0; i<10; i++){
        ENTRY entry = { input[i], NULL };
        if(!hsearch_r(entry, FIND, &found, htab)){
            ERROR(fin);
        }
        printf("The entry is: %s, %d\n", found->key, *(int*)(found->data));
    }
    ENTRY entry = { "kkck", NULL };
    if(!hsearch_r(entry, FIND, &found, htab)){
        PERROR();
    }

fin:
    hdestroy_r(htab);
    return exit_value;
}
