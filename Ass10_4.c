//Write a program which create single thread and it accept one values from user and it returns some value to the caller thread.

/* Enter  number : 
10
Thread is created with ID : 595588672
Value received from main thread is : 10
Return value from thread is 11
End of the main.
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	int i = (int)ptr;
	printf("Value received from main thread is : %d\n",(int)ptr);
	pthread_exit(++i);
}

int main()
{
	pthread_t TID;
	int iNo = 0;
	int iRet = 0;
	int value = 0;
	
	printf("Enter  number : \n");
	scanf("%d",&iNo);
	
	iRet = pthread_create(&TID,
				NULL,
				ThreadProc,
				(int *)iNo);
				
	if(iRet != 0)
	{
		printf("Unable to create thread.\n");
		return -1;
	}
	
	printf("Thread is created with ID : %d\n",TID);
	
	pthread_join(TID,&value);
	printf("Return value from thread is %d\n",value);
	
	printf("End of the main.\n");
	
	return 0;
}
