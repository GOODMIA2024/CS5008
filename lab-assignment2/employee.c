// name - Minjia Tao
// email - tao.mi@northeastern.edu

/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>          // stardard input/output library
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
void readData(int n, employee_t* s) {
    // Add your code here
    for(int i = 0; i < n; i++) {
        printf("\nEnter the employeeID, Name, designation and Department of Employee %d:", i + 1);
        scanf("%d%s%s%s", &s[i].empId, s[i].Name, s[i].Designation, s[i].Dept);  // only the 1st element should use the pointer
    }
}
/* Function to print the employee details*/
void display(int n, employee_t * s) {
    // Add your code here
    for(int i = 0; i < n; i++){
        printf("\nThe details of Employee %d:\n", i + 1);
        printf("empId: %d\n", s[i].empId);
        printf("name: %s\n", s[i].Name);
        printf("Designation: %s\n", s[i].Designation);
        printf("Dept: %s\n", s[i].Dept);
        printf("\n"); 
    }
}

/*----------Main Program--------*/
int main()

{
    // Main Function to print the employee details
    // Add your code here
    // malloc
    
    printf("Enter the number of employees:");
    int n; 
    scanf("%d", &n);                    // read numbers
    employee_t* q = (employee_t*) malloc(sizeof(employee_t) * n); 
    // allocate n(sizeof) continguous blocks of memory of type employee_t for queue q;
    // making q the pointer, make employee_t stored in q.
    if (q != NULL) {                         //special situation when q == NULL
        readData(n, q);
        display(n, q);
        free(q);                            // free memory for not leaking
    }
    return 0;                               // return int - 0 
}

