#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/random.h>

int main()
{
    unsigned int random = 0;
    if(-1 != syscall(SYS_getrandom, (void *)&random, sizeof(unsigned int), 0)){
        printf("%u\n", random);
    } else {
        perror(NULL);
        return 1;
    }
    return 0;
}
