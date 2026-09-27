#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex;
sem_t empty, full;

void* producer(void* arg) {
    // DEADLOCK TRIGGER: Holding the mutex BEFORE waiting on the semaphore.
    // If the buffer is full, the producer sleeps holding the mutex. 
    // The consumer needs the mutex to consume, resulting in a permanent freeze.
    pthread_mutex_lock(&mutex);
    sem_wait(&empty); 
    
    printf("Producer produced an item.\n");
    
    sem_post(&full);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* consumer(void* arg) {
    // Correct Order: Wait on semaphore, then lock mutex.
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    
    printf("Consumer consumed an item.\n");
    
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t prod, cons;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, 1); // Buffer size 1
    sem_init(&full, 0, 0);

    // Initial fill to trigger the deadlock condition on the next producer cycle
    sem_wait(&empty);
    sem_post(&full); 

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
