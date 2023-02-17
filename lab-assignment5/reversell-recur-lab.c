// name: Minjia Tao
// email: tao.mi@northeastern.edu

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node_t;

typedef struct list{
    struct node* head;
}List;

/*-----creating the nodes----------*/
node_t* newNode(int num)
{
    node_t* newNode = (node_t*)malloc(sizeof(node_t));                  // when to use malloc
    if (newNode == NULL) {
        printf("memory is not allocated.\n");
        exit(1);
    }
    newNode->data = num;    // ->什么意思？
    newNode->next = NULL;
    return newNode;
}

/*---creating linked list----*/
List* init_LL(){
    List* l = (List*)malloc(sizeof(List));// how to initialize a linkedlist here
    if (l == NULL) {
        printf("Memory is not allocated.\n");
        exit(1);
    }
    l->head = NULL;
    return l;    
}

/*---Insert the nodes at the begining of the list---*/
void insertFirst(List* l, int data){
    node_t* nodeStart = newNode(data); 
    if (l->head == NULL) {                  // 为什么这里不用考虑l == NULL的情况
        l->head = nodeStart;
        return;
    }
    nodeStart->next = l->head;
    l->head = nodeStart;                         // set the new head; wrong when l->head = nodeStart->next
    return;                                      // 为什么要return
}

/*----display the output--------*/
void display(List* l)
{
    node_t* temp;
    temp = l->head;
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverse(List* l, node_t* ptr)
{
    //insert your code here
    // check if head of Linkedlist is NULL, is it necessary?
    if (l->head == NULL) {
        return;
    }
    // Base Case
        // if LinkedList is NULL, return
    if(ptr == NULL) {
        return;                     // return NULL != void return
    }
        // if reach the end of the linkedlist, return
    if (ptr->next == NULL) {
        l->head = ptr;              // !!! let the list -> head equals to the end of the listnode
                                    // same as ListNode head = reverse(node->next)
        return;                     // 表示函数已经执行终止了    
    }
    
    // Recursive 
        // dive first before rearrange: first recrusive then manipulation
    reverse(l, ptr->next);          // link the new head and the remain list
    ptr->next->next = ptr;
    ptr->next = NULL;
}
    // 这个不用写因为ptr是下面引入的参数
    // node_t* ptr = l->head;
    // node_t* next = ptr->next;
    // 修改头节点 == NULL
    // recursion 1->       2      ->3
    //          ptr    ptr->next ptr->next->next
    //           3->       1      -> 2
    //   ptr->next->next   ptr      ptr->next
                       // head         
        // make the next node point to the previous node
        // head加到尾巴上去，先递归head后面的
    

/*----Free the nodes-----*/
void freenode(List* l){
  node_t* temp;
    while(l->head)
    {
        temp = l->head->next;
        free(l->head);
        l->head = temp;
    }  
    
}

/*-----Main program--------------*/
int main()
{
    List* list=init_LL();
    // LinkedList as 11->22->33->44
    insertFirst(list,44);
    insertFirst(list,33);
    insertFirst(list,22);
    insertFirst(list,11);
    display(list);
    reverse(list,list->head);
    display(list);
    
    freenode(list);
    free(list);
    return 0;
}
