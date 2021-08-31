#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
	struct node*next;
};
typedef struct node node;
struct node *front=0;
struct node *rear=0;
struct node *root=NULL;
int len;
void append()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data :");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL) //inserting first node
	{
		root=temp;
	}
	else
	{
		struct node* var;
		var=root;
		//to know how many times to check:
		while(var->link!=NULL)
		{
			var=var->link;
		}
		var->link=temp; //the value is added
	}
}
int length()
{
	int count =0;
	struct node*temp;
	temp=root; //to start counting from the first node
	while(temp!=NULL)
	{
		count++;
		temp=temp->link; //to move to the next node
	}
	return count;
}

void display()
{
	struct node*temp;
	temp=root;
	if (temp==NULL)
	{
		printf("list is empty \n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("\n \n ");// sending the control to the next line
	}
}
void deleete()
{
	struct node*temp;
	int location;
	printf("Enter where you want to Delete:" );
	scanf("%d",&location);
	if(location>length())
	{
		printf("invalid location \n ");
	}	
	else if(location==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node*var=root,*q;
		int i=1;
		while(i<location-1) //to delete a node in the middle or at the end
		{
			var=var->link;
			i++;
		}
		q=var->link;
		var->link=q->link; //ignoring the delted node and pointing to the next one
		q->link=NULL;
		free(q);
	}
}
void addafter()
{
	int loc,len,i=1;
	struct node*temp,*p;
	printf("Enter location :");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("invalid location .\n");
		printf("the current length of list is %d :",len);
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		//read node data and store NULL value
		printf("enter node data :");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link; //right side connection
		p->link=temp; //left side connection
		
	}
	
}
struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;
void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}
int isempty(queue *q)
{
    return (q->rear == NULL);
}
void enqueue(queue *q, int value)
{
    if (q->count < length())
    {
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = value;
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
         else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}
int dequeue(queue *q)
{
    node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void displayy(node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}


int  main(){
	int choice;
	while(1)
	{
		printf("choose the operation :\n");
		printf("1.Append \n");
		printf("2.add at after \n"); 
		printf("3.length \n");
		printf("4.display \n");
		printf("5.delete \n");
		printf("6.quit \n");
		
		scanf("%d",&choice);
		if(choice==1)
		{
			append();
		}
		
		else if(choice==2)
		{
			addafter();
		}
		else if (choice==3)
		{
			len=length();
			printf("length: %d \n \n ",len);
		}
		else if(choice==4)
		{
			display();
		}
		else if(choice==5)
		{
			deleete();
		}
		else if(choice==6)
		{
			exit(1);
		}
		else
		{
			printf("invalid choice \n");
		}
	}
	queue *q;
    q = malloc(sizeof(queue));
    initialize(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    printf("Queue before dequeue\n");
    display(q->front);
    dequeue(q);
    printf("Queue after dequeue\n");
    display(q->front);
    return 0;
}	

