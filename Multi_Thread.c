#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* thread_data){
	pthread_exit(0);
}

int main()
{
	void* thread_data = NULL;
	pthread_t thread;

	pthread_create(&thread, NULL, threadFunc, thread_data);

	pthread_join(thread, NULL);

	return 0;
}
