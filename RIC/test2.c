#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t cond;

int current = 1;
int N = 30;     // default value; will be overwritten by input
int turn = 1;   // 1 = odd thread, 2 = even thread, 3 = done thread

void* print_odd(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (!(current <= N && current % 2 == 1 && turn == 1)) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("%d\n", current);
        current++;
        if ((current - 1) % 10 == 0 || current > N) {
            turn = 3;  // Done thread
        } else {
            turn = 2;  // Even thread
        }

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);

        if (current > N) break;
    }
    return NULL;
}

void* print_even(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (!(current <= N && current % 2 == 0 && turn == 2)) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("%d\n", current);
        current++;
        if ((current - 1) % 10 == 0 || current > N) {
            turn = 3;  // Done thread
        } else {
            turn = 1;  // Odd thread
        }

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);

        if (current > N) break;
    }
    return NULL;
}

void* print_done(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (!((current - 1) % 10 == 0 && current > 1 && turn == 3)) {
            if (current > N) break;
            pthread_cond_wait(&cond, &lock);
        }

        if ((current - 1) % 10 == 0 && current > 1) {
            printf("done\n");
        }

        if (current > N) {
            pthread_mutex_unlock(&lock);
            break;
        }

        turn = (current % 2 == 1) ? 1 : 2;

        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    printf("Enter the number of digits to print: ");
    scanf("%d", &N);

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);
    pthread_create(&t3, NULL, print_done, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
