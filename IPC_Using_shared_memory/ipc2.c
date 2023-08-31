#include<stdio.h>
#include<sys/shm.h>

typedef struct process{
   char buff[100];
   int ser_up;
   int cli_up;
   int read_write;
}node;
node *new;

void main(){
int shmid;
int key=1437;
shmid = shmget(key,sizeof (node), IPC_CREAT | 0666);
new = (node *)shmat(shmid, NULL, 0);
new->read_write=0;
   while(1)
       while(new->cli_up==1){
       printf("message recieved from user 2 ");
       puts(new->buff);
       new->cli_up=0;
       new->ser_up=1;
       }
       printf("enter message from user 2");
       fgets(new->buff, 100, stdin);
       new->read_write=1;

while(new->read_write==1){
continue;
}
}
