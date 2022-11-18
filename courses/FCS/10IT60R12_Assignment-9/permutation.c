#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
this functions calculates all permutations
*/
void permutation(char *this, char* rest)
{

char *buff;
int i,j,k,len_this,len_rest;

	if(strlen(rest))
	{
		len_this=strlen(this);
		len_rest=strlen(rest);
		buff=(char*)calloc(len_rest,sizeof(char));
		for(i=0;i<len_rest;i++)
		{
			this[len_this+1]=this[len_this];
			this[len_this]=rest[i];				//add one symbol of rest to this
			this[len_this+1]='\0';

			for(j=0,k=0;j<=len_rest;j++)			//add all other symbol to a buffer
			if(i==j)
			continue;
			else
			{
				buff[k]=rest[j];
				k++;
			}
		permutation(this,buff);					//call recursively for each value
		}	
	}
	else 
	printf("%s\n",this);						//print when end is reached
}

/////////////////////
/////   MAIN  ///////
/////////////////////
void main()
{

char *buff1,*buff2;
char buffer[100];
int n;
printf("enter the string..(each character will be taken as distinct)\n");
scanf("%s",buffer);				//enter string
n=strlen(buffer);
	buff1=(char*)calloc(n,sizeof(char));
	buff2=(char*)calloc(n,sizeof(char));

	strcpy(buff1,buffer);
	//scanf("%s",buff1);
	printf("\n\n");


	permutation(buff2,buff1);		//call to permute
	printf("\n");
free(buff1);
free(buff2);
}
