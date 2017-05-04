#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/random.h>

#define TOSTR(X) #X
#define LINE2STR(X) TOSTR(X)
#define DINFO __FILE__ "|" LINE2STR(__LINE__)

/* Write LENGTH bytes of randomness starting at BUFFER.  Return 0 on
   success and -1 on failure.  */
ssize_t
getrandom (void *buffer, size_t length, unsigned int flags) {
	syscall(SYS_getrandom, buffer, length, flags);
}

int main()
{
    unsigned int random = 0;
    if(-1 != getrandom((void *)&random, sizeof(unsigned int), 0)){
        printf("%u\n", random);
    } else {
        perror(DINFO);
        return 1;
    }
    perror(DINFO);
    return 0;
}
