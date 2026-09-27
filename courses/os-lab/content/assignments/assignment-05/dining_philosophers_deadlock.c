#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5
pthread_mutex_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    printf("Philosopher %d is thinking...\n", id);
    
    // Intentional Deadlock Vector: Every thread picks up the left fork first
    pthread_mutex_lock(&forks[id]);
    printf("Philosopher %d picked up left fork %d.\n", id, id);
    
    usleep(100000); // Artificial delay to ensure context switch before right fork
    
    // Attempt to pick up right fork
    pthread_mutex_lock(&forks[(id + 1) % N]);
    printf("Philosopher %d picked up right fork %d. Eating...\n", id, (id + 1) % N);
    
    pthread_mutex_unlock(&forks[(id + 1) % N]);
    pthread_mutex_unlock(&forks[id]);
    
    printf("Philosopher %d finished eating and put down forks.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];
    
    for (int i = 0; i < N; i++) pthread_mutex_init(&forks[i], NULL);
    
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }
    
    for (int i = 0; i < N; i++) pthread_join(threads[i], NULL);
    
    return 0;
}
