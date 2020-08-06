//1830
//Best Fit algorithm for Memory Management(OS)

#include<stdio.h>
#include<stdlib.h>

//Best Fit logic
int best_fit(int memory[],int process[],int allocated[],int no_of_memory_blocks,int no_of_processes)
{
	int process_memory,memory_block;
	//Traversing each memory block for each process
	for(process_memory=0;process_memory<no_of_processes;process_memory++)
	{
		for(memory_block=0;memory_block<no_of_memory_blocks;memory_block++)
		{	
			//Checking if a process fits into any memory block
			if(process[process_memory]<memory[memory_block])
			{
				//If the process did not fit into any memory block yet
				if(allocated[process_memory]==-1)
					allocated[process_memory]=memory_block;
				//If it alreadt fit into a memory block then checking if the current memory block is smaller in size i.e best fit
				else if(memory[memory_block]<memory[allocated[process_memory]])
					allocated[process_memory]=memory_block;
			}
		}
		//Reducing the size of the memory block after allocating a process to it
		memory[allocated[process_memory]]-=process[process_memory];
	}
	
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
	int *memory,*process,*allocated;
	int size_of_memory,size_of_process;
	int i;
	
	printf("\nEnter number of memory block:");
	scanf("%d",&size_of_memory);
	check_error(size_of_memory);
	
	printf("\nEnter number of processes:");
	scanf("%d",&size_of_process);
	check_error(size_of_process);
	
	memory=(int *)calloc(size_of_memory,sizeof(int));	
	process=(int *)calloc(size_of_process,sizeof(int));
	allocated=(int *)calloc(size_of_process,sizeof(int));
	
	printf("\nEnter the memory blocks\n");
	for(i=0;i<size_of_memory;i++)
	{
		printf("Memory block %d:",i+1);
		//Checking if input is non-numerical
		if(!scanf("%d",&memory[i]))
		{
			printf("\nPlease enter integer value\n");
			exit(0);
		}
		check_error(memory[i]);
	}
	
	printf("\nEnter the memory needed by each process\n");
	for(i=0;i<size_of_process;i++)
	{
		printf("Process %d:",i+1);
		if(!scanf("%d",&process[i]))
		{
			printf("\nPlease enter integer value\n");
			exit(0);
		}
		check_error(process[i]);
		allocated[i]=-1;
	}
	
	//Calling best_fit function and Displaying the process allocation
	if(best_fit(memory,process,allocated,size_of_memory,size_of_process))
	{
		printf("\nProcess\tMemory Block\n");
		for(i=0;i<size_of_process;i++)
		{
			printf("\nProcess %d(size %d)\t",i+1,process[i]);
			//Checking if process fit into any memory block		
			if(allocated[i]!=-1)
				printf("Memory block %d\n",allocated[i]+1);
			else
				printf("Not allocated\n");
		}
	}
	else
		printf("Sorry!! ERROR allocating memory");
		
	return 0;
}
