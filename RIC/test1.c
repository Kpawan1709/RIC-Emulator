#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int turn = 0; // 0 = Monday, 1 = Tuesday, 2 = Wednesday

void* print_monday(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (turn != 0)
            pthread_cond_wait(&cond, &lock);
        
        printf("Monday\n");
        sleep(2);
        turn = 1; // Next: Tuesday
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* print_tuesday(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (turn != 1)
            pthread_cond_wait(&cond, &lock);
        
        printf("Tuesday\n");
        sleep(2);
        turn = 2; // Next: Wednesday
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* print_wednesday(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (turn != 2)
            pthread_cond_wait(&cond, &lock);
        
        printf("Wednesday\n");
        sleep(2);
        turn = 0; // Next: Monday again
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, print_monday, NULL);
    pthread_create(&t2, NULL, print_tuesday, NULL);
    pthread_create(&t3, NULL, print_wednesday, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}

