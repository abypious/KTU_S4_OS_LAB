#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<semaphore.h>
void main(){
int size=5;
int item=0;
sem_t *empty=sem_open("PKeee",O_CREAT,0666,5);
sem_t *full=sem_open("PSeee",O_CREAT,0666,0);
sem_t *mutex=sem_open("PCeee",O_CREAT,0666,1);
if(empty==NULL||full==NULL||mutex==NULL){
printf("error");
exit(0);
}
while(1){
   sem_wait(empty);
   sem_wait(mutex);
   printf("produced %d\n",item);
   item=(item+1)%size;
   sem_post(mutex);
   sem_post(full);
sleep(1);
   }
}
