#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<pthread.h>
#include<signal.h>
#define SIZE 2
#define PRODUCTCOUNT 20


/////////////////////////////////////
/////    SEMAPHORE STRUCTURE   //////
/////////////////////////////////////

typedef struct semaphore
{
	int val;
	int BUFF;
}sem;


//void P(sem*);
//void V(sem*);

////////GLOBAL VARIABLES DECLEARATTIONS/////////

int productionCount,consumeCount;		//keeps index for #production and #consume
int Buffer[SIZE];				//common buffer 
int in,out;					//keeps track of index at or from which next item to be produced or consumed
int count;					//keeps count of the no of item in buffer

sem *s,*full,*empty;					//global semaphore vaiable pointer



/*


*/
P(sem *sem_var)
{
	while(sem_var->val<sem_var->BUFF);			//busywait for semaphore variable to get access

	sem_var->val--;			//acquire//decrease by one
}


/*


*/
V(sem *sem_var)
{
	sem_var->val++;			//release//increase by one
}



/*


*/
void* producer(void *arg)
{
	int producedItem;
printf("producer %u\n",pthread_self());
	while(productionCount<PRODUCTCOUNT)
	{
		//usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of production here in microseconds
		producedItem=rand()%1000;	//produce random item

		//while(count==SIZE);//printf(".");	//if the buffer is full then busywait for any consuming event
P(empty);
		P(s);					//acquire the semaphore
		Buffer[in]=producedItem;			//add produced item
		in=(in+1)%SIZE;					//set the next in pointer
		count++;					//increase no the item in the buffer by one
		printf("Produced:#%3d: %d\n",++productionCount,producedItem);
		V(s);					//release the semaphore
V(full);
	}

	return NULL;
}


/*


*/
void* consumer(void *arg)
{
	int consumedItem;
printf("consumer %u\n",pthread_self());
	while(consumeCount<PRODUCTCOUNT)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of consuming here in microseconds

		//while(count==0&&consumeCount<PRODUCTCOUNT);//printf("-");		//if the buffer is empty then busywait for any production event
P(full);
		P(s);					//acquire the semaphore
		consumedItem=Buffer[out];			//consume one item
		out=(out+1)%SIZE;				//set the next out pointer
		count--;					//decrease the no the item in buffer by one
		printf("\t\tConsumed:#%3d: %d\n",++consumeCount,consumedItem);
		V(s);					//release the semaphore
V(empty);
	}

	return NULL;
}


//////////////////////////////////
/////   THE MAIN FUNCTION   //////
//////////////////////////////////

int main(void)
{
	pthread_t pro,con;				//these are thread identifier

	//lock=(sem*)malloc(sizeof(sem));
	s=(sem*)malloc(sizeof(sem));s->BUFF=0;			//allocates memory for semaphore variable
	full=(sem*)malloc(sizeof(sem));full->BUFF=SIZE;
	empty=(sem*)malloc(sizeof(sem));empty->val=SIZE;empty->BUFF=SIZE;

	printf("main waiting for Pro--Con to terminate...\n");

	pthread_create(&pro,NULL,producer,NULL);	//fork//creates producer thread and calls the producer function
	pthread_create(&con,NULL,consumer,NULL);	//fork//creates consumer thread and calls the consumer function

	pthread_join(pro,NULL);			//join//wait for producer process to complete
	pthread_join(con,NULL);			//join//wait for consumer process to complete

	printf("DONE...\n");
	return 0;
}

