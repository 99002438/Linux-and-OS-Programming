#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>


sem_t write;
pthread_mutex_t mutex;
int count = 1;
int numreader = 0;

void *writer(void *writerno)
{   
    sem_wait(&write);
    count = count*2;
    printf("Writer %d modified cnt to %d\n",(*((int *)writerno)),count);
    sem_post(&write);

}
void *reader(void *readerno)
{   
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) {
        sem_wait(&write); // If this id the first reader, then it will block the writer
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: read cnt as %d\n",*((int *)readerno),count);

    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) {
	sem_post(&write); // If this is the last reader, it will wake up the writer.
    }
    pthread_mutex_unlock(&mutex);
}
int main()
{   

    pthread_t r[10],w[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&write,0,1);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; //Just used for numbering the producer and consumer

    for(int i = 0; i < 10; ++i) {
        pthread_create(&r[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(int i = 0; i < 5; ++i) {
        pthread_create(&w[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 10; ++i) {
        pthread_join(r[i], NULL);
    }
    for(int i = 0; i < 5; ++i) {
        pthread_join(w[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&write);

    return 0;
    
}


