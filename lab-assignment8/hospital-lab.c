/* Lab Assignment for Hospital ER */
// name: Minjia Tao
// email: tao.mi@northeastern.edu

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# define s 5        // capacity of priority queue 

int top = -1;

/*structure to define patient information*/
typedef struct node                   // node相当于是array
{
    char name[20];
    int age;
    char address[100];
    int reg;
    int priority;
} NODE;

/*structure to define heap*/
typedef struct {
    NODE *heap;
    int num;     // 这个是总数吗？
} pq;

// heap[0] -> max value 
// heap[1]
// heap[2]

/*creating priority queue*/
pq* pq_init(){                        
    pq* p=(pq*)malloc(sizeof(pq));    // allocate meoory for pq
    if(p == NULL)
    {
        printf("memory is not allocated\n");
        return NULL;
    }
    p->heap = (NODE*)malloc(s*sizeof(NODE));
    p->num = 0;
    return p;
}

/*swapping*/
void swap(NODE *a, NODE* b){
    NODE temp = *b;
    *b = *a;
    *a = temp;
}

// Algorithm
// Heapify(array, size, i)
//   set i as largest
//   leftChild = 2i + 1
//   rightChild = 2i + 2
  
//   if leftChild > array[largest]
//     set leftChildIndex as largest
//   if rightChild > array[largest]
//     set rightChildIndex as largest

//   swap array[i] and array[largest]

/* function to shift down the node to maintain the max heap property*/
void heapify(pq *p2,int n, int i){ // heap相当于是一个数组
    int largest = i;                 /*initialize largest as the root*/
    
    int lchild = 2*i + 1;           /*left =2*i+1*/ //就是index
    int rchild = 2*i + 2;           /*right=2*i+2*/
    /*insert your code here*/

    if (n == 1) {                             // 需要考虑只有一个root的情况吗？
        printf("Single element in the heap");
    }
    
    else {  // 找时间重新写
        if (lchild < n && p2->heap[lchild].priority > p2->heap[largest].priority) {
            largest = lchild;
        } 
        if (rchild < n && p2->heap[rchild].priority > p2->heap[largest].priority) {
            largest = rchild;
        }
        if (largest != i) {
            swap(&(p2->heap[largest]), &(p2->heap[i]));   //改地址指向的内容
            heapify(p2, n, largest);
        }
    }
}

/* To shift the new node (inserted at the end) up at its appropriate position in order to satisfy the max heap property */ 
void shiftUp(pq* p2,int i)
{
    /*insert your code here*/
    // 为什么不用链表？插n个
    if (p2->num == 0) {
        p2->heap[0] = p2->heap[i];
        p2->num++;
    }
    else {
        p2->heap[p2->num-1] = p2->heap[i]; // 最后一位
        for(int i = p2->num / 2 - 1; i >=0; i--) { //为什么？
            heapify(p2,p2->num, i); // 不用再写*，之前已经clarify了
        }
    }  
}
 
/*function to insert patient info into the heap*/
void insert(pq* p2)
{
    ++top;
    /* Take Parent info. from terminal and place it in p2->heap at the last position*/
    char name[20],address[100];
    NODE* temp= &(p2->heap[top]);    // 啥意思？
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

    (p2->heap[top])=*temp;
    /* shift up the newly inserted node to its appropriate position to maintain max heap property*/
    shiftUp(p2,top);
}

/*function to extract the max priority patient from the priority queue*/
void extractmax(pq* p2)
{
    if(p2->num == 0){
        printf("The priority queue is empty\n");
        return;
    }
    
    printf("The name of patient is:%s\n",p2->heap[0].name);
    printf("The age of patient is:%d\n",p2->heap[0].age);
    printf("The address of patient is : %s\n",p2->heap[0].address);
    printf("---------------------------------------------------\n");
    /* shift the element at the end to first position*/
    p2->heap[0] = p2->heap[p2->num-1];
    /*reduce the size of heap and decrement the array index*/
    p2->num--;
    top--;
    /*shift down the node from the root to maintain heap property*/
    heapify(p2,top,0); // 当前排的数字的index是什么
    return;
}

/*Display function to display the patients in the queue with highest priority patient at the front*/
void display(pq* p2)
{   
    printf("\nPatients waiting in the queue are:\n");
    if(p2->num==-1){
        printf("There are no patients in the queue\n");
    }
    for(int i=0; i < p2->num;i++){
    
        printf("The name of patient is:%s\n",p2->heap[i].name);
        printf("The age of patient is:%d\n",p2->heap[i].age);
        printf("The address of patient is : %s\n",p2->heap[i].address);
        printf("---------------------------------------------------\n");

    }
}

/* Deallocate the memory*/
void freequeue(pq* p1){

    free(p1->heap);
    free(p1);
}

/*Main program*/
int main()
    {
        pq* p1=pq_init();
        if(p1==NULL){
            exit(1);
            }
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
                    insert(p1);
                    p1->num++;
                    break;
                /* Select 2 to delete the elements at the front of priority queue*/
                case 2:
                    printf("max priority patient\n");
                    extractmax(p1);
                    break;
                /* Select 3 To display the patients present in the priority queue*/
                case 3:
                    display(p1);
                    break;
                /* Select 4 to exit*/
                case 4:
                    printf("The program is being terminated\n");
                    break;
            }
        }
        while(option!=4);

    freequeue(p1);
    return 0;
}
