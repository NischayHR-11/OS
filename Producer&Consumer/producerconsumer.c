#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

# define buffersize 3

int buffer[buffersize];

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int in=0;
int out=0;

void * consumer( void *cno){

    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    int n=buffer[out];
    printf("CONSUMER %d : CONSUMED %d AT %d",*((int *)cno),n,out);
    out=(out+1)%buffersize;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    
}

void * producer( void *pno){

    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[in]=rand()%100;
    printf("PRODUCER %d : PRODUCED %d AT %d",*((int *)pno),buffer[in],in);
    in=(in+1)%buffersize;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    
}

int main(){

    sem_init(&full,0,0);
    sem_init(&empty,0,buffersize);
    pthread_mutex_init(&mutex,NULL);

    pthread_t p[3],c[3];
    int a[]={1,2,3};

    for(int i=0;i<buffersize;i++){

        pthread_create(&p[i],NULL,producer,(void *)&a[i]);
    }

    for(int i=0;i<buffersize;i++){

        pthread_create(&c[i],NULL,consumer,(void *)&a[i]);
    }

    for(int i=0;i<buffersize;i++){

        pthread_join(p[i],NULL);
    }

    for(int i=0;i<buffersize;i++){

        pthread_join(c[i],NULL);
    }

    sem_destroy(&full);
    sem_destroy(&empty);
    pthread_mutex_destroy(&mutex);
}