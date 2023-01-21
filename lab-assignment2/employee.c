/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>
/*structure to hold the details of an employee*/

typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;
/* Read the employee details using scanf*/
void readData(int n, employee_t* s) //what does it mean by employee_t* s s== array，每一个element定义
{ //s 是形参
    // Add your code here
    for(int i = 0; i < n; i++) {
        printf("\nEnter the employeeID, Name, designation and Department of Employee %d:", i + 1);
        scanf("%d%s%s%s", &s[i].empId, s[i].Name, s[i].Designation, s[i].Dept); //为什么只有一个指针, consider the next line here
        //不用空格，也不要/n读取
        //s是一个数组，是一个头指针
        // s数组中第n个数组访问
        // s数组的位置。 解引用 dereference 用&这个标志
        // s是个首元素的地址
    }
}
/* Function to print the employee details*/
void display(int n, employee_t * s)
{
    // Add your code here
    for(int i = 0; i < n; i++){
        printf("\nThe details of Employee %d:\n", i + 1);
        printf("empId: %d\n", s[i].empId);
        printf("name: %s\n", s[i].Name);
        printf("Designation: %s\n", s[i].Designation);
        printf("Dept: %s\n", s[i].Dept);//s相当于一个数组，s[i]取不同数组的位置，对每个元素进行取值
        printf("\n"); //不能保证一直换行

    }
    
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    // malloc
    
    printf("Enter the number of employees:");
    int n; // 先初始化变量，初始
    scanf("%d", &n); //读入变量scanf，往地址里面存，不是一个变量
    employee_t* q = (employee_t *) malloc(sizeof(employee_t) * n);//when to use malloc function, pointer, memory，创建一个n大小的employee_t
    //没有空格，指针类型的变量， n个大小为employee_t的变量
    readData(n, q);
    display(n, q);
    free(q);//需要释放变量，避免内存泄漏
    return 0;//一定要返回变量return 0，因为main函数得return 0

}

