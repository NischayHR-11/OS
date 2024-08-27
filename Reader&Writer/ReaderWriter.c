#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

# define buffersize 3

sem_t wr;
pthread_mutex_t mutex;
int cnt=1;
int readercnt=0;

void * writer( void *wno){

    sem_wait(&wr);

    cnt=cnt*2;

    printf("WRITER %d : MODIFIED COUNT TO %d\n",*((int *)wno),cnt);
    sem_post(&wr);
}

void * reader( void *rno){

    pthread_mutex_lock(&mutex);

    readercnt++;

    if(readercnt==1){

        sem_wait(&wr);
    }

    pthread_mutex_unlock(&mutex);

    printf("READER %d : READ THE CNT HAS %d",*((int *)rno),cnt);

    pthread_mutex_lock(&mutex);

    readercnt--;

    if(readercnt==0){

        sem_post(&wr);
    }

    pthread_mutex_unlock(&mutex);
}

int main(){

    sem_init(&wr,0,1);
    pthread_mutex_init(&mutex,NULL);

    pthread_t r[3],w[3];

    int a[]={1,2,3};

        for(int i=0;i<buffersize;i++){

        pthread_create(&w[i],NULL,writer,(void *)&a[i]);
    }

    for(int i=0;i<buffersize;i++){

        pthread_create(&r[i],NULL,reader,(void *)&a[i]);
    }

    for(int i=0;i<buffersize;i++){

        pthread_join(w[i],NULL);
    }

    for(int i=0;i<buffersize;i++){

        pthread_join(r[i],NULL);
    }

    sem_destroy(&wr);
    pthread_mutex_destroy(&mutex);
}

