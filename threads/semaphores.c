/*
 * For compiling this code use "gcc -o semaphores semaphores.c -pthread"
 */
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NR_LOOP 10000

static int counter = 0;
sem_t sem1;

static void *thread1_routine(void *arg){

    for(int i = 0; i < NR_LOOP; i++){
        sem_wait(&sem1);
        counter++;
        sem_post(&sem1);
    }

    return 0;
}

static void *thread2_routine(void *arg){

    for(int i = 0; i < NR_LOOP; i++){
        sem_wait(&sem1);
        counter--;
        sem_post(&sem1);
    }

    return 0;
}

int main(void){

    pthread_t thread1, thread2;
    
    sem_init(&sem1, 0, 1);
    pthread_create(&thread1, NULL, *thread1_routine, NULL);
    pthread_create(&thread2, NULL, *thread2_routine, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Counter value: %d\n", counter);

    return 0;
}
