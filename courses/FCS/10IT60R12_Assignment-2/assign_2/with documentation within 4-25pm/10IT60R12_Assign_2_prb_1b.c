/*
Computing Systems Lab
IT69101
(Autumn 2010)
Assignment #2 28/07/2010
*/
// infix to postfix


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct stack
{
	char value;
	struct stack *next;
	}stack;

stack *top=NULL;

/* Name: push
      Input: character
      Output: void
      Description: inserts a character on top of the stack
         
         
   */
void push(char ch)
{
	stack *ptr;//printf("pushed-->%c\n",ch);
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
char pop()
{
	char temp;
	stack *ptr;
	if (top==NULL)
	{
		printf("Underflow");
		exit(1);
	}
	else
	{
		temp=top-> value;
		ptr=top->next;
		free(top);
		top=ptr;//printf("popped-->%c\n",temp);
		return temp;
	}
}

/* Name: main method
      Input: void
      Output: success or failure
      Description: converts infix to postfix expression
         
         
   */
int main()
{
	int i,j,out,testcase,temp=0,count=0;
	char *str,*post,ch;
	str=(char*)malloc(sizeof(char)*20);
	post=(char*)malloc(sizeof(char)*20);
	//printf("testcase-->");
	scanf("%d",&testcase);                                 
	while(testcase)
	{
		//printf("Input --> ");
		scanf("%s",str);
		printf("Input String --> %s\n",str);
		while(str[temp]!='\0')temp++;
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
				if(i==0||i==19||(str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'||str[i+1]==')'||str[i+1]=='\0'))
				{printf("\nError in parsing expression...\n");goto dec;}
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
				{post[j]=ch;j++;ch=pop();}
				i++;count--;
			}
			else 
			{printf("\n Sorry!! unknwn character --> %c\n",str[i]);goto dec;}
		}
		post[j]='\0';count++;
		if(count==0)printf("\n%s\n",post);
		else printf("\nuneven no of parenthesis...\n");
dec:		testcase--;
	}
	
return 0;
}

