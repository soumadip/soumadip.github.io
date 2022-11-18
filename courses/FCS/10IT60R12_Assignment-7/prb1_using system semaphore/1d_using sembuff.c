#include<stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include <pthread.h>
#define SIZE 10
#define PRODUCTCOUNT 20
#define P(s) semop(s, &pop, 1) 	/* pop is the structure passing to do the P(s) operation */
#define V(s) semop(s, &vop, 1) 	/* vop is the structure passing to do the P(s) operation */


/////////////////////////////////////
/////    SEMAPHORE STRUCTURE   //////
/////////////////////////////////////



////////GLOBAL VARIABLES DECLEARATTIONS/////////

int productionCount,consumeCount;		//keeps index for #production and #consume
int Buffer[SIZE];				//common buffer 
int in,out;					//keeps track of index at or from which next item to be produced or consumed
int count;					//keeps count of the no of item in buffer
int proNo,conNo;				//keeps track of the producer and consumer no

int mutex,empty,full;
struct sembuf pop, vop ;					




/*


*/
void* producer(void *arg)
{
	int producedItem;
	int producerNo;

	producerNo=++proNo;
	while(1)//(productionCount<PRODUCTCOUNT)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of production here in microseconds
		producedItem=rand()%1000;	//produce random item

		//while(count==SIZE);//printf(".");	//if the buffer is full then busywait for any consuming event

	P(full);
		P(mutex);
		Buffer[in]=producedItem;			//add produced item
		in=(in+1)%SIZE;					//set the next in pointer
		count++;					//increase no the item in the buffer by one

		printf("Produced:%d: #%3d: %d\n",producerNo,++productionCount,producedItem);
		V(mutex);
	V(empty);					
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
	while(1)//(consumeCount<PRODUCTCOUNT)
	{
		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of consuming here in microseconds

		//while(count==0&&consumeCount<PRODUCTCOUNT);//printf("-");		//if the buffer is empty then busywait for any production event

	P(empty);
		P(mutex);
		consumedItem=Buffer[out];			//consume one item
		out=(out+1)%SIZE;				//set the next out pointer
		count--;					//decrease the no the item in buffer by one	
	
		printf("\t\t\tConsumed:%d: #%3d: %d\n",consumerNo,++consumeCount,consumedItem);
		V(mutex);
	V(full);			
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
	
	mutex = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);//system call for creating semaphores
	empty = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	full  = semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	
	semctl(mutex, 0, SETVAL, 1);	//setting up values of semaphores
	semctl(empty, 0, SETVAL, 0);
	semctl(full, 0, SETVAL,SIZE);
	pop.sem_num = vop.sem_num = 0;	 //initializing the pop & vop sembufs
	pop.sem_flg = vop.sem_flg = 0;
	pop.sem_op = -1 ; //these should be added for while using system call
	vop.sem_op = 1 ;


	printf("Enter no of Producers:: ");
	scanf("%d",&m);
	printf("Enter no of Consumers:: ");
	scanf("%d",&n);

	pro=(pthread_t*)calloc(m,sizeof(pthread_t));
	con=(pthread_t*)calloc(n,sizeof(pthread_t));

	printf("\nmain waiting for %dPro--%dCon to terminate...\n\n",m,n);

	for(i=0;i<m;i++)pthread_create(&pro[i],NULL,producer,NULL);	//fork//creates producer thread and calls the producer function
	for(i=0;i<n;i++)pthread_create(&con[i],NULL,consumer,NULL);	//fork//creates consumer thread and calls the consumer function

	for(i=0;i<m;i++)pthread_join(pro[i],NULL);			//join//wait for producer process to complete
	for(i=0;i<n;i++)pthread_join(con[i],NULL);			//join//wait for consumer process to complete

	printf("DONE...\n");
	return 0;
}

