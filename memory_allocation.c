#include<stdio.h>
#include<stdlib.h>
int ps[20],bs[20],alloc[20],was[20];
int i,j,p,b,bi,wi;

void ff(){
for(i=0;i<p;i++){
   for(j=0;j<b;j++){
   	if(ps[i]<=bs[j]){
	alloc[i]=j;
	bs[j]=bs[j]-ps[i];
	was[i]=bs[j];
	break;
	}
   }
}
}

void best(){
for(i=0;i<p;i++){
   bi=-1;
   for(j=0;j<b;j++){
        if(ps[i]<=bs[j]){
	   if(bi==-1){
		bi=j;}
	   if(bs[bi]>bs[j]){
		bi=j;}
        }
   }
   alloc[i]=bi;
   if(alloc[i]!=-1){
   bs[bi]=bs[bi]-ps[i];
   was[i]=bs[bi];}
}
}

void worst(){
for(i=0;i<p;i++){
   wi=-1;
   for(j=0;j<b;j++){
        if(ps[i]<=bs[j]){
           if(wi==-1){
                wi=j;}
           if(bs[wi]<bs[j]){
                wi=j;}
        }
   }
   alloc[i]=wi;
   if(alloc[i]!=-1){
   bs[wi]=bs[wi]-ps[i];
   was[i]=bs[wi];}
}
}

void display(){
printf("the allocation is as follows : \n");
printf("process no.\tprocess size\tallocated block\tmemmory wastage\n");
for(i=0;i<p;i++){
   printf("%d\t\t%d\t\t",i+1,ps[i]);
      if(alloc[i]==-1){
      printf("not allocated\t");
      }
   else{
   printf("%d\t\t",alloc[i]+1);}
    printf("%d\n",was[i]);
   }

}

void options(){
int ch;
printf("1 for first fit\n2 for best fit\n3 for worst fit\nenter your choice :\n");
scanf("%d",&ch);
switch(ch){
   case 1:ff();
	 display();
	 break;
   case 2:best();
         display();
         break;
   case 3:worst();
         display();
         break;
   default:exit(0);
	   break;
   }
}


int main(){
printf("enter the number of process :\n");
scanf("%d",&p);
printf("enter the number of block :\n");
scanf("%d",&b);

printf("enter the size of each process :\n");
for(i=0;i<p;i++){
scanf("%d",&ps[i]);
}

printf("enter the size of each block :\n");
for(j=0;j<b;j++){
scanf("%d",&bs[j]);
}

for(i=0;i<p;i++){
alloc[i]=-1;
}
for(i=0;i<p;i++){
was[i]=0;
}

options();
}

