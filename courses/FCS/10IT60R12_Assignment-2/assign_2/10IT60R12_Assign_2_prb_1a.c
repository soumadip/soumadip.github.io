/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/

//infix evaluation


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct stack
{
	int value;
	struct stack *next;
	}stack;
stack *top=NULL;


int calculate(char*);
int itp(char*,char*);	

/* Name: push
      Input: integer
      Output: void
      Description: inserts a integer on top of the stack
         
         
   */

void push(int ch)
{
	stack *ptr;
	if(top==NULL)
	{
		top=(stack*)malloc(sizeof(stack));
		top->value=ch;top->next=NULL;
	}
	else
		{
				ptr=(stack*)malloc(sizeof(stack));
				ptr->next=top;
				ptr->value=ch;
				top=ptr;
				}
	}

/* Name: pop
      Input: void
      Output: popped value
      Description: pops the top value fron the stack
         
         
   */
int pop()
{
	int temp;
	stack *ptr;
	if (top==NULL)
	{
		printf("Underflow\n");
		exit(1);
	}
	else
	{
		temp=top-> value;
		ptr=top->next;
		free(top);
		top=ptr;
		return temp;
	}
}

/* Name: main method
      Input: void
      Output: success or failure
      Description: evaluates a infix expression
         
         
   */
int main()
{
	int i,out,testcase,success;
	char str[20],post[20];
	//printf("testcase-->");
	scanf("%d",&testcase);                                 
	while(testcase)
	{
		//printf("Input --> ");
		scanf("%s",str);
		printf("Input String --> %s\n",str);
		success=itp(str,post);
		if(success)out=calculate(post);
dec:		testcase--;
	if(success)printf("\nOutput=%d\n\n",out);
	}
	return 0;
}

/* Name: itp 
      Input: string in infix and string which receive postfix
      Output: success or failure
      Description: parses infix to postfix
         
         
   */
int itp(char *str,char* post)
{
	int i,j,temp=0,count=0;
	char ch;
	while(str[temp]!='\0')
		temp++;
	str[temp]=')';temp++;
	str[temp]='\0';
	push('(');i=0;j=0;
	while(str[i]!='\0')
	{
		if(str[i]>96 && str[i]<123)
		{
			post[j]=str[i];i++;j++;
		}
		else if(str[i]=='(')
		{
			push(str[i]);i++;count++;
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			if(i==0||i==19||(str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'||str[i+1]==')'))
			{printf("\nError in parsing infix expression...\n");return 0;}
			switch(str[i])
			{
			case '+':ch=pop();while(ch!='('){post[j]=ch;j++;ch=pop();}push(ch);break;
			case '-':ch=pop();while(ch!='('){post[j]=ch;j++;ch=pop();}push(ch);break;
			case '*':ch=pop();while(ch!='('&& ch!='-'&& ch!='+'){post[j]=ch;j++;ch=pop();}push(ch);break;
			case '/':ch=pop();while(ch!='('&& ch!='-'&& ch!='+'){post[j]=ch;j++;ch=pop();}push(ch);break;
			}
		push(str[i]);i++;
		}
		else if(str[i]==')')
		{
			ch=pop();
			while(ch!='(')
			{
				post[j]=ch;
				j++;
				ch=pop();
			}
		i++;count--;
		}
		else {printf("\n Sorry!! unknwn character --> %c\n",str[i]);return 0;}
		}
	post[j]='\0';
	if(count!=-1){printf("\nuneven no of parenthesis...\n");return 0;}
return 1;
}

/* Name: calculate
      Input: string in postfix
      Output: evaluated value of the expression
      Description: evaluates a postfix expression
         
         
   */
int calculate(char* str)
{
	int i=0,j,k,temp;
	char str1[20];
	while(str[i]!='\0')
	{
		if(str[i]>96 && str[i]<123)
		{
			//printf("%c= ",str[i]);
			scanf("%d",&temp);
			printf("%4d",temp);
			push(temp);
		}
		else
		{
			switch(str[i])
			{
				case '+': k=pop();j=pop();push(j+k);break;
				case '-': k=pop();j=pop();push(j-k);break;
				case '/': k=pop();j=pop();push(j/k);break;
				case '*': k=pop();j=pop();push(j*k);break;
				default: printf("Error..\n");exit(1);					
			}
		}
		i++;
	}
	return pop();
}
