#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define __USE_GNU
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
#define ERROR_P() \
    exit_value = errno;\
    perror(__FILE__ "|" LINE2STR(__LINE__));

#define ERROR(LABEL)\
    ERROR_P();\
    goto LABEL;

int main(int argc, char *argv[])
{
    struct hsearch_data *htab = calloc(1, sizeof(struct hsearch_data));
    char errormsg[100];

    if(!hcreate_r(100, htab)){
        ERROR_P();
        return exit_value;
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
        ERROR_P();
    }

fin:
    hdestroy_r(htab);
    return exit_value;
}
