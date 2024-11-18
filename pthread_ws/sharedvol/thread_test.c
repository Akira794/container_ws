#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
void *thread_function1( void *ptr );
void *thread_function2( void *ptr );
 
pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;
 
useconds_t tick1 = 200000;
useconds_t tick2 = 2000000;
 
int main(void){
     pthread_t thread1, thread2;
 
     pthread_mutex_init(&mutex, NULL);
 
     pthread_create( &thread1, NULL, thread_function1, (void *) &tick1);
     pthread_create( &thread2, NULL, thread_function2, (void *) &tick2);
 
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);
 
     pthread_mutex_destroy(&mutex);
 
     return 0;
}
 
void *thread_function1(void *ptr){
    useconds_t tick = *( int * )ptr;
 
    while(1){
        pthread_mutex_lock(&mutex);
 
        printf("function1 %d\n",count++);
        pthread_mutex_unlock(&mutex);
        usleep(tick);
    }
}
 
void *thread_function2(void *ptr){
    useconds_t tick = *( int * )ptr;
 
    while(1){
        pthread_mutex_lock(&mutex);
 
        printf("function2 %d\n",count++);
        pthread_mutex_unlock(&mutex);
        usleep(tick);
    }
}
