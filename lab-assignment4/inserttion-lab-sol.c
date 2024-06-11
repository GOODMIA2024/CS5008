//Insertion sort of numbers stored in a file
#include<stdio.h>
#include<stdlib.h>
int main()
{
    
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;/*count has the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input1.txt","r");

    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    printf("contents of file are:");

    while((fscanf(fp,"%d",&arr[count]))==1){
        printf("%d\t",arr[count]);
        count++;
    }

    /* INSERTION SORT */
    for (i = 1; i < count; i++)
    {
        temp = arr[i];
        j = i - 1;
      
    /* Move elements of arr[0..i-1], that are
     greater than temp value, to one position ahead of their current position */
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
             j--;
        }
        arr[j + 1] = temp;
    }
    fp=fopen("sorted.txt","w");
    printf("The output is\n");

    for(i=0;i<count;i++){
        fprintf(fp,"%d\n",arr[i]);
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
