#include <stdio.h>
ssize_t getrandom(void *, size_t, unsigned int);
#define TOSTR(X) #X
#define LINE2STR(X) TOSTR(X)
#define DINFO __FILE__ "|" LINE2STR(__LINE__)

int main()
{
    unsigned int random = 0;
    if(-1 == getrandom((void *)&random, sizeof(unsigned int), 0)){
        perror(DINFO);
        return 1;
    }
    printf("%u\n", random);
    perror(DINFO);
    return 0;
}
