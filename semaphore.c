#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t mutex_1, mutex_2;
  
void* thread_1(void* arg)
{
    //wait
    sem_wait(&mutex_1);
    printf("\n Entered thread_1 ..\n");
  
    //critical section
    sleep(4);
      
    //signal
    printf("\n Exiting thread_1...\n");
    sem_post(&mutex_1);
}

void* thread_2(void* arg)
{
    //wait
    sem_wait(&mutex_1);
    printf("\n Entered thread_2 ..\n");
  
    //critical section
    sleep(4);
      
    //signal
    printf("\n Exiting thread_2 ..\n");
    sem_post(&mutex_1);
}

void* thread_3(void* arg)
{
    //wait
    sem_wait(&mutex_2);
    printf("\n Entered thread_3 ..\n");
  
    //critical section
    //sleep(4);
      
    //signal
    printf("\n Exiting thread_3 ..\n");
    sem_post(&mutex_2);
}
 
  
int main()
{
    sem_init(&mutex_1, 0, 2);
    sem_init(&mutex_2, 0, 1);
    pthread_t t1, t2, t3;
    pthread_create(&t1,NULL,thread_1,NULL);
    sleep(1);
    pthread_create(&t2,NULL,thread_2,NULL);
    sleep(1);
    pthread_create(&t3,NULL,thread_3,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    sem_destroy(&mutex_1);
    sem_destroy(&mutex_2);
    return 0;
}
