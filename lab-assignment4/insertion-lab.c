// name: Minjia Tao
// email: tao.mi@northeastern.edu
// To perform insertion sort of integers stored in a file and display the output and store it in another file.


#include <stdio.h>
#include<stdlib.h>


void insertion_sort(int* arr, int* sort, int count)
{
    for(int i = 1; i < count; i++) {
        sort[i] = arr[i];
        int j = i - 1;
        while (j > 0 && sort[j - 1] > sort[j]) {
            int temp = sort[j];
            sort[j] = sort[j-1];
            sort[j-1] = temp;
            j--; //这一步很关键，保证index一直往前移动找到合适的位置。insertion sort 从头开始放置 valid element， 
                 //bubble sort从尾开始放置每一次valid element
        }
    }
    //return 1;     // Question: need a return statement for the function
}

int main()
{
    FILE *fp;
    int arr[10],temp;
    int count = 0, i, j;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp = fopen("Input1.txt","r");
    if (fp == NULL) {
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    // insert your code here
    // read the file into an array
    while (fscanf(fp, "%d", &arr[count]) == 1) { // 刚开始要使用count作为初始值，count from the numbers in the file 
            //fscanf returns 1 if reads the number successfully 
        count++;
    }
            // 1. one way to read the numbers into array
                // for(i = 0; i < 10; i++){
                //     fscanf(fp, "%d", &arr[i]); // also work
                // }

            // 2. count = sizeof(arr) / sizeof(int);

    fclose(fp); // close the fole after open it

    int sortArr[count]; // initialize the sorrted array with proper size

    insertion_sort(arr, sortArr, count); // perform insertion sort

    // create a new file for showing the sorted array
    FILE* sorted_file = fopen("sorted_file", "w");
    if (sorted_file == NULL) {
        printf("\n Cannot open the sorted file \n");
        return 1;
    }

    for (int i = 0; i < count; i++)
        fprintf(sorted_file, "%d\n", sortArr[i]);
    printf("\n");
    fclose(sorted_file);

    return 0 ;
}

