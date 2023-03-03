// name: Minjia Tao
// email: tao.mi@northeastern.edu

// Hash table with doubly linked list for chaining/
#include <stdio.h>
#include <stdlib.h> 

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; 

// node struct
struct node {

    // Add your code here
    int key;
    int value;
    struct node* next;
    struct node* prev;         // 注意initilaze next和prev?
                                // 哈希表整体实现还是用的单链表，只有chain那部分用的是双向链表，
};

// bucket struct
struct bucket{

    // Add your code here
    struct node* head;
    struct node* tail;
    int count; // count node in a bucket

};

// create a new node
struct node* createNode(int key, int value){

    // Add your code here
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//  hash function with %
int hashFunction(int key){
    return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value){
    int hashIndex = hashFunction(key);
    
    // Add your code here
    struct node* newNode = createNode(key, value);
    
    // when node is empty
    if (hashTable[hashIndex].count == 0) {
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].tail = newNode;
    }

    // when node has a key
    else { //需要对prev和next都要操作吗？
        hashTable[hashIndex].count++;
        hashTable[hashIndex].tail->next = newNode;
        newNode->prev = hashTable[hashIndex].tail;
        hashTable[hashIndex].tail = newNode; // 移动tail指针
    }
}

// remove a key
void remove_key(int key){
    int hashIndex = hashFunction(key);

    // Add your code here
    struct node* removeNode = hashTable[hashIndex].head; // 为什么要用.head,不可以直接么，有点疑惑

    if (removeNode == NULL) {
        printf("\nkey %d not found in bucket %d\n", key, hashIndex);
    }
    while (removeNode != NULL) {
        if (removeNode->key == key) {
            // head
            if (removeNode == hashTable[hashIndex].head) {
                hashTable[hashIndex].head = removeNode->next;
                if (hashTable[hashIndex].head != NULL) { // 可能不是chain
                    hashTable[hashIndex].head->prev = NULL;
                }

            } else if (removeNode == hashTable[hashIndex].tail) {
                hashTable[hashIndex].tail = removeNode->prev;
                hashTable[hashIndex].tail->next = NULL; // 这里需要判断是否为NULL吗？
            } else {
                removeNode->prev->next = removeNode->next;
                removeNode->next->prev = removeNode->prev;
            }
            hashTable[hashIndex].count--;
            free(removeNode);
            printf("\n key %d remove from bucket %d\n",key, hashIndex);
            return;
        }
        removeNode = removeNode->next; //为什么？
    }
    printf("\nkey %d not found in bucket %d\n", key, hashIndex); // 为什么这里还要加return
    return;
}

// search a value using a key
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;

    // Add your code here
    if(node == NULL){
        printf("\nno key found. \n");
        return;
    }
    while (node != NULL)
    {
        if (node->key == key){
            printf("\nkey = [ %d ], value = [ %d ].\n", node->key, node->value);
            return;
        }
        node = node->next;
    }
    printf("\nno key found. \n");
    return;
}

void display(){
    struct node* iterator;

    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

int main(){
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    add(0, 1);
    add(1, 10);
    add(11, 12);
    add(21, 14);
    add(31, 16);
    add(5, 18);
    add(7, 19);

    display();

    remove_key(31);
    remove_key(11);

    display();

    search(11);
    search(1);
}
