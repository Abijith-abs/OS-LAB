#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct{
	int size;
	int allocated;
}Block;

typedef struct{
	int size;
	int allocated;
}Process;

void main(){
	
	
	int n;
	printf("Enter the number of the blocks :");
	scanf("%d",&n);
	
	Block * blocks = (Block *) malloc(sizeof(Block) * n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the size of block %d :",i);
		scanf("%d" ,&blocks[i].size);
		
	}
	Process p[MAXSIZE];
	int deallocated = -1;
	printf("Enter 0 to exit \n 1 for allocation \n 2 for deallocation \n");
	
	int choice;
	int i = 0;
	while(1)
	{
	 	printf("Enter choice :");
	 	scanf("%d",&choice);
	 	
	 	if(choice == 1)
	 	{
	 		printf("Enter the size of process %d: " , i);
	 		scanf("%d",&p[i].size);
	 		p[i].allocated = -1;
	 		
	 		if(deallocated != -1)
	 		{
	 		   if(blocks[deallocated].size >= p[i].size )
	 		   {
	 		   	p[i].allocated = deallocated;
	 		   	blocks[deallocated].size -= p[i].size;
	 		   	blocks[deallocated].allocated = i;
				printf("Process Allocated to %d \n",deallocated);
	 		   	continue;
			   }
			   
	 		}
	 		for(int j = 0 ; j < n ; j++)
	 		{
	 		    if(blocks[j].size >= p[i].size){
	 		    p[i].allocated = j;
	 		    blocks[j].size -= p[i].size;
	 		    blocks[j].allocated = i;
	 		    printf("Process %d Allocated to %d \n",i, j);
	 		    break;
	 		    }
	 		}
	 		if(p[i].allocated == -1)
	 		{
	 			printf("Process %d Couldnt be allocated \n",i);
	 			continue;
	 		}
	 		
	 		i++;
	 		continue;
	 		
	 		
		}
		
		else if(choice == 0)
		{
			break;
		}
		
		else if(choice ==3)
		{
			{
				for(int t =0;t<n;t++)
				{
					printf("Block %d Allocated to %d ,,, remaining space = %d \n" , t , blocks[t].allocated , blocks[t].size);
				}
			}
		}
		else{
		
		
			int k;
			printf("Enter the process to be deallocated :");
			scanf("%d" , &k);
			if(p[k].allocated == -1)
			{
				printf("Already deallocated ! \n");
				continue;
			}
			
			

				blocks[p[k].allocated].size += p[k].size;
				deallocated = p[k].allocated;
				p[k].allocated = -1;
				printf("Process %d Deallocated \n",k);
			
		
			}				
	}	
	
}

