#include<stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include <pthread.h>
#define SIZE 10
#define PRODUCTCOUNT 20


/////////////////////////////////////
/////    SEMAPHORE STRUCTURE   //////
/////////////////////////////////////

typedef struct semaphore
{
	int val;

}sem;


////////GLOBAL VARIABLES DECLEARATTIONS/////////

int productionCount,consumeCount;		//keeps index for #production and #consume
int Buffer[SIZE];				//common buffer 
int in,out;					//keeps track of index at or from which next item to be produced or consumed
int count;					//keeps count of the no of item in buffer
int proNo,conNo;				//keeps track of the producer and consumer no

sem *s;					//global semaphore vaiable pointer



/*


*/
P(sem *sem_var)
{
	while(sem_var->val<0);			//busywait for semaphore variable to get access
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
	int producerNo;

	producerNo=++proNo;
	while(productionCount<PRODUCTCOUNT)//(1)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of production here in microseconds
		producedItem=rand()%1000;	//produce random item

		while(count==SIZE);//printf(".");	//if the buffer is full then busywait for any consuming event

		P(s);					//acquire the semaphore
		Buffer[in]=producedItem;			//add produced item
		in=(in+1)%SIZE;					//set the next in pointer
		count++;					//increase no the item in the buffer by one
		printf("Produced:%d: #%3d: %d\n",producerNo,++productionCount,producedItem);
		V(s);					//release the semaphore
	}

	return NULL;
}


/*


*/
void* consumer(void *arg)
{
	int consumedItem;
	int consumerNo;

	consumerNo=++conNo;
	while(consumeCount<PRODUCTCOUNT)//(1)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of consuming here in microseconds

		while(count==0&&consumeCount<PRODUCTCOUNT);//printf("-");		//if the buffer is empty then busywait for any production event

		P(s);					//acquire the semaphore
		consumedItem=Buffer[out];			//consume one item
		out=(out+1)%SIZE;				//set the next out pointer
		count--;					//decrease the no the item in buffer by one
		printf("\t\t\tConsumed:%d: #%3d: %d\n",consumerNo,++consumeCount,consumedItem);
		V(s);					//release the semaphore
	}

	return NULL;
}


//////////////////////////////////
/////   THE MAIN FUNCTION   //////
//////////////////////////////////

int main(void)
{
	pthread_t *pro,*con;				//these are thread identifier
	int m,n;
	int i;

	printf("Enter no of Producers:: ");
	scanf("%d",&m);
	printf("Enter no of Consumers:: ");
	scanf("%d",&n);

	pro=(pthread_t*)calloc(m,sizeof(pthread_t));
	con=(pthread_t*)calloc(n,sizeof(pthread_t));

	s=(sem*)malloc(sizeof(sem));			//allocates memory for semaphore variable
	printf("\nmain waiting for %dPro--%dCon to terminate...\n\n",m,n);

	for(i=0;i<m;i++)pthread_create(&pro[i],NULL,producer,NULL);	//fork//creates producer thread and calls the producer function
	for(i=0;i<n;i++)pthread_create(&con[i],NULL,consumer,NULL);	//fork//creates consumer thread and calls the consumer function

	for(i=0;i<m;i++)pthread_join(pro[i],NULL);			//join//wait for producer process to complete
	for(i=0;i<n;i++)pthread_join(con[i],NULL);			//join//wait for consumer process to complete

	printf("DONE...\n");
	return 0;
}

