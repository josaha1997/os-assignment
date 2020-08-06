//1830
//FCFS algorithm for Memory Management(OS)

#include<stdio.h>
#include<stdlib.h>
int memory=0,allocated=1,start=2,end=3;

//FCFS logic
int fcfs(int total_memory,int *process[4],int no_of_processes)
{
	int i,available_memory=total_memory;
	//Checking available memory for each process
	for(i=0;i<no_of_processes;i++)
	{	printf("\nProcess %d(%d %d %d)\t",i+1,process[i][memory],process[i][start],process[i][end]);
			//Checking if a process fits into available memory
			if(process[i][memory]<=available_memory)
			{
				process[i][start]=total_memory-available_memory;
				process[i][end]=process[i][start]+process[i][memory]-1;
				available_memory-=process[i][memory];
				process[i][allocated]=1;
				
			}
	}
	return available_memory;	
}
 
//Checking for negative input
void check_error(int value)
{
	if(value<0)
	{
		printf("\nSorry! This value cannot be negative\n");
		exit(0);
	}	
}

int main()
{
	int **process;
	int total_memory,size_of_process,unused_memory;
	int i;
	
	printf("\nEnter size of memory:");
	scanf("%d",&total_memory);
	check_error(total_memory);
	
	printf("\nEnter number of processes:");
	scanf("%d",&size_of_process);
	check_error(size_of_process);
	
	process=(int **)calloc(size_of_process,sizeof(int*));
	for(i=0;i<size_of_process;i++)
		process[i]=(int *)calloc(4,sizeof(int));
	
	
	printf("\nEnter the memory needed by each process\n");
	for(i=0;i<size_of_process;i++)
	{
		printf("Process %d:",i+1);
		//Checking for non-numerical value
		if(!scanf("%d",&process[i][memory]))
		{
			printf("\nPlease enter integer value\n");
			exit(0);
		}
		check_error(process[i][memory]);		
		process[i][allocated]=-1;
		process[i][start]=-1;
		process[i][end]=-1;
	}
	
	//Calling fcfs function and Displaying the process allocation
	unused_memory=fcfs(total_memory,process,size_of_process);
		printf("\nProcess\t\tMemory Allocated\tStart Address\tEnd Address\n");
		for(i=0;i<size_of_process;i++)
		{
			printf("\nProcess %d(size %d)\t",i+1,process[i][memory]);
			//Checking if process was allocated memory	
			if(process[i][allocated]!=-1)
				printf("Allocated\t");
			else
				printf("Not allocated\t");
			printf("%d\t\t%d\n",process[i][start],process[i][end]);
		}
		printf("Unused memory=%d\n",unused_memory);
		
	return 0;
}
