#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
this functions calculates all combinations
*/
void combination(char *this, char* rest,int r)
{

char *buff;
int i,j,k,len_this,len_rest;

	if(r>0)
	{
		len_this=strlen(this);
		len_rest=strlen(rest);
		buff=(char*)calloc(len_rest,sizeof(char));
		for(i=0;i<len_rest;i++)
		{
			this[len_this+1]=this[len_this];
			this[len_this]=rest[i];			//add one symbol from rest to this
			this[len_this+1]='\0';

			for(j=i+1;j<=len_rest;j++)
			buff[j-i-1]=rest[j];			//rest symbol startting from the picked,to a buffer

			if(strlen(buff)>=r-1)
			combination(this,buff,r-1);		//call recursively for each value
		}	
	}
	else
	printf("%s\n",this);

}

/////////////////////
/////   MAIN  ///////
/////////////////////
void main()
{
char *buff1,*buff2;
char buffer[100];
int r;
int n;
printf("enter the string..(each character will be taken as distinct)\n");
scanf("%s",buffer);				//enter string
scanf("%d",&r);					//enter r
n=strlen(buffer);
	buff1=(char*)calloc(n,sizeof(char));
	buff2=(char*)calloc(n,sizeof(char));

	strcpy(buff1,buffer);
	//scanf("%s",buff1);
	printf("\n\n");


	combination(buff2,buff1,r);				//call to combinate
	printf("\n");
free(buff1);
free(buff2);
}


