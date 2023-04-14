// name: Minjia Tao
// email: tao.mi@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t chopstick[5]; // lock variable
int MAX_EAT_COUNT = 1; // maximum number of times a philosopher can eat
int hungry[5] = {1, 1, 1, 1, 1}; // initialize all philosophers as hungry

// Thread to be executed
void *philosopher(void *x)
{
    // Treat variable x as a pointer to an int and then extract the value into n
    int* a = (int*) x;
    int n = *a;

    /*-----Insert your code here----*/
    while (1) {
        if (hungry[n]) {
            printf("Philosopher %d is thinking.\n", n + 1);

            sem_wait(&chopstick[n]); // acquire left chopstick
            sem_wait(&chopstick[(n+1)%5]); // acquire right chopstick
            printf("Philosopher %d is eating using chopstick[%d] and chopstick[%d]\n", n + 1, n, (n+1)%5);

            usleep(rand() % 1000); // simulate eating for some random amount of time

            sem_post(&chopstick[n]); // release left chopstick
            sem_post(&chopstick[(n+1)%5]); // release right chopstick
            printf("Philosopher %d finished eating.\n", n + 1);

            usleep(rand() % 1000); // simulate thinking for some random amount of time

            hungry[n] = 0;
        }
    }
}

/*------------ Main Program ---------*/
int main() 
{
    int i, val[5];
    pthread_t threads[5];
    // initializing the semaphore (for chopsticks)
    for (i = 0; i < 5; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    // create and run the thread
    for (i = 0; i < 5; i++) {
        val[i] = i;
        pthread_create(&threads[i], NULL, (void *) philosopher, &val[i]);
    }

    // wait until all the threads are done
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroying the semaphore
    for (i = 0; i < 5; i++) {
        sem_destroy(&chopstick[i]);
    }
    return 0;
}
