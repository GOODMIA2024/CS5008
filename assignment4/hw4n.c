// name: Minjia Tao
// email: tao.mi@northeastern.edu

// selection sort
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 50
#define RAND_RANGE 100

void print_array(int* arr, int num){
  //print out source array in rows of num elements
  for (int i = 0; i < ((LIMIT/num)+1); i++) {
    for (int j = 0; j<num; j++) {
      if (i*num + j < LIMIT) {
	      printf("%.2d ",arr[i*num+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

void generate_num(int* arr){
  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize array with random numbers from 0..RAND_RANGE
  for (int i = 0; i < LIMIT; i++) {
    arr[i] = rand() % RAND_RANGE;
  }
}

void selection_sort_2arr(int* source, int* dest, bool* valid) // valid is an array
{
  int smallest;      // current smallest element
  int smallestIndex;  // initialize the index for the smallest number
  for (int i = 0; i < LIMIT; i++) {
//     smallestIndex = i;
//     for (int j = i + 1; j < LIMIT; j++) {
//       if (source[j] < source[smallestIndex]) {
//         smallestIndex = j;
//       }
//       if (smallestIndex != i) {
//         int temp = source[smallest];
//         source[smallest] = source[i];
//         source[i] = temp;
//       }
//     }
//   }
// }
    // INSERT YOUR CODE HERE

    // cannot initialize the smallest as source[i] since it will ask for more restriction
        //     // for(int j = 0; j < LIMIT; j++) { // question: consider for the duplicates?
    //     //   if (valid[j]) {
    //     //     smallest = j; //  这边不对
    //     //     break;
    //     //   }
    //     // }
    
    smallest = RAND_RANGE + 1; // the upper bound of all the random numbers，找到全部数组中的最大值

    // find the smallest number and its index in the source array
    for(int j = 0; j < LIMIT; j++) { // question: consider for the duplicates?
      if (valid[j] && source[j] < smallest) { // valid[j] == true
        smallest = source[j];
        smallestIndex = j;
      }
    }
    
    //put the smallest number in the dest and marked it as false in the valid array
    dest[i] = smallest;
    valid[smallestIndex] = false; 

    // question: how to understand? // 为什么要加入valid？
  }
}


void selection_sort_1arr(int* source)
{
  int smallest;      // current smallest element
  int temp;          // temporary for swap
  int smallestIndex; // index of the smallest element

  for (int i = 0; i < LIMIT; i++) {

  // INSERT YOUR CODE HERE
    smallest = source[i];
    smallestIndex = i;

    // find the smallest element in the unsorted portion of the array
    for (int j = i + 1; j < LIMIT; j++) {
      if (source[j] < smallest) {
        smallest = source[j];
        smallestIndex = j;
      }
    }

    // move the smaller one to the front by swapping
    if (smallestIndex != i) {
      temp = source[smallestIndex];
      source[smallestIndex] = source[i];
      source[i] = temp;
    }
  }
}


int main(){

  int source[LIMIT]; // array to hold input data values
  int dest[LIMIT];   // array to hold sorted data values
                     // use dest only if you are using two arrays
  bool valid[LIMIT]; // array that indicates which input values are valid

  //initialize valid array - at begining the full array is valid
  for (int i = 0; i < LIMIT; i++) {
    valid[i] = true;
  }
 
  //initialize source array with random numbers from 0..RAND_RANGE
  generate_num(source);

  //print out source array in rows of 20 elements
  printf("Source array:\n");
  print_array(source, 20);

  //Selection sort with 2 array
  //print out sorted array by 2 array in rows of 10
  selection_sort_2arr(source, dest, valid);
  printf("Sorted array by 2 array:\n");
  print_array(dest, 10);

  //Selection sort with 1 array
  //print out sorted array by 1 array in rows of 10
  selection_sort_1arr(source);
  printf("Sorted array by 1 array:\n");
  print_array(source, 10);
 
  return 0;
}
