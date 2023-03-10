/*Enter your name here*/
/* Enter your email here*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];
    int age;
    char address[100];
    int reg;
    int priority;
    struct node *next;
}node_t;

/* Inserting patients in the queue based on priority*/
node_t *insert(struct node *front)
{
    node_t *p,*temp;
    char name[20],address[100];
    temp=(node_t*)malloc(sizeof(node_t));
    printf("Enter patient Name:");
    scanf("%s", temp->name);
    printf("Enter the patient's age:");
    scanf("%d",&(temp->age));
    printf("Enter the address:");
    scanf("%s",temp->address);
    printf("Enter the reg no:");
    scanf("%d",&(temp->reg));
    printf("Enter the priority:");
    scanf("%d",&(temp->priority));
    int pri=temp->priority;

    /* check 2 conditions i. if there is no node present OR ii. if the priority 
       value is greater than priority of the node already present */
    if((front==NULL)||pri>front->priority)
    {
    /*---inserting newnode---*/
    temp->next=front;
    front=temp;/*put newnode address in front*/
    }
    else
    /*Traverse the list and find a position to insert a newnode*/
    {
        /*Move pointer p from the front*/
        p=front;
        while(p->next!=NULL && p->next->priority>=pri )
        {
            p=p->next; /* move the pointer p to the next node until you find 
                          the position of insertion.*/
        }
        temp->next=p->next;
        p->next=temp;
    }
    return front;
}

/* Delete the node which is present at the front*/
node_t *delete(struct node *front)
{
    node_t *temp;
    if(front==NULL)
    {
        printf("\n NO PATIENT RECORD TO DELETE");
        return front;
    }
    else
    {
        temp= front; /*place the front pointer in temp*/
        /*Print the record to be deleted*/
        printf("\n Deleted Record is : %d",temp->reg);
        printf("\n Patient's name is:%s", temp->name);
        printf("\n Patient's age: %d", temp->age);
        /*Move the start pointer to next position*/
        front=front->next;
        free(temp); /*  delete the node*/
    }
    return front;
}

/* To display the patients records */
void display(node_t *front)
{
    node_t *temp=front;
    if(front==NULL)
        printf("\nTHERE IS NO PATIENT");
    else
    {
        printf("\nPriority wise appointments are:\n");
        while(temp!=NULL)
        {
            printf("The name of patient is:%s\n",temp->name);
            printf("The age of patient is:%d\n",temp->age);
            printf("The address of patient is : %s\n",temp->address);
            printf("---------------------------------------------------\n");
            temp=temp->next;
    
        }
    }
    return;
}

void freenode(node_t *temp)
{
    if(temp!=NULL){
        freenode(temp->next);
        free(temp);
    }
}

/*-----------------Main program---------------------------*/
int main()
{
    node_t *front=NULL;
    int option;
    do{

        printf("\t\t\t Hospital emergency room system\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.PATIENTS WAITING IN THE QUEUE\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            /*Select 1 to insert elements in the priority queue*/
            case 1:
            front= insert(front);
            break;
            /* Select 2 to delete the elements at the front of priority queue*/
            case 2:
            front= delete(front);
            break;
            /* Select 3 To display the elements present in the priority queue*/
            case 3:
            display(front);
            break;
            case 4:
            exit(0);
            break;
         }
    } while(option!=4);
    freenode(front);
    return 0;
}
