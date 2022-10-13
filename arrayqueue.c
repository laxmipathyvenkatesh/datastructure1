#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front = -1,rear = -1;
void insert(void);
int delete_elements(void);
int peek(void);
void display(void);
int main()
{
	int option,val;
	do
	{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n1.insert an elements \n2. delete an elements \n3. peek \n4. display the queue \n5. EXIT");
		printf("\n enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				insert();
				break;
			case 2:
				val= delete_elements();
				if(val != -1)
				printf("\n the number deleted is : %d", val);
				break;
			case 3:
				val=peek();
				if(val != -1)
				printf("\n the first value in queue is : %d", val);
				break;
			case 4:
				display();
				break;							
		}
	}
	while(option !=5);
	getch();
	return 0;
}

void insert()
{
	int num;
	printf("\n enter the number to be inserted in the queue : ");
	scanf("%d",&num);
	if(rear == MAX-1)
	printf("\n OVERFLOW");
	else if(front == -1 && rear == -1)
	front = rear = 0;
	else
	rear++;
	queue[rear]=num;
}

int delete_elements()
{
	int val;
	if(front== -1|| front>rear)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	else
	{
	
		val = queue[front];
		front++;
		if(front>rear)
		front=rear=-1;
		return val;
    }
}

int peek()
{
	if(front==-1||front>rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

void display()
{
	int i;
	printf("\n");
	if(front == -1||front>rear)
	printf("\n QUEUE IS EMPTY");
	else
	{
		for(i=front;i<= rear;i++)
		printf("\t %d",queue[i]);
	}
}
