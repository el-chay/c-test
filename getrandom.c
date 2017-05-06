#include <unistd.h>
#include <sys/syscall.h>
#include <linux/random.h>

/* Write LENGTH bytes of randomness starting at BUFFER.  Return 0 on
   success and -1 on failure.  */
ssize_t
getrandom (void *buffer, size_t length, unsigned int flags) {
	syscall(SYS_getrandom, buffer, length, flags);
}
