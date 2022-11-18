#include<stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include <pthread.h>
#define SIZE 3
#define PRODUCTCOUNT 20




////////GLOBAL VARIABLES DECLEARATTIONS/////////

int productionCount,consumeCount;		//keeps index for #production and #consume
int Buffer[SIZE];				//common buffer 
int in,out;					//keeps track of index at or from which next item to be produced or consumed
int count;					//keeps count of the no of item in buffer

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;



/*


*/
void* producer(void *arg)
{
	int producedItem;
	while(productionCount<PRODUCTCOUNT)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of production here in microseconds
		producedItem=rand()%1000;	//produce random item

		while(count==SIZE);//printf(".");	//if the buffer is full then busywait for any consuming event

		pthread_mutex_lock( &mutex1 );//P(s);	//acquire the semaphore
		Buffer[in]=producedItem;			//add produced item
		in=(in+1)%SIZE;					//set the next in pointer
		count++;					//increase no the item in the buffer by one
		printf("Produced:#%3d: %d\n",++productionCount,producedItem);
		pthread_mutex_unlock( &mutex1 );//V(s);//release the semaphore
	}

	return NULL;
}


/*


*/
void* consumer(void *arg)
{
	int consumedItem;
	while(consumeCount<PRODUCTCOUNT)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of consuming here in microseconds

		while(count==0);//printf("-");		//if the buffer is empty then busywait for any production event

		pthread_mutex_lock( &mutex1 );//P(s);	//acquire the semaphore
		consumedItem=Buffer[out];			//consume one item
		out=(out+1)%SIZE;				//set the next out pointer
		count--;					//decrease the no the item in buffer by one
		printf("\t\tConsumed:#%3d: %d\n",++consumeCount,consumedItem);
		pthread_mutex_unlock( &mutex1 );//V(s);//release the semaphore
	}

	return NULL;
}


//////////////////////////////////
/////   THE MAIN FUNCTION   //////
//////////////////////////////////

int main(void)
{
	pthread_t pro,con;				//these are thread identifier

	printf("main waiting for Pro--Con to terminate...\n\n");

	pthread_create(&pro,NULL,producer,NULL);	//fork//creates producer thread and calls the producer function
	pthread_create(&con,NULL,consumer,NULL);	//fork//creates consumer thread and calls the consumer function


	pthread_join(pro,NULL);			//join//wait for producer process to complete
	pthread_join(con,NULL);			//join//wait for consumer process to complete

	printf("DONE...\n");
	return 0;
}

