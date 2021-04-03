#include <stdio.h>
#include <pthread.h>

void* threadFunc1(void *thread_data);
void* threadFunc2(void *thread_data);

int counter1 = 1;
int counter2 = 100;

void* threadFunc1(void *thread_data)
{
	while (1)
	{
		counter1++;
		sleep(1);
		printf("counter1=%d\n",counter1);
		if (counter1 >= counter2)
		{
			printf("exit thread1\n");
			pthread_exit(0);
		}
	}
}

void* threadFunc2(void *thread_data)
{
	while (1)
	{
		counter2--;
		sleep(1);
		printf("counter2=%d\n",counter2);
		if (counter2 <= counter1)
		{
			printf("exit thread2\n");
			pthread_exit(0);
		}
	}
}

int main()
{
	void *thread_data1 = NULL;
	void *thread_data2 = NULL;
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, threadFunc1, thread_data1);
	pthread_create(&thread2, NULL, threadFunc2, thread_data2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
