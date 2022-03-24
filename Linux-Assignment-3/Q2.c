/*
Q2.Write a program where thread cancel itself.(use pthread_cancel())
*/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *Name(void *threadid)
{
	printf("\nYuvraj Singh Solanki\n");
	while(1);
}

int main()
{
	pthread_t thread;
	
    	int rc,t=0;
    	printf("=====Creating thread===== \n");
    	rc = pthread_create(&thread,NULL,Name,NULL);
    
    	printf("\nThread ID :%u", thread);
    	sleep(6);
    
    	t = pthread_cancel(pthread_self);       //pthread_ cancel function caaling itself
    	if(t==0)
    	{
        	printf("\n=====Canceling thread=====\n");
    	}
    	printf("Thread ID : %u\n",thread);
  
    return 0;
}
