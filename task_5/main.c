#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

const int bufSize = 2;
char buf[bufSize];

int rear = 0;
sem_t  empty;

pthread_mutex_t mutexD;
pthread_mutex_t mutexF;

pthread_t threads[3] ;


void printTable(){
    printf("Стол: %s и %s\n", (buf[0] == '\0' ? "empty" : (buf[0] == 't' ? "tobacco":"paper")),(buf[1] == '\0' ? "empty" : (buf[1] == 't' ? "tobacco":"paper")));
}
// Курильщик 1
void *TobaccoSmoker(void *param){
    int time_to_wait = 5 + abs(rand())%10;
    printf("Курильщик 1 ушёл за табаком на %d секунд\n",time_to_wait);
    sleep(time_to_wait);
    printf("Курильщик 1 пришёл с табаком\n");
    pthread_mutex_lock(&mutexD);
    sem_wait(&empty);
    buf[rear] = 't';
    rear = (rear+1)%bufSize;
    pthread_mutex_unlock(&mutexD) ;
    printTable();
    return NULL;
}
// Курильщик 2
void *PaperSmoker(void *param){
    int time_to_wait = 5 + abs(rand())%10;
    printf("Курильщик 2 ушёл за бумагой на %d секунд\n",time_to_wait);
    sleep(time_to_wait);
    printf("Курильщик 2 пришёл с бумагой\n");
    pthread_mutex_lock(&mutexD);
    sem_wait(&empty);
    buf[rear] = 'p';
    rear = (rear+1)%bufSize;
    pthread_mutex_unlock(&mutexD) ;
    printTable();
    return NULL;
}
// Курильщик 3
void *GeneralSmoker(void *param){
    int time_to_wait = 5 + abs(rand())%10;
    pthread_mutex_lock(&mutexF);

    printf("Курильщик 3 взял %s и %s и свернул сигарету\n", (buf[0] == '\0' ? "empty" : (buf[0] == 't' ? "tobacco":"paper")),(buf[1] == '\0' ? "empty" : (buf[1] == 't' ? "tobacco":"paper")));
    buf[0] = '\0';
    buf[1] = '\0';
    sem_post(&empty);
    sem_post(&empty);
    printf("Курильщик 3 будет курить %d секунд\n",time_to_wait);
    sleep(time_to_wait);
    printf("Курильщик 3 покурил\n");
    pthread_mutex_unlock(&mutexF);
    printTable();
    return NULL;
}
// посредник
void *GeneralThread(void *param){
    srand(time(NULL));
    pthread_mutex_init(&mutexD, NULL) ;
    pthread_mutex_init(&mutexF, NULL) ;
    for (int i = 0; i<bufSize; i++){
        buf[i] = '\0';
    }
    sem_init(&empty, 0, bufSize) ; //количество свободных ячеек равно bufSize
    int number = 5 + abs(rand())%20;
    printf("Будет %d перекуров\n", number);
    for (int i = 0; i<number; i++){
        printf("%d-ый перекур:\n", i+1);
        pthread_create(&threads[0],NULL,TobaccoSmoker, NULL) ;
        pthread_create(&threads[1],NULL,PaperSmoker, NULL) ;
        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);
        pthread_create(&threads[2],NULL, GeneralSmoker, NULL) ;
        pthread_join(threads[2], NULL);
    }
    return NULL;
}

int main() {
    pthread_t general_thread;
    pthread_create(&general_thread,NULL,GeneralThread, NULL) ;
    pthread_join(general_thread, NULL);
    return 0;
}
