/*
Q1.Write a multithreading program, where threads runs same shared golbal variable of the
process between them.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int globalVar = 5;


void *thread_increment(void *arg)
{
    globalVar++;
	printf("The incremented value of globalVariable is: %d\n", globalVar);
}

void *thread_decrement(void *arg)
{
    globalVar--;
	printf("The decremented value of globalVariable is: %d\n", globalVar);
}

int main()
{
	pthread_t thread1,thread2;

	
		pthread_create(&thread1,NULL,thread_increment,NULL);
		pthread_create(&thread2,NULL,thread_decrement,NULL);
	
		pthread_join(thread1,NULL);
		pthread_join(thread2,NULL);

        printf("globalVar = %d\n",globalVar);
	return 0;
}