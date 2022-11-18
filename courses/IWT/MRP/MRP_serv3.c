//Author:: Soumadip Biswas
//Roll No:: 10IT60R12
//Assignment 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<pthread.h>
#include<sys/socket.h> 
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>

#ifndef IP
#define IP "10.14.87.244"
#endif
#ifndef PORT
#define PORT 60112
#endif
#define SOCK_MRP 100
#define SIZE 255
#define ETX 3
#define R_TYPE 1
#define U_TYPE 2

#define P(s) semop(s, &pop, 1)  /* pop is the structure we pass for doing the P(s) operation */
#define V(s) semop(s, &vop, 1)  /* vop is the structure we pass for doing the V(s) operation */

////////Structure definitions /////////

typedef struct unackd
{
	char packet[SIZE];
	struct timeval timestamp;
	char addr[15];
	int portno;
	struct unackd *next;
}unackd;


typedef struct recvd
{
	char packet[SIZE];
	char addr[15];
	int portno;
	struct recvd *next;
}recvd;

//////////////////////////////////////////


///////global variables///////

unackd *unackdBuff;
recvd *recvdBuff;

int sockfd;
int unackSem, recvSem ;
struct sembuf pop,vop ;
pthread_t pth[2];
pthread_t R,S;
int ackCounter=0;

//////////////////////////////



////// function prototypes ///////

void sigInt();
void fflushstdin();
void* send_routine(void* arg);
void* receive_routine(void* arg);
int r_socket(int domain, int type, int protocol);
int r_bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
ssize_t r_sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr_in *dest_addr, socklen_t addrlen);
ssize_t r_recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr_in *src_addr, socklen_t *addrlen);
int r_close(int fd);
int dropMessage();
long timevaldiff(struct timeval *starttime, struct timeval *finishtime);
int destroy(void* ptr, int type);

///////////////////////////////////



//////////////////////////
///// MAIN FUNCTION //////
//////////////////////////

int main()
{
	char cBuff[SIZE]="",temp[2];
	socklen_t length;
	int i,len;
	struct sockaddr_in cAddress,sAddress;
	
	signal(SIGINT,sigInt);
	
	if((sockfd=r_socket(AF_INET,SOCK_MRP,0))<0)
	{
		perror("SocketError");
		exit(0);
	}
	printf("Socket Created\n");
	
	sAddress.sin_family = AF_INET;					//setting values
	sAddress.sin_addr.s_addr = INADDR_ANY;
	sAddress.sin_port = htons(PORT);
	
	if(r_bind(sockfd,(struct sockaddr*)&sAddress,sizeof(sAddress)) < 0)	//binding
	{
		perror("BindError");
		exit(0);
	}
	printf("Binding Done\n");
	
	length=sizeof(cAddress);
	r_recvfrom(sockfd, cBuff, SIZE, 0,&cAddress, &length);		//receipt msg from client
	printf("\n\tData Received:: %s\n",cBuff);
	
	strcpy(cBuff,"received your data..");
/*	printf("sending reply started..............\n");
	for(i=0;i<=len;i++)
	{
		temp[0]=cBuff[i];
		temp[1]='\0';
		r_sendto(sockfd, temp,2, 0,&cAddress, sizeof(cAddress));
	}
//	r_sendto(sockfd, cBuff, strlen(cBuff), 0,&cAddress, sizeof(cAddress));
*/	
	pthread_join(R,NULL);
	pthread_join(S,NULL);
	
//	r_close(sockfd);

}


/*
		This function opens an UDP socket with the socket call. It also creates the
	2 threads R and S, and allocates initial space for the tables. The parameters to these
	are the same as the normal socket( ) call, except that it will take only SOCK_MRP as
	the socket type.
*/
int r_socket(int domain, int type, int protocol)
{
	key_t key1,key2;
	
		if(type!=SOCK_MRP)
		{
			fprintf(stderr,"r_socket:type supposed to be SOCK_MRP:");
			return -1;
		}
		if((sockfd = socket(domain,SOCK_DGRAM,0))<0)
		{
			return sockfd;
		}
	
		key1=ftok("/tmp/",8);
		key2=ftok("/tmp/",7);
		unackSem = semget(key1, 1, 0777|IPC_CREAT);
		recvSem = semget(key2, 1, 0777|IPC_CREAT);
	
		semctl(recvSem, 0, SETVAL, 1);
		semctl(unackSem, 0, SETVAL, 1);
	
		pop.sem_num = vop.sem_num = 0;
		pop.sem_flg = vop.sem_flg = 0;
		pop.sem_op = -1 ; vop.sem_op = 1 ;
		
		pthread_create(&R,NULL,receive_routine,NULL);
		pthread_create(&S,NULL,send_routine,NULL);
		

	return sockfd;

}

/*
		The thread S/send_routine behaves in the following manner. It sleeps for some time (T), and wakes up
	periodically. On waking up, it scans the unacknowledged-message table to see if any of
	the messages timeout period (set to 2T ) is over (from the difference between the time in
	the table entry for a message and the current time). If yes, it retransmits that message and
	resets the time in that entry of the table to the new sending time. If not, no action is taken.
	This is repeated for all messages in the table every time S wakes up.
*/
void* send_routine(void* arg)
{
	int i;
	unackd *ptr;
	char buf[SIZE];
	struct sockaddr_in sAddress;
	struct timeval now;

	pth[0]=pthread_self();
	
	while(1)
	{
		i=0;
		usleep(150000);
		P(unackSem);
			ptr=unackdBuff;
			while(ptr!=NULL)
			{
				gettimeofday(&now,NULL);
				if(timevaldiff(&ptr->timestamp,&now)>=300)
				{
					gettimeofday(&ptr->timestamp,NULL);

					sAddress.sin_family = AF_INET;
					sAddress.sin_addr.s_addr = inet_addr(ptr->addr);
					sAddress.sin_port = htons(ptr->portno);
					
					buf[0]='1';
					strcpy(&buf[1],ptr->packet);
					
					sendto(sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&sAddress,sizeof(sAddress));
					printf("Resend:: (%d)%s\n",buf[1],buf+2);
				
				}
				ptr=ptr->next;
			}
			
		V(unackSem);
	}

}




/*
		The thread R/receive_routine behaves in the following manner. When it receives a message, if 
	it is a data message, it stores it in the received-message table, and sends an ACK message to the
	sender. If it is an ACK message in response to a previously sent message, it updates the
	unacknowledged-message table to take out the message for which the acknowledgement
	has arrived.

*/
void* receive_routine(void* arg)
{
	socklen_t length;
	unackd *ptr,*prev;
	recvd *ptr1;
	char pack[SIZE],ack[2];
	struct sockaddr_in cAddress;

	length=sizeof(cAddress);
	pth[1]=pthread_self();
	while(1)
	{
		recvfrom(sockfd,pack,SIZE, 0,(struct sockaddr *)&cAddress, &length);
		
		switch(pack[0])
		{
			case '0':
				P(unackSem);
					
					prev=ptr=unackdBuff;
					while(ptr!=NULL)
					{
						if(ptr->packet[0]==pack[1])	//&&!strcmp(ptr->addr,inet_ntoa(cAddress.sin_addr)))
						{
							ackCounter--;printf("\nAcounter now%d\n",ackCounter);
							if(!(ackCounter-1))
							{
								unackdBuff=NULL;
								cAddress.sin_family = AF_INET;
								cAddress.sin_addr.s_addr = inet_addr(IP);
								cAddress.sin_port = htons(PORT);
								pack[0]='1';pack[1]=255;pack[2]='\0';
								sendto(sockfd,pack,strlen(pack)+1,0,(struct sockaddr*)&cAddress,sizeof(cAddress));
							}
							
							if(ptr==unackdBuff)
							unackdBuff=unackdBuff->next;
							else
							prev->next=ptr->next;
							printf("ack recved:: %d\n",pack[1]);
							free(ptr);
							break;
						}
						prev=ptr;
						ptr=ptr->next;
					}
				V(unackSem);
				break;
			case '1':
				P(recvSem);
					ptr1=recvdBuff;
					if(recvdBuff==NULL)
					ptr1=recvdBuff=(recvd*)malloc(sizeof(recvd));
					else
					{
						while(ptr1->next!=NULL)
						ptr1=ptr1->next;
						
						ptr1->next=(recvd*)malloc(sizeof(recvd));
						ptr1=ptr1->next;
					}
				//	printf("data received---%c\n",pack[2]);
					printf("%s",pack+2);
					strcpy(ptr1->packet,pack+2);
					strcpy(ptr1->addr,inet_ntoa(cAddress.sin_addr));
					ptr1->portno=ntohs(cAddress.sin_port);
					ptr1->next=NULL;
				V(recvSem);
				ack[0]='0';
				ack[1]=pack[1];
				if(dropMessage()>=500)
					{
						sendto(sockfd,ack,2,0,(struct sockaddr*)&cAddress,sizeof(cAddress));
			//			printf("ack send:: %d\n",ack[1]);
					}
			//		else printf("dropped ack:: %d\n",ack[1]);
				break;
		
		}
	}

}


/*
		binds the socket with some address-port using the bind call.
*/
int r_bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
	int ret;
	if((ret=bind(sockfd,addr,addrlen))<0)
	{
		fprintf(stderr,"r_bind : cannot bind");
		return -1;
	}
	return ret;
}


/*
		sends the message immediately by sendto. It also adds a message sequence
	no. at the beginning of the message and stores the message along with its sequence
	no. and destination address-port in the unacknowledged-message table before
	sending the message. With each entry, there is also a time field that is filled up
	nitially with the time of first sending the message.

*/
ssize_t r_sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr_in *dest_addr, socklen_t addrlen)
{
	int ret=0;
	int counter=0;
	char temp[SIZE];
	char cBuf[SIZE+2];
	unackd *ptr;
	
		P(unackSem);
		cBuf[0]='1';
		cBuf[1]=++ackCounter;
		strcpy(&cBuf[2],(char*)buf);
		printf("snt-->%c%d%s\n",*cBuf,cBuf[1],cBuf+2);
		ptr=unackdBuff;
		if(unackdBuff==NULL)
			ptr=unackdBuff=(unackd*)malloc(sizeof(unackd));
			else
			{
				while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=(unackd*)malloc(sizeof(unackd));
				ptr=ptr->next;
			}
			
		ret+=sendto(sockfd,cBuf,strlen(cBuf)+1,flags,(struct sockaddr*)dest_addr,addrlen);
		
		gettimeofday(&ptr->timestamp,NULL);
		strcpy(ptr->packet,cBuf+1);//printf("\n%c%d%s\tsend and written\n",cBuf[0],cBuf[1],ptr->packet+1);
		strcpy(ptr->addr,inet_ntoa(dest_addr->sin_addr));
		ptr->portno=ntohs(dest_addr->sin_port);
		ptr->next=NULL;
		V(unackSem);
/*		for(i=0;i<len;i++)
		{
			P(unackSem);
			ptr=unackdBuff;
			if(unackdBuff==NULL)
			ptr=unackdBuff=(unackd*)malloc(sizeof(unackd));
			else
			{
				while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=(unackd*)malloc(sizeof(unackd));
				ptr=ptr->next;
			}
			temp[0]='1';
			ptr->packet[0]=temp[1]=counter++;
			ptr->packet[1]=temp[2]=cbuf[i];
			ptr->packet[2]=temp[3]='\0';
			//usleep(115000);
			sendto(sockfd,temp,sizeof(temp)+1,flags,(struct sockaddr*)dest_addr,addrlen);
		//	printf("\n%c%d%c\tsend and written\n",temp[0],temp[1],temp[2]);
			gettimeofday(&ptr->timestamp,NULL);
			
			strcpy(ptr->addr,inet_ntoa(dest_addr->sin_addr));
			ptr->portno=ntohs(dest_addr->sin_port);
			ptr->next=NULL;
			V(unackSem);
		}
*/
	
	return ret;
}


/*
		looks up the received-message table to see if any message is already
	received in the underlying UDP socket or not. If yes, it returns the first message and
	deletes that message from the table. If not, it blocks the call. To block the r_recvfrom
	call, you can use sleep call to wait for some time and then see again if a message is
	received. r_recvfrom, similar to recvfrom, is a blocking call by default and returns to
	the user only when a message is available.

*/
ssize_t r_recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr_in *src_addr, socklen_t *addrlen)
{
	int counter=0,flag=0;
	recvd *ptr;//,*prev;
	char* cBuf=buf;
	while(strlen(cBuf)<len)
	{
	usleep(150000);
	P(recvSem);
		ptr=recvdBuff;
		while(ptr!=NULL)
		{
			if(!strcmp(ptr->packet,""))
			{
				flag=1;
				free(ptr);
				recvdBuff=NULL;
				break;
			}
			strcat(cBuf,ptr->packet);
			counter++;
			recvdBuff=recvdBuff->next;
			free(ptr);
			ptr=recvdBuff;
		}
	V(recvSem);
	if(flag) break;
	}
	return counter;
}


/*
		closes the socket; kills all threads and frees all memory associated with the
	socket. If any data is there in the received-message table, it is discarded.

*/
int r_close(int fd)
{
	key_t key1,key2;
	key1=ftok("/tmp/",8);
	key2=ftok("/tmp/",7);
	semctl(key1,0,IPC_RMID);
	semctl(key2,0,IPC_RMID);
	pthread_kill(pth[0],SIGKILL);
	pthread_kill(pth[1],SIGKILL);
	destroy(unackdBuff,U_TYPE);
	destroy(recvdBuff,R_TYPE);
	return close(fd);
}


/*
		where p is a probability between 0 and 1. This function first generates a random number
	between 0 and 1. If the generated number is < p, then the function returns 1, else it
	returns 0.


*/
int dropMessage()
{
	return rand()%1000;
}

int destroy(void* ptr, int type)
{
	void *temp;
	switch (type)
	{
		case U_TYPE :
			while(ptr!=NULL)
			{
				temp=((unackd*)ptr)->next;
				free((unackd*)ptr);
				ptr=temp;
			}
			return 1;
		case R_TYPE :
			while(ptr!=NULL)
			{
				temp=((recvd*)ptr)->next;
				free((recvd*)ptr);
				ptr=temp;
			}
			return 1;
		default:
			fprintf(stderr,"wrong type");
			return -1;

	}
}



long timevaldiff(struct timeval *starttime, struct timeval *finishtime)
{
  long msec;
  msec=(finishtime->tv_sec-starttime->tv_sec)*1000;
  msec+=(finishtime->tv_usec-starttime->tv_usec)/1000;
  return msec;
}

/*
my fflush(stdin)
*/
void fflushstdin( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' ); //pushes the pointer to EOF
}


/*
signal handler for ctrl+c
*/
void sigInt()
{
	printf("\nCtrl+C...\n");
	r_close(sockfd);
	exit(0);
}


