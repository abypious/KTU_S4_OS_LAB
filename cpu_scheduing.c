#include<stdio.h>
typedef struct{
int id,ct,at,bt,wt,tat,pt,c,rt;
}process;

process temp,p[10];
int n;
int total=0;
float twt=0,ttat=0;

void fcfs()
{
int i,j;
printf("\nFCFS\n");
printf("enter the number of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
        p[i].id=i;
        printf("enter the arrival time and burst time\n");
        scanf("%d%d",&p[i].at,&p[i].bt);
}
        for(i=0;i<n;i++)
        {
        for(j=0;j<n-i-1;j++)
        {
        if(p[j].at>p[j+1].at)
        {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
        }
        }
        }
total=0;
for(i=0;i<n;i++)
{
        while(total<p[i].at)
        {
        total++;
        }
p[i].ct=total+p[i].bt;
total=p[i].ct;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;

}
printf("pid | arr | burst | comp | turn | wait\n");
for(i=0;i<n;i++)
{
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        ttat+=p[i].tat;
        twt+=p[i].wt;

}
printf("avg wait time %f , avg turn %f",(twt/n),(ttat/n));


}
void sjf()
{
printf("\n\nSJF\n");
int i,j,sh;
printf("enter the number of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
        p[i].id=i;
        printf("enter the arrival time and burst time\n");
        scanf("%d%d",&p[i].at,&p[i].bt);
}
        for(i=0;i<n;i++)

        for(j=0;j<n-i-1;i++)
        {
        if(p[j].at>p[j+1].at)
        {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
  }
        }

total=0;
sh=0;
for(i=0;i<n;i++)
p[i].c=1;
for(i=0;i<n;i++)
{
        sh=i;
        while(total<p[i].at)
        {
        total++;
        }
for(j=i;j<n;j++)

if(p[j].at<=total&&p[sh].bt>p[j].bt&&p[sh].c==1)
{
sh=j;
}
temp=p[sh];
p[sh]=p[i];
p[i]=temp;
p[i].c=0;

p[i].ct=total+p[i].bt;
total=p[i].ct;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;

}
ttat=0;
twt=0;
printf("pid | arr | burst | comp | turn | wait\n");
for(i=0;i<n;i++)
{
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        ttat+=p[i].tat;
        twt+=p[i].wt;

}
printf("avg wait time %f , avg turn %f",(twt/n),(ttat/n));
}
void priority()
{
printf("\n\nPRIORITY\n");
int i,j,sh;
printf("enter the number of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
        p[i].id=i;
        printf("enter the arrival time and burst time and priority\n");
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
}
        for(i=0;i<n;i++)

        for(j=0;j<n-i-1;i++)
        {
        if(p[j].at>p[j+1].at)
        {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
        }
        }

total=0;
sh=0;
for(i=0;i<n;i++)
p[i].c=1;
for(i=0;i<n;i++)
{
        sh=i;
        while(total<p[i].at)
        {
        total++;

        }
for(j=i;j<n;j++)

if(p[j].at<=total&&p[sh].pt>p[j].pt&&p[sh].c==1)
{
sh=j;
}
temp=p[sh];
p[sh]=p[i];
p[i]=temp;
p[i].c=0;



p[i].ct=total+p[i].bt;
total=p[i].ct;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;

}
ttat=0;
twt=0;
printf("pid | arr | burst |priority| comp | turn | wait\n");
for(i=0;i<n;i++)
{
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
        ttat+=p[i].tat;
        twt+=p[i].wt;

}
printf("avg wait time %f , avg turn %f",(twt/n),(ttat/n));

}

int rr() {
	printf("\n\nROUND ROBIN\n");
    int i,j,rp,qu;
    printf("enter the number of process : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("enter the at bt of %d \n", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }
    printf("enter the time slice :\n");
    scanf("%d", &qu);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    rp = n;
    total = 0;
    while (rp > 0) {
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                printf("-->%d ", p[i].id);
                if (p[i].rt > qu) {
                    total += qu;
                    p[i].rt -= qu;
                } else {
                    total += p[i].rt;
                    p[i].rt = 0;
                    rp--;
                    p[i].wt = total - p[i].at - p[i].bt;
                    p[i].tat = p[i].wt + p[i].bt;
                }
            }
        }
    }
    printf("\nid\tat\tbt\tct\twt\ttt\n");
    ttat = 0;
    twt = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].at + p[i].tat, p[i].wt, p[i].tat);
        ttat += p[i].tat;
        twt += p[i].wt;
    }
    printf("avg twt=%f\n", twt / n);
    printf("avg ttt=%f\n", ttat / n);
    return 0;
}

int main()
{
        fcfs();
        sjf();
        priority();
	rr();
}
