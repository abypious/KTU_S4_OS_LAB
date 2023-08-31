 #include<stdio.h>
int allocation[10][10],max[10][10],need[10][10],n,m;
void readmatrix(int a[10][10]){
int i,j;
for(i=0;i<n;i++){
   for(j=0;j<m;j++){
	scanf("%d",&a[i][j]);
   }
}
}

void display(int b[10][10]){
int i,j;
for(i=0;i<n;i++){
   for(j=0;j<m;j++){
	printf("%d\t",b[i][j]);
   }
printf("\n");
}
}

void calculate(){
int i,j;
for(i=0;i<n;i++){
   for(j=0;j<m;j++){
	need[i][j]=max[i][j]-allocation[i][j];
   }
}
}
void banker(){
int avail[10],safeseq[10],finish[10],i,j,k,s,flag,ind=0;
for(i=0;i<n;i++)
finish[i]=0;
for(i=0;i<m;i++)
scanf("%d",&avail[i]);
for(s=0;s<n;s++){
	for(i=0;i<n;i++){
	   flag=0;
	   if(finish[i]==0){
              for(j=0;j<m;j++){
	         if(need[i][j]>avail[j]){
		    flag=1;
		    break;
	         }
	      }
	   if(flag==0){
	      finish[i]=1;
	      safeseq[ind]=i;
	      ind++;
	      for(k=0;k<m;k++){
	         avail[k]+=allocation[i][k];
	      }
	   }
	}
}
}
flag=0;
for(i=0;i<n;i++)
{
	if(finish[i]==0){
	   printf("deadlock");
	   flag=1;
	   break;
	}
}
if(flag==0)
{
	printf("following seq is safe\n");
	for(i=0;i<n-1;i++){
	printf("p%d",safeseq[i]);
}
	printf("p%d",safeseq[4]);
	printf("\n");
}
}

int main(){
printf("enter the number of process\n");
scanf("%d",&n);
printf("enter the number of resources\n");
scanf("%d",&m);
printf("allocation matrix\n");
readmatrix(allocation);
display(allocation);
printf("\nmax matrix\n");
readmatrix(max);
display(max);
printf("need matrix\n");
calculate();
display(need);
printf("enter available matrix");
banker();
return 0;
}
