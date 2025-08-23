#include<stdio.h>
#include<stdbool.h>
#define MAX_PROCESSES 10
typedef struct
{
	int pid;
	int burstTime;
	int arrivalTime;
	int priority;
	int waitingTime;
	int turnaroundTime;
	int remainingTime;
}process;

void findWaitingTimeFCFS(process processes[],int n);
void findWaitingTimeSJF(process processes[],int n);
void findWaitingTimeRoundRobin(process processes[],int n,int quantum);
void findWaitingTimepriority(process processes[],int n);
void calculateTurnaroundTime(process processes[],int n);
void printResults(process processes[],int n);

int main()
{
	int n,quantum;
	process processes[MAX_PROCESSES];
	printf("Enter the Number of processes:");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		printf("Enter Burst Time for process %d:",i+1);
		scanf("%d",&processes[i].burstTime);
		
		printf("Enter Arrival Time for process %d:",i+1);
		scanf("%d",&processes[i].arrivalTime);
		
		printf("Enter Priority for process %d:",i+1);
		scanf("%d",&processes[i].priority);
		processes[i].pid=i+1;
		processes[i].remainingTime=processes[i].burstTime;
	}
	
	printf("\nFirst-Come,First-Served(FCFS) Scheduling:\n");
	findWaitingTimeFCFS(processes,n);
	calculateTurnaroundTime(processes,n);
	printResults(processes,n);
	
	printf("\nShortest Job First(SJF) Scheduling:\n");
	findWaitingTimeSJF(processes,n);
	calculateTurnaroundTime(processes,n);
	printResults(processes,n);
	
	printf("Round Robin Scheduling:\n");
	printf("Enter Time Quantum:");
	scanf("%d",&quantum);
	findWaitingTimeRoundRobin(processes,n,quantum);
	calculateTurnaroundTime(processes,n);
	printResults(processes,n);
	
	printf("\nPriority Scheduling:\n");
	findWaitingTimepriority(processes,n);
	calculateTurnaroundTime(processes,n);
	printResults(processes,n);
	return 0;
}
void findWaitingTimeFCFS(process processes[],int n)
{
	processes[0].waitingTime=0;
	for(int i=1; i<n; i++)
	{
		processes[i].waitingTime=processes[i-1].waitingTime+processes[i-1].burstTime;
	}
}

void findWaitingTimeSJF(process processes[],int n)
{
	int completed=0,currentTime=0;
	bool isCompleted[MAX_PROCESSES]={false};
	while(completed!=n)
	{
		int shortest=-1;
		for(int i=0; i<n; i++)
		{
			if(!isCompleted[i]&&(shortest==-1||processes[i].burstTime<processes[shortest].burstTime))
			{
				shortest=i;
			}
		}
		currentTime+=processes[shortest].burstTime;
		processes[shortest].waitingTime=currentTime-processes[shortest].arrivalTime-processes[shortest].burstTime;
		isCompleted[shortest]=true;
		completed++;
	}
}

void findWaitingTimeRoundRobin(process processes[],int n,int quantum)
{
	int currentTime=0;
	int remainingProcesses=n;
	while(remainingProcesses>0)
	{
		for(int i=0; i<n; i++)
		{
			if(processes[i].remainingTime>0)
			{
				if(processes[i].remainingTime>quantum)
				{
					currentTime+=quantum;
					processes[i].remainingTime-=quantum;
				}else
				{
					currentTime+=processes[i].remainingTime;
					processes[i].waitingTime=currentTime-processes[i].burstTime;
					processes[i].remainingTime=0;
					remainingProcesses--;
				}
			}
		}
	}
}

void findWaitingTimepriority(process processes[],int n)
{
	int completed=0,currentTime=0;
	bool isCompleted[MAX_PROCESSES]={false};
	while(completed!=n)
	{
		int highestpriority=-1;
		for(int i=0; i<n; i++)
		{
			if(!isCompleted[i]&&(highestpriority==-1||processes[i].priority<processes[highestpriority].priority))
			{
				highestpriority=i;
			}
		}
		currentTime+=processes[highestpriority].burstTime;
		processes[highestpriority].waitingTime=currentTime-processes[highestpriority].arrivalTime-processes[highestpriority].burstTime;
		isCompleted[highestpriority]=true;
		completed++;
	}
}

void calculateTurnaroundTime(process processes[],int n)
{
	for(int i=0; i<n; i++)
	{
		processes[i].turnaroundTime=processes[i].burstTime+processes[i].waitingTime;
	}
}

void printResults(process processes[],int n)
{
	printf("\nprocess\tburst Time\tArrival Time\tpriority\tWaiting Time\tTurnaround Time\n");
	for(int i=0; i<n; i++)
	{
		printf("p%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].pid,processes[i].burstTime,processes[i].arrivalTime,processes[i].priority,processes[i].waitingTime,processes[i].turnaroundTime);
	}
}
