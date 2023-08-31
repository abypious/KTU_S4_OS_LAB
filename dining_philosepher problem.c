#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<semaphore.h>
void eat();
sem_t s[10];
void* philo(void* n){
int ph=*(int *)n;
printf("philosepher %d come to eat\n",ph);
sem_wait(&s[ph]);
printf("philosepher %d got left fork\n",ph);
sem_wait(&s[(ph+1)%5]);
printf("philosepher %d got right fork\n",ph);
eat(ph);
sleep(2);
printf("philosepher %d release left fork\n",ph);
sem_post(&s[(ph+1)%5]);
printf("philosepher %d release right fork\n",ph);
sem_post(&s[ph]);
printf("philosepher %d finished\n",ph);
}
void eat(int ph){
printf("philosepher %d started to eat\n",ph);
}
int main(){
int i,p[5];
pthread_t  thread[5];
do{
for(i=0;i<5;i++){
sem_init(&s[i],0,1);
}
for(i=0;i<5;i++){
p[i]=i;
pthread_create(&thread[i],NULL,philo,(void*)&p[i]);
}
for(i=0;i<5;i++){
pthread_join(thread[i],NULL);
}

}while(1);
}
