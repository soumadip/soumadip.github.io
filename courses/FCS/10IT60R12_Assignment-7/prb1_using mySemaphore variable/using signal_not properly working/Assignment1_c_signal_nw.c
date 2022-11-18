#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<pthread.h>
#include<signal.h>
#define SIZE 10
#define PRODUCTCOUNT 200


/////////////////////////////////////
/////    SEMAPHORE STRUCTURE   //////
/////////////////////////////////////

typedef struct Process_List{
pthread_t tid;
struct Process_List* next;
}List;

typedef struct semaphore{
int val;
int process_count;
List *p_list;
}sem;

void P(sem*);
void V(sem*);

////////GLOBAL VARIABLES DECLEARATTIONS/////////

int productionCount,consumeCount;		//keeps index for #production and #consume
int Buffer[SIZE];				//common buffer 
int in,out;					//keeps track of index at or from which next item to be produced or consumed
int count;					//keeps count of the no of item in buffer

sem *s;					//global semaphore vaiable pointer


void sigstop()
{
	//signal(SIGCHLD,sigstop);
	printf("I have received a SIGSTOP\n");
}

void sigcont()
{
	//signal(SIGCONT,sigcont);
	printf("I have received a SIGCONT\n");
}



/*


*/
void P(sem *sem_var)
{
	List *ptr;
	ptr=sem_var->p_list;
	if(sem_var->val<0)
	{

	//block this thread

		if(ptr==NULL)
			ptr=sem_var->p_list=(List*)malloc(sizeof(List));
		else
		{	while(ptr->next)
				ptr=ptr->next;
			ptr=(List*)malloc(sizeof(List));
		}
		ptr->tid=pthread_self();
		//sem_var->process_count++;
	printf("going to stop %u---%u\n",pthread_self(),getpid());
		/*raise(SIGSTOP);/*/	pthread_kill(pthread_self(),SIGSTOP);
	printf("restart %u\n",pthread_self());
	
	}
	sem_var->val--;			//acquire//decrease by one
}


/*


*/
void V(sem *sem_var)
{
	List *ptr;
	ptr=sem_var->p_list;
	sem_var->val++;			//release//increase by one

	if(sem_var->val<0)
	{
	//wakeup a thread
	pthread_kill(sem_var->p_list->tid,SIGCONT);
	sem_var->p_list=ptr->next;
	free(ptr);
	//sem_var->process_count--;
	}

}


/*


*/
void* producer(void *arg)
{
	int producedItem;
printf("producer %u\n",pthread_self());

//signal(SIGSTOP,sigstop);
//signal(SIGCONT,sigcont);
	while(productionCount<PRODUCTCOUNT)
	{
	//	usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of production here in microseconds
		producedItem=rand()%1000;	//produce random item

		while(count==SIZE);//printf(".");	//if the buffer is full then busywait for any consuming event

		P(s);					//acquire the semaphore
		Buffer[in]=producedItem;			//add produced item
		in=(in+1)%SIZE;					//set the next in pointer
		count++;					//increase no the item in the buffer by one
		printf("Produced:#%3d: %d\n",++productionCount,producedItem);
		V(s);					//release the semaphore
	}

	return NULL;
}


/*


*/
void* consumer(void *arg)
{
	int consumedItem;
printf("consumer %u\n",pthread_self());
//signal(SIGSTOP,sigstop);
//signal(SIGCONT,sigcont);
	while(consumeCount<PRODUCTCOUNT)
	{
//		usleep(rand()%1000000);			//FREQUENCY LINE//control frequency of consuming here in microseconds

		while(count==0&&consumeCount<PRODUCTCOUNT);//printf("-");		//if the buffer is empty then busywait for any production event

		P(s);					//acquire the semaphore
		usleep(rand()%1000000);	
		consumedItem=Buffer[out];			//consume one item
		out=(out+1)%SIZE;				//set the next out pointer
		count--;					//decrease the no the item in buffer by one
		printf("\t\tConsumed:#%3d: %d\n",++consumeCount,consumedItem);
		V(s);					//release the semaphore
	}

	return NULL;
}


//////////////////////////////////
/////   THE MAIN FUNCTION   //////
//////////////////////////////////

int main(void)
{
	pthread_t pro,con;				//these are thread identifier
printf("mainThread %u\n",pthread_self());
//signal(SIGSTOP,sigchld);
	//lock=(sem*)malloc(sizeof(sem));
	s=(sem*)malloc(sizeof(sem));			//allocates memory for semaphore variable
	printf("main waiting for Pro--Con to terminate...\n");

	pthread_create(&pro,NULL,producer,NULL);	//fork//creates producer thread and calls the producer function
	pthread_create(&con,NULL,consumer,NULL);	//fork//creates consumer thread and calls the consumer function

	pthread_join(pro,NULL);			//join//wait for producer process to complete
	pthread_join(con,NULL);			//join//wait for consumer process to complete

	printf("DONE...\n");
	return 0;
}

