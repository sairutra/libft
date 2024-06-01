#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <pthread.h>
#include <unistd.h>

// acknowledgement https://www.vishalchovatiya.com/hack-c-cpp-application-using-rtld-next-with-an-easy-example/
// compilation 
// gcc -fPIC -shared -o malloc.so malloc.c -ldl -pthread && LD_PRELOAD=./malloc.so your_application



// Function pointer to hold the original malloc
static void *(*real_malloc)(size_t) = NULL;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Constructor function to initialize real_malloc
__attribute__((constructor))
void init_malloc() {
	pthread_mutex_lock(&lock);
	if (real_malloc == NULL) {
		real_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
		if (real_malloc == NULL) {
			const char *error_msg = "Error in dlsym for malloc\n";
			write(STDERR_FILENO, error_msg, sizeof(error_msg));
		}
	}
	pthread_mutex_unlock(&lock);
}

// Overriding malloc
void *malloc(size_t size)
{
	void *ret;
	if (real_malloc == NULL) {
		const char *error_msg = "malloc called before initialization\n";
		write(STDERR_FILENO, error_msg, sizeof(error_msg));
		return NULL;
	}

	const char *msg = "Our Malloc\n";
	write(STDOUT_FILENO, msg, 11);
	ret = real_malloc(size);

	return (ret); // Call the original malloc
}
